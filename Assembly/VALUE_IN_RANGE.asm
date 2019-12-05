.MODEL SMALL
.STACK 100H

.DATA
    INPUT_MSG       DB  'ENTER A NUMBER : $'
    IN_RANGE_MSG    DB  'NUMBER IS IN RANGE $'
    OUT_RANGE_MSG   DB  'NUMBER IS OUT OF RANGE $'
    VAR             DB  ?
    LEFT_RANGE      DB  35H
    RIGHT_RANGE     DB  39H
    QUIT_CHARACTER  DB  'Q$'
    QUIT_MSG        DB  'TERMINATTING...$'
    
    
.CODE

MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
    
    START:
        
        LEA DX,INPUT_MSG
        MOV AH,9
        INT 21H
        
        MOV AH,1        ;INPUT
        INT 21H
        MOV BL,AL
        
        MOV AH,2        ;NEW LINE
        MOV DL,0AH
        INT 21H
        MOV DL,0DH
        INT 21H
        
        CMP BL,QUIT_CHARACTER
        JE EXIT
        
        CMP BL,LEFT_RANGE
        JNGE OUT_OF_BOUND
        
        CMP BL,RIGHT_RANGE
        JNLE OUT_OF_BOUND
        
        LEA DX,IN_RANGE_MSG
        MOV AH,9
        INT 21H
        
        MOV AH,2        ;NEW LINE
        MOV DL,0AH
        INT 21H
        MOV DL,0DH
        INT 21H
        
        JMP START
        
        OUT_OF_BOUND:
            LEA DX,OUT_RANGE_MSG
            MOV AH,9
            INT 21H
            
            MOV AH,2        ;NEW LINE
            MOV DL,0AH
            INT 21H
            MOV DL,0DH
            INT 21H
            
            JMP START
        
        
        
    EXIT:
        LEA DX,QUIT_MSG
        MOV AH,9
        INT 21H
        
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
        
            