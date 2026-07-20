#include "cpu.hpp"

int main() {
    std::vector<uint8_t> program = {
        0x01, 3,    // Address 0 & 1: LDA 3  -> Load 3 into Register A (Counter)
        0x02, 1,    // Address 2 & 3: LDB 1  -> Load 1 into Register B (Value to subtract)
        
        // --- Loop Start ---
        0x05,       // Address 4:     OUT    -> Print current CPU state (A, B, PC, ZF)
        0x04,       // Address 5:     SUB    -> Subtract B from A (A = A - B)
        
        0x07, 10,   // Address 6 & 7: JZ 10  -> Jump if Zero to Address 10 (HALT) if A == 0
        0x06, 4,    // Address 8 & 9: JMP 4  -> Unconditional Jump back to Address 4 if A != 0
        
        0x00        // Address 10:    HALT   -> Stop CPU execution
    };

    CPU cpu;

    cpu.loadProgram(program);
    cpu.run();

    return 0;
}