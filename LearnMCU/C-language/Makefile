# Makefile — projeto bare-metal

SRC = c-asm.c m.s
ASM = c-asm.c
LD_SCRIPT = m.ld
ELF = m.elf
BIN = m.bin

# Toolchain
CC = riscv64-unknown-elf-gcc
OBJCOPY = riscv64-unknown-elf-objcopy
GDB = gdb-multiarch
QEMU = qemu-system-riscv32

# Flags 
CFLAGS = -O0 -ggdb -nostdlib -march=rv32i -mabi=ilp32
CFLAGSNGDB = -O0 -nostdlib -march=rv32i -mabi=ilp32
LDFLAGS = -Wl,-T$(LD_SCRIPT)

all: $(ELF) $(BIN)

$(ELF): $(SRC) $(LD_SCRIPT)
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC) -o $(ELF)

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $(ELF) $(BIN)

asm: $(ASM)
	$(CC) $(CFLAGSNGDB) $(ASM) -S
# riscv64-unknown-elf-gcc -O0 -nostdlib -march=rv32i -mabi=ilp32 -Wl, -Tm.ld c-asm.c -S

run: $(ELF)
	$(QEMU) -M virt -nographic -bios none -kernel $(ELF)

debug: $(ELF)
	$(QEMU) -M virt -nographic -bios none -kernel $(ELF) -gdb tcp::1236 -S

gdb: $(ELF)
	$(GDB) $(ELF) -ex "target remote localhost:1236" -ex "break _start" -ex "continue"

clean:
	rm -f *.elf *.bin
