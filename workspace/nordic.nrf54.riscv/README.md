# nRF54 RISC-V toolchain setup

The RISC-V core runs from SRAM. The default setup selects `sram-llvm`.

| Setup | Local toolchain directory |
| --- | --- |
| `sram-llvm` | `tools/llvm` with Clang, LLD, LLVM utilities, and an `ilp32e` compiler-rt archive |
| `sram-gcc` | `tools/gcc-riscv` with GCC, GNU Binutils, and an `ilp32e` libgcc |
| `sram-segger` | `tools/segger-riscv` or the directory set by `SEGGER_RISCV_HOME` |

For `sram-segger`, install the host edition of **SEGGER Embedded Studio 8.26** (compiler 20.1.1) and follow SEGGER’s installation and license activation instructions. [Downloads](https://www.segger.com/downloads/embedded-studio) · [Installation](https://www.segger.com/products/development-tools/embedded-studio/technology/installation/) · [License activation](https://www.segger.com/products/development-tools/embedded-studio/licensing/conditions-activation/)

Find the installed toolchain directory. It must contain `bin/segger-cc`, `gcc/riscv32-none-elf/bin/ld` and the other GNU binutils, `include/` and `lib/libc_rv32emc_small.a`. The Windows executables end in `.exe`. Point to this directory inside the installation.

```sh
# Windows (Git Bash). Use forward slashes in the path.
export SEGGER_RISCV_HOME='C:/path to/SEGGER/toolchain'

# Linux or macOS. Use the absolute path inside the vendor installation.
export SEGGER_RISCV_HOME='/path to/SEGGER/toolchain'
```

Set the variable in the shell that runs your build. For a build launched from VS Code, set it before starting VS Code so the build inherits it. When the variable is unset, the build looks in Emporium’s `tools/segger-riscv`.

Provision SRecord and J-Link through the usual Emporium setup. Select the RISC-V board and build as usual. The build merges the SRAM payload with the Cortex-M33 launcher. To program the merged image, run `./load.sh` from `workspace/.emscript`.
