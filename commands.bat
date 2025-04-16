
flex lexical.l 
bison -d syntax.y

gcc lex.yy.c syntax.tab.c -lfl -ly -o compil

compil.exe<test.txt