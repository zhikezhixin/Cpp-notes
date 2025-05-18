#include "pch.h"

//using namespace winrt;
//using namespace Windows::Foundation;

// 主函数 - 在Windows控制台应用程序的入口点
int sc_main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    return sc_main(argc, argv);
}

// SystemC主函数实现
int sc_main(int argc, char* argv[]) {
    // 初始化SystemC
    sc_clock clock("clock", 10, SC_NS);
    sc_signal<bool> reset;

    // 实例化CPU
    PipelineCPU cpu("cpu");
    cpu.clock(clock);
    cpu.reset(reset);

    // 打开波形跟踪文件
    sc_trace_file* tf = sc_create_vcd_trace_file("cpu_waveform");
    sc_trace(tf, clock, "clock");
    sc_trace(tf, reset, "reset");

    // 运行仿真
    reset = true;  // 复位信号
    sc_start(10, SC_NS);

    reset = false; // 释放复位

    std::cout << "开始CPU流水线仿真...\n\n";

    // 仿真10个周期
    for (int i = 0; i < 10; i++) {
        std::cout << "\n====== 周期 " << i << " ======\n";
        sc_start(10, SC_NS);
        cpu.print_state();
    }

    // 输出最终寄存器状态
    std::cout << "\n\n最终寄存器状态:\n";
    cpu.print_regs();

    // 关闭波形文件
    sc_close_vcd_trace_file(tf);

    // 等待用户按键，防止控制台直接关闭
    std::cout << "\n按任意键继续...\n";
    std::cin.get();

    return 0;
}