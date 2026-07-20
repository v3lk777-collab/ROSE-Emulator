# ROSE CPU Emulator

[![C++](https://img.shields.io/badge/C%2B%2B-23-blue.svg)](https://en.cppreference.com/w/cpp/23)
[![CMake](https://img.shields.io/badge/CMake-3.25%2B-informational.svg)](https://cmake.org/)
[![License](https://img.shields.io/badge/license-GPLv3-green.svg)](LICENSE)

A minimal, byte-accurate 8-bit CPU emulator written in modern **C++23**. ROSE simulates a custom hardware architecture featuring two primary registers (`A` and `B`), a basic Arithmetic Logic Unit (ALU), memory mapping, and conditional/unconditional jump control.

---

## Features

- **Byte-Perfect Accuracy** — the Program Counter (`PC`) advances dynamically based on each instruction's actual size.
- **Custom Instruction Set (ISA)** — hand-crafted opcodes for data movement, arithmetic, and control flow.
- **Zero-Flag Logic** — built-in conditional branching (`JZ`) for real, working loops.
- **Modern CMake Build System** — simple to configure, build, and extend.

---

## Instruction Set Architecture (ISA)

| Opcode | Mnemonic | Arguments  | Size (Bytes) | Description |
|:------:|:---------|:-----------|:-------------:|:-------------|
| `0x00` | `HALT`   | —          | 1 | Terminates CPU execution immediately. |
| `0x01` | `LDA`    | `[value]`  | 2 | Loads an immediate 8-bit value into register `A`. |
| `0x02` | `LDB`    | `[value]`  | 2 | Loads an immediate 8-bit value into register `B`. |
| `0x03` | `ADD`    | —          | 1 | `A = A + B`. Updates the Zero Flag. |
| `0x04` | `SUB`    | —          | 1 | `A = A - B`. Updates the Zero Flag. |
| `0x05` | `OUT`    | —          | 1 | Prints the current CPU state (`A`, `B`, `PC`, `ZF`) to the console. |
| `0x06` | `JMP`    | `[address]`| 2 | Unconditional jump — sets `PC` to the target address. |
| `0x07` | `JZ`     | `[address]`| 2 | Conditional jump — sets `PC` to the target address if the Zero Flag is `1`. |

---

## Project Structure

```text
ROSE/
├── CMakeLists.txt
├── include/
│   └── cpu.hpp
├── src/
│   ├── cpu.cpp
│   └── main.cpp
└── README.md
```

---

## Getting Started

### Prerequisites

- A C++23-compliant compiler (GCC 13+, Clang 16+, or MSVC 19.35+)
- CMake 3.25 or later

### Build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

On Windows with MinGW:

```bash
cmake .. -G "MinGW Makefiles"
cmake --build .
```

### Run

```bash
./rose
```

---

## License

Released under the **GNU General Public License v3.0**. See [LICENSE](LICENSE) for details.