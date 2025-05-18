#pragma once
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>

#include <systemc.h>
#include <iostream>
#include <iomanip>

// 指令格式定义
struct Instruction {
    unsigned int opcode;    // 操作码
    unsigned int rs;        // 源寄存器1
    unsigned int rt;        // 源寄存器2
    unsigned int rd;        // 目标寄存器
    unsigned int imm;       // 立即数
    unsigned int address;   // 内存地址

    Instruction() : opcode(0), rs(0), rt(0), rd(0), imm(0), address(0) {}
};

// 操作码定义
enum OpCode {
    OP_NOP = 0,  // 空操作
    OP_ADD = 1,  // 加法
    OP_SUB = 2,  // 减法
    OP_AND = 3,  // 与
    OP_OR = 4,  // 或
    OP_LW = 5,  // 读内存
    OP_SW = 6,  // 写内存
    OP_BEQ = 7,  // 分支
    OP_J = 8   // 跳转
};

// 流水线寄存器
struct IF_ID_Reg {
    unsigned int pc;
    Instruction instr;

    IF_ID_Reg() : pc(0) {}
};

struct ID_EX_Reg {
    unsigned int pc;
    Instruction instr;
    int reg_data1;   // 寄存器1的值
    int reg_data2;   // 寄存器2的值

    ID_EX_Reg() : pc(0), reg_data1(0), reg_data2(0) {}
};

struct EX_MEM_Reg {
    unsigned int pc;
    Instruction instr;
    int alu_result;   // ALU运算结果
    int reg_data2;    // 寄存器2的值(用于存储指令)
    bool branch_taken; // 分支是否执行

    EX_MEM_Reg() : pc(0), alu_result(0), reg_data2(0), branch_taken(false) {}
};

struct MEM_WB_Reg {
    unsigned int pc;
    Instruction instr;
    int alu_result;    // ALU运算结果
    int mem_result;    // 内存读取结果

    MEM_WB_Reg() : pc(0), alu_result(0), mem_result(0) {}
};

// CPU模块声明
SC_MODULE(PipelineCPU) {
    // 输入输出端口
    sc_in_clk clock;
    sc_in<bool> reset;

    // 寄存器和内存
    int registers[32];
    int memory[1024];

    // 流水线寄存器
    IF_ID_Reg if_id;
    ID_EX_Reg id_ex;
    EX_MEM_Reg ex_mem;
    MEM_WB_Reg mem_wb;

    // 程序计数器
    unsigned int pc;

    // 指令内存 (用数组模拟)
    Instruction instructions[100];
    int instr_count;

    // 冒险控制信号
    bool stall;
    bool flush;

    // 流水线阶段方法声明
    void fetch();          // 取指阶段
    void decode();         // 译码阶段
    void execute();        // 执行阶段
    void memory_access();  // 内存访问阶段
    void writeback();      // 写回阶段

    // 辅助方法
    void init_instructions();
    void print_state();
    void handle_hazards();
    void print_regs();

    // 构造函数
    SC_CTOR(PipelineCPU);
};
