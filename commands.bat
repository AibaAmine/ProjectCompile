flex lexical.l 
bison -d syntax.y
gcc lex.yy.c syntax.tab.c   "C:\Program Files (x86)\CodeBlocks\MinGW\lib\libfl.a" "C:\Program Files (x86)\CodeBlocks\MinGW\lib\liby.a" -o compil
compil.exe<test.txt