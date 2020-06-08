c:\GnuWin32\bin\flex lexico.l
pause
c:\GnuWin32\bin\bison -dyv sintactico.y 
pause
c:\MinGW\bin\gcc.exe ts.c lex.yy.c y.tab.c -o segunda.exe
pause

segunda.exe prueba_AsigEsp.txt



pause
del lex.yy.c
del y.tab.c
del y.tab.h
del segunda.exe
pause