.section .text 
.align 2 
.globl setupGPIO 
 
#include "memoryMap.inc" 
#include "GPIO.inc" 
 
setupGPIO: 
    addi sp, sp, -16           
# allocate a stack frame, moves the stack up by 16 bits 
    sw ra, 12(sp)   
    li t0, GPIO_CTRL_ADDR     # load GPIO base address 

    # ENABLE OUTPUT
    li t1, OUTPUT
    sw t1, GPIO_OUTPUT_EN(t0)
    sw x0, GPIO_OUTPUT_VAL(t0)
    sw t1, GPIO_OUTPUT_XOR(t0)

    # ENABLE INPUT
    li t1, INPUT                # load address of pin 2 into t1 
    sw t1, GPIO_INPUT_EN(t0)    # set pins for input enable 
    sw t1, GPIO_INPUT_PULUP(t0) # enable pull up  

    lw ra, 12(sp)               # return the return address 
    addi sp, sp, 16             # deallocate the stack  
    ret