include macros2.asm 
include number.asm 


.MODEL LARGE
.386
.STACK 200h

MAXTEXTSIZE equ 50

.DATA
    x   dd  ?
    j   db  MAXTEXTSIZE dup (?),'$'
    _2  dd  2.0


.CODE


START:


mov AX,@DATA

mov DS,AX

 mov es,ax  ; Simple Asignation
    FLD _2
    FSTP x
    DisplayFloat x,2

 mov AX, 4C00h 
int 21h ; Genera la interrupcion 21h 
 END START ; fin. 
