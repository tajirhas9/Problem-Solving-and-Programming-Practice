.MODEL SMALL
.STACK 100H

.DATA
    ONE DB '1$'
    VAR DB ?

.CODE

MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    MOV AH,1    ;INPUT
    INT 21H
    MOV VAR,AL
    
    SUB VAR,17   ;ASCII SUBRACTION
    
    MOV AH,2    ;OUTPUT
    
    MOV DL,0AH  ;NEWLINE
    INT 21H
    MOV DL,0DH  ;CRET
    INT 21H
    
    LEA DX,ONE  ;OUTPUT 1 (LOAD EFFECTIVE ADDRESS)
    MOV AH,9
    INT 21H
    
    MOV AH,2    ;OUTPUT VAR
    MOV DL,VAR
    INT 21H
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN