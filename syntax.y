%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int yylex();
extern int nb_ligne;
void yyerror(const char* msg);
%}


%union {
    int integer;
    float real;
    char* str;  // For strings and identifiers
    char letter; // For single letters
}

%start MAINPRGM
%token VAR BEGINPG ENDPG EN LET DEFINE CONST INT FLOAT
%token IF THEN ELSE DO WHILE FOR FROM TO STEP INPUT OUTPUT
%token PLUS MINUS MULT DIV
%token AFF EGAL INF SUP SUPEG INFEG EGALITE DIFFERENT
%token AND OR NOT
%token PVG DP COMMA PO PF AO AF CO CF
%token INTEGER FLOATING STRING IDF
%token <letter> LETTER

%left OR
%left AND
%right NOT
%left INF SUP SUPEG INFEG EGALITE DIFFERENT
%left PLUS MINUS
%left MULT DIV




%%
MAINPRGM: programme;
programme: IDF PVG VAR declarations BEGINPG instructions ENDPG PVG;

declarations: declaration | declarations declaration;

declaration: LET IDF DP INT PVG
            | LET IDF DP FLOAT PVG
            | DEFINE CONST IDF DP INT EGAL INTEGER PVG
            | DEFINE CONST IDF DP FLOAT EGAL FLOATING PVG;

instructions: instruction | instructions instruction;

instruction: affectation | condition | boucle | lecture | ecriture;

affectation: IDF AFF expression PVG;

condition: IF PO expression PF THEN AO instructions AF ELSE AO instructions AF;

boucle: DO AO instructions AF WHILE PO expression PF PVG;

lecture: INPUT PO IDF PF PVG;

ecriture: OUTPUT PO STRING COMMA IDF PF PVG;

expression: INTEGER | IDF | expression PLUS expression | expression MINUS expression;

%%

int main() {
    printf("Début de l'analyse syntaxique...\n");
    yyparse();
    printf("Fin de l'analyse syntaxique.\n");
    return 0;
}

void yyerror(const char* msg) {
    printf("Erreur Syntaxique à la ligne %d : %s\n", nb_ligne, msg);
}
