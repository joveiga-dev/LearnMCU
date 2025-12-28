# m.s
# Código de entrada bare-metal RISC-V

    .global _start
    .section .text._start

_start:
    # Configura a stack (dentro da RAM definida)
    li sp, 0x80002000

    # Chama função escrita em C
    jal jose

# Loop infinito para não cair no vazio
1:
    j 1b

