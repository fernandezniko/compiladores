c:\GnuWin32\bin\flex lexico.l
pause
c:\GnuWin32\bin\bison -dyv sintactico.y
pause
c:\MinGW\bin\gcc.exe ts.c lex.yy.c y.tab.c -o primera.exe
pause
primera.exe prueba_ENTSAL.txt
pause
del lex.yy.c
del y.tab.c
del y.output
del y.tab.h
del primera.exe
del ts.txt
pause