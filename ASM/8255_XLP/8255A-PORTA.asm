CODE SEGMENT
    ASSUME CS:CODE
    ADR_8255_CONTROL  EQU   0200H+0006H
    ADR_8255_PORT_A   EQU  0200H+0000H
    ADR_8255_PORT_B   EQU  0200H+0002H
    ADR_8255_PORT_C   EQU  0200H+0004H
START:
    ;������ 0              A�������B������ ���Ƿ�ʽ0
    MOV DX, ADR_8255_CONTROL
    MOV AL, 10000010B
    OUT DX, AL 
    
    MOV DX, ADR_8255_PORT_A
    MOV AL, 11110000B
    OUT DX, AL       
           
HERE:

    JMP HERE

CODE ENDS
    END START
