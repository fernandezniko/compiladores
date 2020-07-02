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
    _drgidrg    db  'drgidrg','$', 9 dup (?)


.CODE
    ; Simple Asignation
    FILD _2
    FSTP x
    LEA SI, _drgidrg
    LEA DI,j
cpy_nxt:mov bl, [si]
    mov [di], bl
    inc si
    inc di
    dec cx
    jnz cpy_nxt

 mov AX, 4C00h 
int 21h ; Genera la interrupcion 21h 
 END ; fin. 
