# SimpleOS

SimpleOS is a basic operating system developed as a learning project to understand the fundamentals of OS development.

## Features

- Basic kernel implementation
- Simple command-line interface
- Memory management
- Process scheduling

## Getting Started

### Prerequisites

- [GCC Cross-Compiler](https://wiki.osdev.org/GCC_Cross-Compiler)
- [QEMU](https://www.qemu.org/) for emulation

### Building SimpleOS

1. Clone the repository:

   ```bash
   git clone https://github.com/ashirs2/SimpleOS.git
   cd SimpleOS
   make all
   qemu-system-x86_64 -hda ./bin/os.bin
