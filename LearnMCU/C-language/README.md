

### Toolchain
Install the toolchain, QEMU and GDB

```bash
sudo apt update -y
sudo apt install -y gcc-riscv64-unknown-elf qemu-system-misc gdb-multiarch
```

### How to
```bash
make asm
make 
make run
# open new terminal
make debug
# open new terminal
make gdb

```
