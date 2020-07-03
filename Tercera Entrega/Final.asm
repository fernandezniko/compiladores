include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 50

.DATA
	uno	dd	?
	dos	dd	?
	tres	dd	?
	a	dd	?
	b	dd	?
	_2	dd	2.0
	_3	dd	3.0
	_4	dd	4.0
	_5	dd	5.0
	_ADD	dd	?
	_SUB	dd	?
	_MUL	dd	?
	_DIV	dd	?


.CODE
START:
	mov AX,@DATA
	mov DS,AX
	mov es,ax
	FLD _2
	FSTP a
	FLD _3
	FSTP b
	FLD _3
	FSTP uno
	DisplayFloat uno,2
	newLine 1
	FLD _4
	FSTP uno
	FLD _5
	FSTP dos
	DisplayFloat uno,2
	newLine 1
	DisplayFloat dos,2
	newLine 1

 mov AX, 4C00h 
int 21h ; Genera la interrupcion 21h 
 END START ; fin. 
