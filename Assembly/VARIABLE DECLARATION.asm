.MODEL SMALL
.STACK 100H

.DATA
    VAR1 DB 5
    VAR2 DB ?
    MSG1 DB 'VAR 1 : $'
    MSG2 DB 'VAR2 : $'
.CODE

MAIN PROC
    
    MOV AX,@DATA            ;INITIALIZE DATA SEGMENT
    MOV DS,AX
    
    MOV AH,1        ;INPUT VAR2
    
    INT 21H
    MOV VAR2,AL
    
    ADD VAR1,48     ;
    
    MOV AH,2        ;OUTPUT COMMAND
    
    MOV DL,0AH      ;newline
    INT 21H
    MOV DL,0DH      ;carry return
    INT 21H
    
    LEA DX,MSG1
    MOV AH,9
    INT 21H 
    
    MOV AH,2
    
    MOV DL,VAR1
    INT 21H
    
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
    
    LEA DX,MSG2
    MOV AH,9
    INT 21H 
    
    MOV AH,2
    
    MOV DL,VAR2
    INT 21H
