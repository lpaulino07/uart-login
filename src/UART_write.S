.section .text
.align 2
.globl UART_write
#include "memoryMap.inc"
#include "UART.inc"
UART_write:
 addi sp, sp, -16
 # allocate a stack frame, moves the stack up by 16 bits
 sw ra, 12(sp)
 
 loop:
    li t0, UART_CTRL_ADDR       # load base address for UART

    lw t1, UART_txdata(t0)      # load the txdata register
   
    li t2, 0x80000000           # mask to check 31st bit
    and t3, t2, t1              # AND to check 31st bit
    bnez t3, loop               # loop back if the bit is set

    sb a0, UART_txdata(t0)      # save byte to txdata
    lw ra, 12(sp)               # load the return adress
    addi sp, sp, 16             # dealocate the stack
 ret
