include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 50

.DATA
	a1	dd	?
	b2	dd	?
	_2	dd	2.0


.CODE
