

CODE SEGMENT
ASSUME CS:CODE
ADR_TIMER_CONTROL EQU  0400H+0006H
ADR_TIMER_DATA0   EQU  0400H+0000H
ADR_TIMER_DATA1   EQU  0400H+0002H
ADR_TIMER_DATA2   EQU  0400H+0004H
START:      

	MOV DX, ADR_TIMER_CONTROL
    MOV AL, 10010110B
    OUT DX, AL
    
	MOV DX, ADR_TIMER_DATA2
    MOV AL, 80
    OUT DX, AL
    

ENDLESS:
	JMP   ENDLESS
CODE ENDS
	END START