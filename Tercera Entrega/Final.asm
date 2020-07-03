include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 50

.DATA
	b	dd	?
	j	dd	?
	c	dd	?
	_1	dd	1.0
	_2	dd	2.0
	_3	dd	3.0
	_ADD	dd	?
	_SUB	dd	?
	_MUL	dd	?
	_DIV	dd	?


.CODE
START:
	mov AX,@DATA
	mov DS,AX
	mov es,ax
	FLD _1
	FSTP b
	FLD _2
	FSTP j
	FLD _3
	FSTP c
	; Condition
	FLD b
	FCOMP j
	FSTSW AX
	SAHF
	JNE ELSE_1
	JMP ELSE_1
	DisplayFloat j,2
	newLine 1
	DisplayFloat c,2
	newLine 1

 mov AX, 4C00h 
int 21h ; Genera la interrupcion 21h 
 END START ; fin. 
