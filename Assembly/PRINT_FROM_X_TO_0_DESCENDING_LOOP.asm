.MODEL SMALL
.STACK 100H 

.DATA
    COMMA   DB  ',$'
.CODE
MAIN PROC
    
    MOV AX,@DATA
    MOV DS,AX
     
    MOV AH,1
    INT 21H
    MOV BL,AL
    
    SUB AL,2FH
    
    MOV CX,0
    MOV CL,AL
    
    MOV AH,2    
    MOV DL,0AH  ;NEW LINE
    INT 21H
    MOV DL,0DH
    INT 21H
    
    L1:
        MOV AH,2
        MOV DL,BL
        INT 21H
        
        DEC BL
        
        LEA DX,COMMA
        MOV AH,9
        INT 21H
        
        LOOP L1
    
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
        
    