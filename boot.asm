; bootloader that prints out "Hello World!". enabled video mode. color is blue.

ORG 0
BITS 16


jmp 0x7c0:start



start:
    cli ; Clear Interrupts
    mov ax, 0x7c0
    mov ds, ax
    mov es, ax
    mov ax, 0x00
    mov ss, ax
    mov sp, 0x7c00
    sti ; Enables Interrupts

    mov ah, 2 ; Read sector command
    mov al, 1 ; One sector to read
    mov ch, 0 ; Cylinder low eigth bits
    mov cl, 2 ; Read sector two
    mov dh, 0 ; Head number
    mov bx, buffer
    int 0x13
    
    jc error
    
    mov si, buffer
    call print

    jmp $

error:
    mov si, error_message
    call print
    jmp $


print:
    mov bx, 0
    mov dl, 0
    mov dh, 10
.loop:
    mov ah, 02h
    int 10h
    inc dl
    lodsb
    cmp al, 0
    je .done
    call print_char 
    jmp .loop
.done:   
    ret

print_char:
    mov ah, 09h
    mov bl, 3
    mov cx, 1
    int 10h
    ret

error_message: db 'Failed to load Sector' , 0



times 510 - ($ - $$) db 0 
dw 0xAA55


buffer:
