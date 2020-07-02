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
    _4  dd  4.0
    _5  dd  5.0
    _ADD    dd  ?
    _SUB    dd  ?
    _MUL    dd  ?
    _DIV    dd  ?


.CODE
START:
    mov AX,@DATA
    mov DS,AX
    mov es,ax
    FLD _4
    FLD _5
    FMUL
    FSTP _MUL
    FLD _2
    FLD _MUL
    FADD
    FSTP _ADD
    ; Simple Asignation
    FLD _ADD
    FSTP x
    DisplayFloat x,2

 mov AX, 4C00h 
int 21h ; Genera la interrupcion 21h 
 END START ; fin. 
