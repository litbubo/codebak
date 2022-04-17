
data segment
    ; add your data here!
    op1 db 041h, 042h, 043h, 044h, 045h, 046h, 047h, 048h, 049h, 050h
    op2 db 01h, 02h, 03h, 04h, 05h, 06h, 07h, 08h, 09h, 0ah
    op3 db 11 dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax

    ; add your code here
    mov cx, 10        ;设置循环次数10次
    lea ax, op1       ;取op1地址送入ax
    lea bx, op2       ;取op2地址送入bx
    mov si, ax        ;送ax入变址寄存器si
    mov di, bx        ;送bx入变址寄存器di
    lea ax, op3
    mov bp, ax
loop1:
    mov al, [si]      ;取一个值送入累加器al
    add al, [di]      ;取op2一个值与al中值相加并送入al
    mov [bp], al      ;将al值送入op3中
    
    mov dl, [bp]      ;屏幕打印op3
    mov ah, 2
    int 21h
    mov dl, 0Ah       ;换行
    mov ah, 2
    int 21h
    mov dl, 0dh       ;回车
    mov ah, 2
    int 21h
    inc si            ;自增运算
    inc di
    inc bp
    dec cx            ;自减运算
    jnz loop1
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
