@echo off
del y.output
c:\GnuWin32\bin\flex -d lexico.l

c:\GnuWin32\bin\bison -dyv sintactico.y 

c:\MinGW\bin\gcc.exe ts.c lex.yy.c y.tab.c -o primera.exe
primera.exe prueba.txt
pause
@echo off

del lex.yy.c
del y.tab.c