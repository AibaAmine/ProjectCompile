%{
    #include<stdio.h>
    #include<string.h>
    int nb_ligne=1;
    int col=0;
%}


/* -- Partie : Expressions régulières -- */
letter [a-zA-Z]
digit [0-9]
IDF {letter}({letter}|{digit}|_)*
integer {digit}+
float {digit}+\.[0-9]*
signedInt "("[+-]{integer}")"
signedFloat "("[+-]{float}")"
Comment1 "<!-"([^>-])*"-!>"
Comment2 "{--"([^}]|\n)*"--}" 
String \"[^\"]*\"

/* -- Partie : Règles de production -- */
%%

"MainPrgm"      { printf("mot cle : MainPrgm\t"); }
"Var"           { printf("mot cle : Var\t"); }
"BeginPg"       { printf("mot cle : BeginPg\t"); }
"EndPg"         { printf("mot cle : EndPg\t"); }
"En"            { printf("mot cle : En\t"); } 
"let"           { printf("mot cle : let\t"); }
"@define"       { printf("mot cle : @define\t"); }
"Const"         { printf("mot cle : Const\t"); }
"Int"           { printf("mot cle : Int\t"); }
"Float"         { printf("mot cle : Float\t"); }
"if"            { printf("mot cle : if\t"); }
"then"          { printf("mot cle : then\t"); }
"else"          { printf("mot cle : else\t"); }
"do"            { printf("mot cle : do\t"); }
"while"         { printf("mot cle : while\t"); }
"for"           { printf("mot cle : for\t"); }
"from"          { printf("mot cle : from\t"); }
"to"            { printf("mot cle : to\t"); }
"step"          { printf("mot cle : step\t"); }
"input"         { printf("mot cle : input\t"); }
"output"        { printf("mot cle : output\t"); }

{IDF}           { 
                  if(yyleng > 14) 
                    printf("Erreur IDF plus de 14 char\n");
                  else if (strstr(yytext, "__") != NULL)
                    printf("Erreur IDF contient des tirets bas consecutifs\n");
                  else if (yytext[yyleng-1] == '_')
                    printf("Erreur IDF se termine par un tiret bas\n");
                  else
                    printf("IDF : %s \t", yytext); 
                }

{letter}        { printf("IDF : %s \t", yytext); }


{integer}       { printf("entier : %s \t", yytext); }
{signedInt}     { printf("entier signe : %s \t", yytext); }
{float}         { printf("reel : %s \t", yytext); }
{signedFloat}   { printf("reel signe : %s \t", yytext); }
{String}        { printf("chaine de caracteres : %s \t", yytext); }

";"             { printf("pvg \t"); }
":"             { printf("deux points \t"); }
","             { printf("virgule \t"); }
"("             { printf("parenthese ouvrante \t"); }
")"             { printf("parenthese fermante \t"); }
"{"             { printf("accolade ouvrante \t"); }
"}"             { printf("accolade fermante \t"); }
"["             { printf("crochet ouvrant \t"); }
"]"             { printf("crochet fermant \t"); }
":="            { printf("affectation \t"); }
"="             { printf("egal \t"); }

"+"             { printf("addition \t"); }
"-"             { printf("soustraction \t"); }
"*"             { printf("multiplication \t"); }
"/"             { printf("division \t"); }

">"             { printf("superieur \t"); }
"<"             { printf("inferieur \t"); }
">="            { printf("superieur ou egal \t"); }
"<="            { printf("inferieur ou egal \t"); }
"=="            { printf("egalite \t"); }
"!="            { printf("different \t"); }

"AND"           { printf("ET logique \t"); }
"OR"            { printf("OU logique \t"); }
"!"             { printf("NON logique \t"); }

{Comment1}      { printf("commentaire(1 ligne) reconnu \t"); }
{Comment2}      { 
                  printf("commentaire(plusieurs lignes) reconnu \t"); 
                  for(int i=0; i<yyleng; i++) {
                    if(yytext[i] == '\n') nb_ligne++;
                  }
                }

[ \t]           { /* Ignorer les espaces et les tabulations */ }
\n              { nb_ligne++; printf("\n"); }
.               { printf("erreur lexicale a la ligne %d : %s\n", nb_ligne, yytext); }
%%

int main() 
{
    yylex();
    return 0;
}
