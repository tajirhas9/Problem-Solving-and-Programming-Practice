 .MODEL SMALL
.STACK 100H

.DATA
    msg1 DB 'HELLO WORLD $'
    msg2 DB 'MY NAME IS TAJIR HASNAIN $'
    
.CODE
MAIN PROC
    
    MOV AX,@DATA    ;INITIALIZE DATA SEGMENT
    MOV DS,AX
    
    LEA DX,msg1     ;LOAD EFFECTIVE ADDRESS
    MOV AH,9
    INT 21H
           
    MOV AH,2
    MOV DL,0AH
    INT 21H
    MOV DL,0DH
    INT 21H
            
    LEA DX,msg2     ;LOAD EFFECTIVE ADDRESS
    MOV AH,9   
    INT 21H
    
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN