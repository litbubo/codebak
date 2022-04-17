; multi-segment executable file template.

data segment
    ; add your data here!
    pkey db "press any key...$"
    op1 db 38h, 46h, 35h, 56h, 31h, 39h
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

    ; add your code here
    lea si, op1
    mov cx, 5
    mov bl, [si]
looper:
    inc si
    cmp bl, [si]
    jc done
    mov bl, [si]
done:
    dec cx
    jnz looper


            
    lea dx, pkey
    mov ah, 9
    int 21h        ; output string at ds:dx
    
    ; wait for any key....    
    mov ah, 1
    int 21h
    
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends

end start ; set entry point and stop the assembler.
