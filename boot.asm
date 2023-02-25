ORG 0x7c00
BITS 16

start:
    mov si, message
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

message: db 'Hello World', 0
times 510 - ($ - $$) db 0 
dw 0xAA55