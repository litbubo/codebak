; multi-segment executable file template.

data segment
    ; add your data here!
    n dw ?
    sum dw ?
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax

    ; add your code here
    mov ax, 0
    mov bx, 0
    mov cx, 0
loop1:
    inc bx
    add ax, bx
    inc cx
    cmp ax, 2000
    jbe loop1
    mov sum, ax
    mov n, cx
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
