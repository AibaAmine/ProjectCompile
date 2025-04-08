%{
    #include<stdio.h>
    #include<string.h>
    #include "syntax.tab.h" 
    #include "ts.h"
    extern YYSTYPE yylval;
    int nb_ligne=1;
    int col=0;
%}

digit [0-9]
IDF [a-zA-Z]([a-z0-9_])*
integer {digit}+
float {digit}+"."{digit}+
signedInt "("[+-]{integer}")"
signedFloat "("[+-]{float}")"
Comment1 "<!-".*"-!>"
Comment2 "{--"(.|\n)*"--}" 
String \".*\"

%%

"MainPrgm"      { Rechercher(yytext, "Mot Cle", "", "", 2); return MAINPRGM; }
"Var"           { Rechercher(yytext, "Mot Cle", "", "", 2); return VAR; }
"BeginPg"       { Rechercher(yytext, "Mot Cle", "", "", 2); return BEGINPG; }
"EndPg"         { Rechercher(yytext, "Mot Cle", "", "", 2); return ENDPG; }
"let"           { Rechercher(yytext, "Mot Cle", "", "", 2); return LET; }
"@define"       { Rechercher(yytext, "Mot Cle", "", "", 2); return DEFINE; }
"Const"         { Rechercher(yytext, "Mot Cle", "", "", 2); return CONST; }
"Int"           { Rechercher(yytext, "Mot Cle", "", "", 2); return INT; }
"Float"         { Rechercher(yytext, "Mot Cle", "", "", 2); return FLOAT; }
"if"            { Rechercher(yytext, "Mot Cle", "", "", 2); return IF; }
"then"          { Rechercher(yytext, "Mot Cle", "", "", 2); return THEN; }
"else"          { Rechercher(yytext, "Mot Cle", "", "", 2); return ELSE; }
"do"            { Rechercher(yytext, "Mot Cle", "", "", 2); return DO; }
"while"         { Rechercher(yytext, "Mot Cle", "", "", 2); return WHILE; }
"for"           { Rechercher(yytext, "Mot Cle", "", "", 2); return FOR; }
"from"          { Rechercher(yytext, "Mot Cle", "", "", 2); return FROM; }
"to"            { Rechercher(yytext, "Mot Cle", "", "", 2); return TO; }
"step"          { Rechercher(yytext, "Mot Cle", "", "", 2); return STEP; }
"input"         { Rechercher(yytext, "Mot Cle", "", "", 2); return INPUT; }
"output"        { Rechercher(yytext, "Mot Cle", "", "", 2); return OUTPUT; }
"AND"           { Rechercher(yytext, "Mot Cle", "", "", 2); return AND; }
"OR"            { Rechercher(yytext, "Mot Cle", "", "", 2); return OR; }

{IDF} {
    if(yyleng > 14) {
        exit(1);
    }
    else if (strstr(yytext, "__") != NULL) {
        exit(1);
    }
    else if (yytext[yyleng-1] == '_') {
        exit(1);
    }
    else {
        Rechercher(yytext, "IDF", "", "", 1);
        yylval.str = strdup(yytext);
        return IDF;
    }
}

{integer}  { 
    int value = atoi(yytext);
    if (value > 32767) {
        printf("Integer overflow: %s\n", yytext);
        printf("\n");
        exit(1);
    }
    yylval.integer = value;
    return INTEGER;
}
{signedInt}  { 
    int value = atoi(yytext + 1);
    if (value < -32768 || value > 32767) {
        printf("\n");
        printf("Integer overflow: %s\n", yytext);
        exit(1);
    }
    yylval.integer = value;
    return INTEGER;
}
{float}         {printf("\n float: %f\n", atof(yytext)); yylval.real = atof(yytext); return FLOATING;  }
{signedFloat}   { yylval.real = atof(yytext + 1); return FLOATING; }
{String}        { yylval.str = strdup(yytext); return STRING; }

"+"             { Rechercher(yytext, "Separatreur", "", "", 3); return PLUS; }
"-"             { Rechercher(yytext, "Separatreur", "", "", 3); return MINUS; }
"*"             { Rechercher(yytext, "Separatreur", "", "", 3); return MULT; }
"/"             { Rechercher(yytext, "Separatreur", "", "", 3); return DIV; }
"="             { Rechercher(yytext, "Separatreur", "", "", 3); return EGAL; }
":="            { Rechercher(yytext, "Separatreur", "", "", 3); return AFF; }
">"             { Rechercher(yytext, "Separatreur", "", "", 3); return SUP; }
"<"             { Rechercher(yytext, "Separatreur", "", "", 3); return INF; }
">="            { Rechercher(yytext, "Separatreur", "", "", 3); return SUPEG; }
"<="            { Rechercher(yytext, "Separatreur", "", "", 3); return INFEG; }
"=="            { Rechercher(yytext, "Separatreur", "", "", 3); return EGALITE; }
"!="            { Rechercher(yytext, "Separatreur", "", "", 3); return DIFFERENT; }
"!"             { Rechercher(yytext, "Separatreur", "", "", 3); return NOT; }
";"             { Rechercher(yytext, "Separatreur", "", "", 3); return PVG; }
":"             { Rechercher(yytext, "Separatreur", "", "", 3); return DP; }
","             { Rechercher(yytext, "Separatreur", "", "", 3); return COMMA; }
"("             { Rechercher(yytext, "Separatreur", "", "", 3); return PO; }
")"             { Rechercher(yytext, "Separatreur", "", "", 3); return PF; }
"{"             { Rechercher(yytext, "Separatreur", "", "", 3); return AO; }
"}"             { Rechercher(yytext, "Separatreur", "", "", 3); return AF; }
"["             { Rechercher(yytext, "Separatreur", "", "", 3); return CO; }
"]"             { Rechercher(yytext, "Separatreur", "", "", 3); return CF; }

{Comment1}      { }
{Comment2}      { 
    for(int i=0; i<yyleng; i++) {
        if(yytext[i] == '\n') nb_ligne++;
    }
}

[ \t]           { }
\n              { nb_ligne++; }
.               { }
%% 




