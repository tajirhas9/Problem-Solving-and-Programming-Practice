.MODEL SMALL
.STACK 100H

.DATA
    QUIT_CHARACTER  DB  'Q$'
    TYPE_MSG        DB  'YOU TYPED : $'
    QUIT_MSG        DB  'TERMINATING...$'
.CODE

MAIN PROC
        
    MOV AX,@DATA
    MOV DS,AX
    
    START:
        MOV AH,1
        INT 21H
        MOV BL,AL
        
        MOV AH,2
        MOV DL,0AH
        INT 21H
        MOV DL,0DH
        INT 21H
        
        LEA DX,TYPE_MSG
        MOV AH,9
        INT 21H
        
        MOV AH,2
        MOV DL,BL
        INT 21H
        
        MOV DL,0AH
        INT 21H
        MOV DL,0DH
        INT 21H
        
        CMP BL,QUIT_CHARACTER
        JNE START

    EXIT:
        LEA DX,QUIT_MSG
        MOV AH,9
        INT 21H
        
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
        
        
