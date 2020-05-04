c:\GnuWin32\bin\flex lexico.l

c:\GnuWin32\bin\bison -dyv sintactico.y 

c:\MinGW\bin\gcc.exe ts.c lex.yy.c y.tab.c -o primera.exe
pause
primera.exe prueba.txt
pause


del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
pause