#include "cpu.hpp"
#include <iostream>

CPU::CPU() {
    reset();
}

void CPU::reset() {
    A = 0;
    B = 0;
    PC = 0;

    zeroFlag = false;
    isCPURunning = true;

    for (size_t i = 0; i < memory.size(); i++) {
        memory[i] = 0;
    }
}

void CPU::loadProgram(const std::vector<uint8_t>& program) {
    for (size_t i = 0; i < program.size() && i < memory.size(); i++) {
        memory[i] = program[i];
    }
}

void CPU::printCPUState() {
    std::cout << "--> A:  " << static_cast<int>(A) << "\n";
    std::cout << "--> B:  " << static_cast<int>(B) << "\n";
    std::cout << "--> PC: " << PC << "\n";
    std::cout << "--> ZF: " << (zeroFlag ? "1" : "0") << "\n";
    std::cout << "----------------------------------------\n";
}

void CPU::run() {
    while (isCPURunning) {
        uint8_t opcode = memory[PC];

        switch (static_cast<Opcode>(opcode)) {
        case Opcode::HALT:
            isCPURunning = false;
            PC++;
            return;

        case Opcode::LDA:
            A = memory[PC + 1];
            PC += 2;
            break;

        case Opcode::LDB:
            B = memory[PC + 1];
            PC += 2;
            break;

        case Opcode::ADD:
            A = A + B;
            zeroFlag = (A == 0);
            PC++;
            break;
        
        case Opcode::SUB:
            A = A - B;
            zeroFlag = (A == 0);
            PC++;
            break;
        
        case Opcode::OUT:
            printCPUState();
            PC++;
            break;

        case Opcode::JMP:
            PC = memory[PC + 1];
            break;

        case Opcode::JZ:
            if (zeroFlag) {
                PC = memory[PC + 1];
            } else {
                PC += 2;
            }

            break;
        
        default:
            std::cerr << "Unknown opcode: " << (int)opcode << " at PC: " << PC << std::endl;

            isCPURunning = false;
            return;
        }
    }
}