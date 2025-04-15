%{
    #include<stdio.h>
    #include<string.h>
    #include "syntax.tab.h" 
    #include "ts.h"
    extern YYSTYPE yylval;
    int nb_ligne=1;
    int col=0;
    int after_mainprgm = 0;  // Flag to track if we just saw MainPrgm
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

"MainPrgm"      { printf("Keyword: MainPrgm\n"); Rechercher(yytext, "Mot Cle", "", "", 2);
                  after_mainprgm = 1;  // Set flag to indicate we expect the program name
                  return MAINPRGM; 
                  }
"Var"           { printf("Keyword: Var\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return VAR; }
"BeginPg"       { printf("Keyword: BeginPg\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return BEGINPG; }
"EndPg"         { printf("Keyword: EndPg\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return ENDPG; }
"let"           { printf("Keyword: let\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return LET; }
"@define"       { printf("Keyword: @define\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return DEFINE; }
"Const"         { printf("Keyword: Const\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return CONST; }
"Int"           { printf("Keyword: Int\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return INT; }
"Float"         { printf("Keyword: Float\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return FLOAT; }
"if"            { printf("Keyword: if\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return IF; }
"then"          { printf("Keyword: then\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return THEN; }
"else"          { printf("Keyword: else\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return ELSE; }
"do"            { printf("Keyword: do\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return DO; }
"while"         { printf("Keyword: while\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return WHILE; }
"for"           { printf("Keyword: for\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return FOR; }
"from"          { printf("Keyword: from\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return FROM; }
"to"            { printf("Keyword: to\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return TO; }
"step"          { printf("Keyword: step\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return STEP; }
"input"         { printf("Keyword: input\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return INPUT; }
"output"        { printf("Keyword: output\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return OUTPUT; }
"AND"           { printf("Keyword: AND\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return AND; }
"OR"            { printf("Keyword: OR\n"); Rechercher(yytext, "Mot Cle", "", "", 2); return OR; }



{IDF} {
    if (after_mainprgm == 1) {
        printf("Program name: %s\n", yytext);
        col += yyleng;
        yylval.str = strdup(yytext);
        after_mainprgm = 0;  // Reset the flag
        return PROGNAME;
    }
    if(yyleng > 14) {
        printf("ERROR lexical ! Identifier too long: %s\n", yytext);
    }
    else if (strstr(yytext, "__") != NULL) {
        printf("ERROR lexical ! Identifier contains '__': %s\n", yytext);
    }
    else if (yytext[yyleng-1] == '_') {
        printf("ERROR lexical ! Identifier ends with '_': %s\n", yytext);
    }
    else {
        printf("Identifier: %s\n", yytext);
        col += yyleng;
        yylval.str = strdup(yytext);
    }
        return IDF;
}

{integer}  { 
    col += yyleng;
    int value = atoi(yytext);
    if (value > 32767) {
        printf("ERROR Integer overflow: %s\n", yytext);
        
    }
    yylval.integer = value;
    return INTEGER;
}
{signedInt}  { 
    col += yyleng;
    char sign = yytext[1];  // + or -
    int value = atoi(yytext + 2);  // Skip ( and sign
    if (value < -32768 || value > 32767) {
        printf("\n");
        printf("ERROR Integer overflow: %s\n", yytext);
        
    }
    if (sign == '-') value = -value;
    yylval.integer = value;
    return INTEGER;
}
{float}         { printf("\n float: %f\n", atof(yytext)); col += yyleng; yylval.real = atof(yytext); return FLOATING; }
{signedFloat}   { col += yyleng; char sign = yytext[1]; float value = atof(yytext + 2); if (sign == '-') value = -value; yylval.real = value; return FLOATING; }
{String}        { col += yyleng; yylval.str = strdup(yytext); return STRING; }

"+"             { printf("Separator: +\n"); Rechercher(yytext, "Separatreur", "", "", 3); return PLUS; }
"-"             { printf("Separator: -\n"); Rechercher(yytext, "Separatreur", "", "", 3); return MINUS; }
"*"             { printf("Separator: *\n"); Rechercher(yytext, "Separatreur", "", "", 3); return MULT; }
"/"             { printf("Separator: /\n"); Rechercher(yytext, "Separatreur", "", "", 3); return DIV; }
"="             { printf("Separator: =\n"); Rechercher(yytext, "Separatreur", "", "", 3); return EGAL; }
":="            { printf("Separator: :=\n"); Rechercher(yytext, "Separatreur", "", "", 3); return AFF; }
">"             { printf("Separator: >\n"); Rechercher(yytext, "Separatreur", "", "", 3); return SUP; }
"<"             { printf("Separator: <\n"); Rechercher(yytext, "Separatreur", "", "", 3); return INF; }
">="            { printf("Separator: >=\n"); Rechercher(yytext, "Separatreur", "", "", 3); return SUPEG; }
"<="            { printf("Separator: <=\n"); Rechercher(yytext, "Separatreur", "", "", 3); return INFEG; }
"=="            { printf("Separator: ==\n"); Rechercher(yytext, "Separatreur", "", "", 3); return EGALITE; }
"!="            { printf("Separator: !=\n"); Rechercher(yytext, "Separatreur", "", "", 3); return DIFFERENT; }
"!"             { printf("Separator: !\n"); Rechercher(yytext, "Separatreur", "", "", 3); return NOT; }
";"             { printf("Separator: ;\n"); Rechercher(yytext, "Separatreur", "", "", 3); return PVG; }
":"             { printf("Separator: :\n"); Rechercher(yytext, "Separatreur", "", "", 3); return DP; }
","             { printf("Separator: ,\n"); Rechercher(yytext, "Separatreur", "", "", 3); return COMMA; }
"("             { printf("Separator: (\n"); Rechercher(yytext, "Separatreur", "", "", 3); return PO; }
")"             { printf("Separator: )\n"); Rechercher(yytext, "Separatreur", "", "", 3); return PF; }
"{"             { printf("Separator: {\n"); Rechercher(yytext, "Separatreur", "", "", 3); return AO; }
"}"             { printf("Separator: }\n"); Rechercher(yytext, "Separatreur", "", "", 3); return AF; }
"["             { printf("Separator: [\n"); Rechercher(yytext, "Separatreur", "", "", 3); return CO; }
"]"             { printf("Separator: ]\n"); Rechercher(yytext, "Separatreur", "", "", 3); return CF; }

{Comment1}      { printf("Single ligne comment !\n"); col += yyleng; } 
{Comment2}      {  
    printf("Multi ligne comment !\n");
    for(int i=0; i<yyleng; i++) {
        if(yytext[i] == '\n') nb_ligne++;
    }
    col += yyleng;
}

[ \t]           { col += yyleng; }
\n              { nb_ligne++; col = 0; }
.               { printf("ERROR lexical ! Unrecognized character: %s at line %d, column %d\n", yytext, nb_ligne, col); col += yyleng; ; }

%% 