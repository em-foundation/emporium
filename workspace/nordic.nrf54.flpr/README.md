# nRF54 FLPR toolchain setup

The FLPR distro uses the SEGGER RISC-V compiler from **SEGGER Embedded Studio 8.26** (compiler 20.1.1). Install the host edition from [SEGGER](https://www.segger.com/downloads/embedded-studio) and follow [SEGGER’s installation instructions](https://www.segger.com/products/development-tools/embedded-studio/technology/installation/) and [license activation instructions](https://www.segger.com/products/development-tools/embedded-studio/licensing/conditions-activation/).

Find the installed toolchain directory. It must contain `bin/segger-cc`, `gcc/riscv32-none-elf/bin/ld` and the other GNU binutils, `include/` and `lib/libc_rv32emc_small.a`. The Windows executables end in `.exe`. Point to this directory inside the installation.

```sh
# Windows (Git Bash). Use forward slashes in the path.
export SEGGER_RISCV_HOME='C:/path to/SEGGER/toolchain'

# Linux or macOS. Use the absolute path inside the vendor installation.
export SEGGER_RISCV_HOME='/path to/SEGGER/toolchain'
```

Set the variable in the shell that runs your build. For a build launched from VS Code, set it before starting VS Code so the build inherits it. When the variable is unset, the build looks in Emporium’s `tools/segger-riscv`.

Provision SRecord and J-Link through the usual Emporium setup. Select the FLPR board and build as usual. To load the merged image onto the selected board, run `./load.sh` from `workspace/.emscript`.
