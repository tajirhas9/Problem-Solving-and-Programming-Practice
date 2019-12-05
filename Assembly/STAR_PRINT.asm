.MODEL SMALL
.STACK 100H

.CODE

MAIN PROC
    
    MOV CX,0
    MOV CL,3
    
    MOV AH,2
        
   L1:  
        CMP CL,0
        JE EXIT
        
        MOV BL,3
        SUB BL,CL   ;BL = BL - CL
        ADD BL,1
        MOV BH,CL
        SUB BH,1
        
        L2:
            CMP BH,0
            JE L3
            
            MOV DL,' '
            INT 21H
            DEC BH
            JMP L2
        
        L3:
           CMP BL,0
           JE NEW_LINE
           
           MOV DL,'*'
           INT 21H
           DEC BL
           JMP L2
        
        NEW_LINE:
            MOV DL,0AH
            INT 21H
            MOV DL,0DH
            INT 21H
        
        DEC CL
        JMP L1
        
        
    EXIT:
        MOV AH,4CH
        INT 21H
        MAIN ENDP
END MAIN
            
         