data segment
buffer db 5 dup(0)
data ends

code segment
assume cs:code,ds:data
start proc far

    mov ax,data
    mov ds,ax

    mov si,0         ;si ��cx��ʼ��0
    mov cx,0
L1: mov ah,01h       ;�жϣ��Ӽ��̶�ȡһ���ַ�����al
    int 21h
    cmp al,0dh       ;�ж��Ƿ�Ϊ�س����ǻس�����תLL
    je LL
    inc cx           ;cx����
    sub al,30h       ;�����ַ�-48ת�����ִ���
    mov buffer[si],al      ;���ַ�����buffer�ַ���
    inc si           ;si����
    jmp L1    
    
LL: mov si,0         
    mov al,buffer[si]
    add al,30h
    cmp al,2dh
    jne L2

    mov si,1
    sub cx,2
    xor ah,ah       ;������������־λ
    mov al,buffer[si]
    cmp cx,0
    jbe L8
    
L7: inc si
    mov bl,buffer[si]
    mov di,10
    xor bh,bh
    mul di
    add ax,bx
    loop L3
L8: neg ax
    jmp L4

L2: mov si,0
    dec cx
    xor ah,ah
    mov al,buffer[si]
    cmp cx,0
    jbe L4
L3: inc si
    mov bl,buffer[si]
    mov di,10
    xor bh,bh
    mul di
    add ax,bx
    loop L3


L4: mov cx,16
    mov bx,ax
L5: rol bx,1
    mov dl,30h
    adc dl,0
    mov ah,02h
    int 21h
    loop L5

    mov ah,4ch
    int 21h
start endp
code ends
     end start
