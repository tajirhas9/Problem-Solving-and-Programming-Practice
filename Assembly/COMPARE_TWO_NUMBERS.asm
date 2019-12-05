.MODEL SMALL
.STACK 100H

.DATA
    VAR         DB  ?
    COMPARER    DB  35H
    GREATER_MSG DB  'GREATER THAN 5 $'
    LESS_MSG    DB  'lESS THAN 5 $'
    EQUAL_MSG   DB  'EQUAL TO 5 $'
    INPUT_MSG   DB  'ENTER A NUMBER : $'
     
.CODE

MAIN PROC
   
    
    MOV AX,@DATA
    MOV DS,AX
    
    LEA DX,INPUT_MSG
    MOV AH,9
    INT 21H
    
    MOV AH,1
    
    INT 21H
    
    MOV VAR,AL
    
    MOV BL,COMPARER
    
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    CMP VAR,BL
    JG GREATER
    
    LESS_OR_EQUAL:
        
        CMP BL,VAR
        JE EQUAL
        
        LEA DX,LESS_MSG
        MOV AH,9
        INT 21H
        JMP EXIT
        
        EQUAL:
            LEA DX,EQUAL_MSG
            MOV AH,9
            INT 21H
            JMP EXIT
    
    GREATER:
        LEA DX,GREATER_MSG
        MOV AH,9
        INT 21H
        
    
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN