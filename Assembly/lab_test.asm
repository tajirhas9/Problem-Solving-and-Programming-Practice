section .text
	global _start
_start:
	;Read
	mov eax,3
	mov ebx,2
	mov edx,2
	mov ecx,num1
	int 0x80

	;Read 2nd number
	mov eax,3
	mov ebx,2
	mov edx,2
	mov ecx,num2
	int 0x80
	
	;Add	
	mov eax,num1	
	add eax,num2	

	;Compare	
	cmp eax,0026h
	jge greater
	
	mov eax,4
	mov ebx,1
	mov ecx, less_msg
	mov edx,1
	int 0x80
	
	mov eax,1
	int 0x80

greater:
	mov eax,4
	mov ebx,1
	mov ecx,greater_msg
	mov edx,1
	int 0x80
	
	;Exit
	mov eax,1
	int 0x80	
	
section .bss
	num1 resb 2
	num2 resb 2
	sum resb 4
section .data
	greater_msg db '>' , 0xa
	less_msg db '<', 0xa

