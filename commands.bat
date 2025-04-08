flex lexical.l 
bison -d -v syntax.y
gcc lex.yy.c syntax.tab.c E:\codeblocks\MinGW\lib\libfl.a E:\codeblocks\MinGW\lib\liby.a -o compil
compil.exe<test.txt