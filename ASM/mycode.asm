data segment
buffer db 5 dup(0)
data ends

code segment
assume cs:code,ds:data
start proc far

    mov ax,data
    mov ds,ax

    mov si,0         ;si ，cx初始化0
    mov cx,0
L1: mov ah,01h       ;中断，从键盘读取一个字符存入al
    int 21h
    cmp al,0dh       ;判断是否为回车，是回车则跳转LL
    je LL
    inc cx           ;cx自增
    sub al,30h       ;数字字符-48转化数字存入
    mov buffer[si],al      ;将字符放入buffer字符串
    inc si           ;si自增
    jmp L1    
    
LL: mov si,0         
    mov al,buffer[si]
    add al,30h
    cmp al,2dh
    jne L2

    mov si,1
    sub cx,2
    xor ah,ah       ;自身异或，清除标志位
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
