#pragma once
#include <vector>
#include <cstdint>

enum class Opcode : uint8_t {
    HALT = 0x00,
    LDA  = 0x01,
    LDB  = 0x02,
    ADD  = 0x03,
    SUB  = 0x04,
    OUT  = 0x05,
    JMP  = 0x06,
    JZ   = 0x07
};

class CPU {
private:
    uint8_t A;
    uint8_t B;
    uint16_t PC;
    std::vector<uint8_t> memory = std::vector<uint8_t>(256, 0);

    bool zeroFlag;
    bool isCPURunning;

private:
    void reset();
    void printCPUState();

public:
    CPU();

    void run();
    void loadProgram(const std::vector<uint8_t>& program);
};