%{
    #include<stdio.h>
    #include<string.h>
    #include "syntax.tab.h" 
    extern YYSTYPE yylval;

    int nb_ligne=1;
    int col=0;
%}

/* -- Partie : Expressions régulières -- */
digit [0-9]
IDF [a-zA-Z]([a-zA-Z0-9_])*
integer {digit}+
float {digit}+\.[0-9]*
signedInt "("[+-]{integer}")"
signedFloat "("[+-]{float}")"
Comment1 "<!-"([^>-])*"-!>"
Comment2 "{--"([^}]|\n)*"--}" 
String \"[^\"]*\"

/* -- Partie : Règles de production -- */
%%

"MainPrgm"      { return MAINPRGM; }
"Var"           { return VAR; }
"BeginPg"       { return BEGINPG; }
"EndPg"         { return ENDPG; }
"En"            { return EN; }
"let"           { return LET; }
"@define"       { return DEFINE; }
"Const"         { return CONST; }
"Int"           { return INT; }
"Float"         { return FLOAT; }
"if"            { return IF; }
"then"          { return THEN; }
"else"          { return ELSE; }
"do"            { return DO; }
"while"         { return WHILE; }
"for"           { return FOR; }
"from"          { return FROM; }
"to"            { return TO; }
"step"          { return STEP; }
"input"         { return INPUT; }
"output"        { return OUTPUT; }
"AND"           { return AND; }
"OR"            { return OR; }

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
        yylval.str = strdup(yytext);
        return IDF;
    }
}

{integer}       { yylval.integer = atoi(yytext); return INTEGER; }
{signedInt}     { yylval.integer = atoi(yytext + 1); return INTEGER; }
{float}         { yylval.real = atof(yytext); return FLOATING; }
{signedFloat}   { yylval.real = atof(yytext + 1); return FLOATING; }
{String}        { yylval.str = strdup(yytext); return STRING; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }

"="             { return EGAL; }
":="            { return AFF; }
">"             { return SUP; }
"<"             { return INF; }
">="            { return SUPEG; }
"<="            { return INFEG; }
"=="            { return EGALITE; }
"!="            { return DIFFERENT; }

"!"             { return NOT; }

";"             { return PVG; }
":"             { return DP; }
","             { return COMMA; }
"("             { return PO; }
")"             { return PF; }
"{"             { return AO; }
"}"             { return AF; }
"["             { return CO; }
"]"             { return CF; }

{Comment1}      { /* Ignore single-line comments */ }
{Comment2}      { 
    for(int i=0; i<yyleng; i++) {
        if(yytext[i] == '\n') nb_ligne++;
    }
}

[ \t]           { /* Ignore whitespace */ }
\n              { nb_ligne++; }
.               { /* Handle lexical errors */ }
%% 




