include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 50

.DATA
	x	dd	?
	_2	dd	2.0


.CODE
	; Simple Asignation
	FILD _2
	FSTP x
	DisplayInteger "hola"

 mov AX, 4C00h 
int 21h ; Genera la interrupcion 21h 
 END ; fin. 
