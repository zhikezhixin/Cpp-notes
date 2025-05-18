#include "pch.h"

// 实现CPU构造函数
PipelineCPU::SC_CTOR(PipelineCPU) {
    // 注册SystemC线程
    SC_METHOD(writeback);
    sensitive << clock.pos();

    SC_METHOD(memory_access);
    sensitive << clock.pos();

    SC_METHOD(execute);
    sensitive << clock.pos();

    SC_METHOD(decode);
    sensitive << clock.pos();

    SC_METHOD(fetch);
    sensitive << clock.pos() << reset;

    SC_METHOD(handle_hazards);
    sensitive << clock.pos();

    // 初始化
    pc = 0;
    stall = false;
    flush = false;
    instr_count = 0;

    // 初始化寄存器和内存
    for (int i = 0; i < 32; i++) {
        registers[i] = 0;
    }

    for (int i = 0; i < 1024; i++) {
        memory[i] = 0;
    }

    // 初始化示例指令
    init_instructions();
}

// 打印寄存器状态
void PipelineCPU::print_regs() {
    std::cout << "寄存器状态:\n";
    for (int i = 0; i < 32; i++) {
        if (i % 8 == 0 && i > 0) std::cout << "\n";
        std::cout << "R" << std::setw(2) << i << ": " << std::setw(4) << registers[i] << " ";
    }
    std::cout << "\n\n";
}

// 初始化示例指令
void PipelineCPU::init_instructions() {
    // 示例程序: 计算 r3 = (r1 + r2) - r4

    // 设置初始值
    registers[1] = 10;  // r1 = 10
    registers[2] = 20;  // r2 = 20
    registers[4] = 5;   // r4 = 5

    // 指令1: r3 = r1 + r2
    instructions[0].opcode = OP_ADD;
    instructions[0].rs = 1;
    instructions[0].rt = 2;
    instructions[0].rd = 3;

    // 指令2: r5 = r3 - r4
    instructions[1].opcode = OP_SUB;
    instructions[1].rs = 3;
    instructions[1].rt = 4;
    instructions[1].rd = 5;

    // 指令3: r6 = r5 AND r1
    instructions[2].opcode = OP_AND;
    instructions[2].rs = 5;
    instructions[2].rt = 1;
    instructions[2].rd = 6;

    // 指令4: 存储r6到内存地址100
    instructions[3].opcode = OP_SW;
    instructions[3].rs = 6;
    instructions[3].imm = 100;

    // 指令5: 从内存100加载到r7
    instructions[4].opcode = OP_LW;
    instructions[4].rd = 7;
    instructions[4].imm = 100;

    // 设置指令数量
    instr_count = 5;
}

// 取指阶段
void PipelineCPU::fetch() {
    if (reset.read()) {
        pc = 0;
        if_id.pc = 0;
        if_id.instr = Instruction();
        return;
    }

    if (stall) {
        // 如果流水线停顿，则不处理
        return;
    }

    if (flush) {
        // 如果需要清除流水线，则插入NOP
        if_id.instr = Instruction();
        if_id.pc = pc;
        flush = false;
        return;
    }

    if (pc < instr_count) {
        // 取指令
        if_id.instr = instructions[pc];
        if_id.pc = pc;
        pc++;

        std::cout << "Fetch: 指令 " << pc - 1 << ", PC = " << pc - 1 << std::endl;
    }
    else {
        // 没有更多指令
        if_id.instr = Instruction(); // NOP
    }
}

// 译码阶段
void PipelineCPU::decode() {
    if (reset.read() || stall) {
        id_ex.instr = Instruction();
        return;
    }

    // 将IF/ID寄存器的内容传递到ID/EX寄存器
    id_ex.pc = if_id.pc;
    id_ex.instr = if_id.instr;

    // 读取寄存器
    if (if_id.instr.opcode != OP_NOP) {
        id_ex.reg_data1 = registers[if_id.instr.rs];
        id_ex.reg_data2 = registers[if_id.instr.rt];

        std::cout << "Decode: 指令类型 " << if_id.instr.opcode
            << ", rs = " << if_id.instr.rs
            << ", rt = " << if_id.instr.rt
            << ", rd = " << if_id.instr.rd << std::endl;
    }
}

// 执行阶段
void PipelineCPU::execute() {
    if (reset.read()) {
        ex_mem.instr = Instruction();
        ex_mem.branch_taken = false;
        return;
    }

    // 将ID/EX寄存器的内容传递到EX/MEM寄存器
    ex_mem.pc = id_ex.pc;
    ex_mem.instr = id_ex.instr;
    ex_mem.reg_data2 = id_ex.reg_data2;
    ex_mem.branch_taken = false;

    // 执行ALU操作
    switch (id_ex.instr.opcode) {
    case OP_ADD:
        ex_mem.alu_result = id_ex.reg_data1 + id_ex.reg_data2;
        std::cout << "Execute: ADD, 结果 = " << ex_mem.alu_result << std::endl;
        break;

    case OP_SUB:
        ex_mem.alu_result = id_ex.reg_data1 - id_ex.reg_data2;
        std::cout << "Execute: SUB, 结果 = " << ex_mem.alu_result << std::endl;
        break;

    case OP_AND:
        ex_mem.alu_result = id_ex.reg_data1 & id_ex.reg_data2;
        std::cout << "Execute: AND, 结果 = " << ex_mem.alu_result << std::endl;
        break;

    case OP_OR:
        ex_mem.alu_result = id_ex.reg_data1 | id_ex.reg_data2;
        std::cout << "Execute: OR, 结果 = " << ex_mem.alu_result << std::endl;
        break;

    case OP_LW:
    case OP_SW:
        ex_mem.alu_result = id_ex.reg_data1 + id_ex.instr.imm;  // 计算内存地址
        std::cout << "Execute: 计算内存地址 = " << ex_mem.alu_result << std::endl;
        break;

    case OP_BEQ:
        if (id_ex.reg_data1 == id_ex.reg_data2) {
            ex_mem.branch_taken = true;
            pc = id_ex.pc + 1 + id_ex.instr.imm;  // 计算分支目标地址
            flush = true;  // 需要清除流水线
            std::cout << "Execute: 分支成功, 新PC = " << pc << std::endl;
        }
        else {
            std::cout << "Execute: 分支未成功" << std::endl;
        }
        break;

    case OP_J:
        pc = id_ex.instr.address;  // 设置跳转地址
        ex_mem.branch_taken = true;
        flush = true;  // 需要清除流水线
        std::cout << "Execute: 跳转到地址 " << pc << std::endl;
        break;

    case OP_NOP:
    default:
        break;
    }
}

