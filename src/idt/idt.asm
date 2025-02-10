section .asm 

extern int21_handler
extern no_interrupt_handler
global no_interrupt
global int21h
global idt_load

idt_load:
    push ebp ;push base pointer
    mov ebp, esp 
    
    
    ;ebp + 8 into ebx 
    ; ebp + 4 return to pervious function caller
    ; ebp + 8 1st argument passed to the function
    mov ebx, [ebp+8] 
    lidt [ebx]

    pop ebp ;pop base pointer

int21h:
    cli
    pushad
    call int21_handler   
    popad 
    sti
    iret

no_interrupt:
    cli
    pushad
    call no_interrupt_handler
    popad
    sti
    iret