
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
    mov cx, 10        ;����ѭ������10��
    lea ax, op1       ;ȡop1��ַ����ax
    lea bx, op2       ;ȡop2��ַ����bx
    mov si, ax        ;��ax���ַ�Ĵ���si
    mov di, bx        ;��bx���ַ�Ĵ���di
    lea ax, op3
    mov bp, ax
loop1:
    mov al, [si]      ;ȡһ��ֵ�����ۼ���al
    add al, [di]      ;ȡop2һ��ֵ��al��ֵ��Ӳ�����al
    mov [bp], al      ;��alֵ����op3��
    
    mov dl, [bp]      ;��Ļ��ӡop3
    mov ah, 2
    int 21h
    mov dl, 0Ah       ;����
    mov ah, 2
    int 21h
    mov dl, 0dh       ;�س�
    mov ah, 2
    int 21h
    inc si            ;��������
    inc di
    inc bp
    dec cx            ;�Լ�����
    jnz loop1
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