// 内存访问阶段
void PipelineCPU::memory_access() {
    if (reset.read()) {
        mem_wb.instr = Instruction();
        return;
    }

    // 将EX/MEM寄存器的内容传递到MEM/WB寄存器
    mem_wb.pc = ex_mem.pc;
    mem_wb.instr = ex_mem.instr;
    mem_wb.alu_result = ex_mem.alu_result;

    // 访问内存
    switch (ex_mem.instr.opcode) {
    case OP_LW:
        // 从内存加载
        mem_wb.mem_result = memory[ex_mem.alu_result];
        std::cout << "Memory: 从地址 " << ex_mem.alu_result
            << " 加载值 " << mem_wb.mem_result << std::endl;
        break;

    case OP_SW:
        // 写入内存
        memory[ex_mem.alu_result] = ex_mem.reg_data2;
        std::cout << "Memory: 存储值 " << ex_mem.reg_data2
            << " 到地址 " << ex_mem.alu_result << std::endl;
        break;

    default:
        // 对于其他指令，不需要访问内存
        break;
    }
}

// 写回阶段
void PipelineCPU::writeback() {
    if (reset.read()) {
        return;
    }

    // 写回寄存器
    switch (mem_wb.instr.opcode) {
    case OP_ADD:
    case OP_SUB:
    case OP_AND:
    case OP_OR:
        // 写入目标寄存器
        registers[mem_wb.instr.rd] = mem_wb.alu_result;
        std::cout << "Writeback: 写入 " << mem_wb.alu_result
            << " 到寄存器 R" << mem_wb.instr.rd << std::endl;
        break;

    case OP_LW:
        // 从内存加载到寄存器
        registers[mem_wb.instr.rd] = mem_wb.mem_result;
        std::cout << "Writeback: 写入 " << mem_wb.mem_result
            << " 到寄存器 R" << mem_wb.instr.rd << std::endl;
        break;

    default:
        // 对于其他指令，不需要写回
        break;
    }

    // 打印寄存器状态
    if (mem_wb.instr.opcode != OP_NOP) {
        print_regs();
        std::cout << "-------------------\n";
    }
}

// 处理流水线冒险
void PipelineCPU::handle_hazards() {
    // 简单的数据冒险检测
    // 在这个简单的实现中，我们只检测数据相关性，不进行前递

    // 检查ID阶段的指令是否依赖于EX阶段的运算结果
    if (id_ex.instr.opcode != OP_NOP &&
        ex_mem.instr.opcode != OP_NOP &&
        ex_mem.instr.rd != 0) {

        // 检查数据相关性
        if ((id_ex.instr.rs == ex_mem.instr.rd) ||
            (id_ex.instr.rt == ex_mem.instr.rd)) {

            // 插入停顿
            stall = true;
            std::cout << "检测到数据冒险，插入停顿\n";
            return;
        }
    }

    // 检查ID阶段的指令是否依赖于MEM阶段的运算结果
    if (id_ex.instr.opcode != OP_NOP &&
        mem_wb.instr.opcode != OP_NOP &&
        mem_wb.instr.rd != 0) {

        // 检查数据相关性
        if ((id_ex.instr.rs == mem_wb.instr.rd) ||
            (id_ex.instr.rt == mem_wb.instr.rd)) {

            // 插入停顿
            stall = true;
            std::cout << "检测到数据冒险，插入停顿\n";
            return;
        }
    }

    // 不需要停顿
    stall = false;
}

// 打印CPU状态
void PipelineCPU::print_state() {
    std::cout << "\n当前流水线状态:" << std::endl;
    std::cout << "PC = " << pc << std::endl;

    std::cout << "IF/ID:  PC = " << if_id.pc << ", OP = " << if_id.instr.opcode << std::endl;
    std::cout << "ID/EX:  PC = " << id_ex.pc << ", OP = " << id_ex.instr.opcode
        << ", RS = " << id_ex.reg_data1 << ", RT = " << id_ex.reg_data2 << std::endl;
    std::cout << "EX/MEM: PC = " << ex_mem.pc << ", OP = " << ex_mem.instr.opcode
        << ", ALU = " << ex_mem.alu_result << std::endl;
    std::cout << "MEM/WB: PC = " << mem_wb.pc << ", OP = " << mem_wb.instr.opcode
        << ", ALU = " << mem_wb.alu_result << ", MEM = " << mem_wb.mem_result << std::endl;
}