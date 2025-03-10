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
}
%start programme
%token MAINPRGM VAR BEGINPG ENDPG EN LET DEFINE CONST INT FLOAT
%token IF THEN ELSE DO WHILE FOR FROM TO STEP INPUT OUTPUT
%token PLUS MINUS MULT DIV
%token AFF EGAL INF SUP SUPEG INFEG EGALITE DIFFERENT
%token AND OR NOT
%token PVG DP COMMA PO PF AO AF CO CF
%token INTEGER FLOATING STRING IDF

%type <str> IDF STRING
%type <integer> INTEGER
%type <real> FLOATING
%type <integer> value
%type <integer> expression
%type <str> var_list
%type <str> affectation
%type <str> lecture
%type <str> ecriture
%type <str> declaration
%type <str> boucle


%left OR
%left AND
%right NOT
%left INF SUP SUPEG INFEG EGALITE DIFFERENT
%left PLUS MINUS
%left MULT DIV

%%

programme: MAINPRGM IDF PVG VAR declarations BEGINPG instructions ENDPG PVG {
    printf("PARSER: Programme parsed successfully.\n");
};

declarations: declaration { printf("PARSER: Single declaration processed.\n"); }
            | declarations declaration { printf("PARSER: Multiple declarations processed.\n"); };

declaration: LET var_list DP type PVG { printf("PARSER: Variable declaration.\n"); }
           | LET var_list DP CO type PVG INTEGER CF PVG { printf("PARSER: Array declaration.\n"); }
           | DEFINE CONST IDF DP type EGAL value PVG { printf("PARSER: Constant definition.\n"); };

var_list: IDF { printf("PARSER: Variable: %s\n", $1); }
        | var_list COMMA IDF { printf("PARSER: Variable list extended: %s\n", $3); };  

type: INT { printf("PARSER: Type: Integer.\n"); }
    | FLOAT { printf("PARSER: Type: Float.\n"); };

value: INTEGER { printf("PARSER: Integer Value: %d\n", $1); }
     | FLOATING { printf("PARSER: Floating Value: %f\n", $1); };

instructions: instruction { printf("PARSER: Single instruction processed.\n"); }
            | instructions instruction { printf("PARSER: Multiple instructions processed.\n"); };

instruction: affectation { printf("PARSER: Affectation processed.\n"); }
           | condition { printf("PARSER: Condition processed.\n"); }
           | boucle { printf("PARSER: Loop processed.\n"); }
           | lecture { printf("PARSER: Input instruction processed.\n"); }
           | ecriture { printf("PARSER: Output instruction processed.\n"); };

affectation: IDF AFF expression PVG { printf("PARSER: Assignment to variable: %s\n", $1); }
           | IDF CO expression CF AFF expression PVG { printf("PARSER: Array assignment.\n"); };

condition: IF PO conditions PF THEN AO instructions AF ELSE AO instructions AF {printf("PARSER: If-Else condition processed.\n");}
        | IF PO conditions PF THEN AO instructions AF { printf("PARSER: If condition processed.\n"); };

boucle: DO AO instructions AF WHILE PO conditions PF PVG { printf("PARSER: Do-While loop processed.\n"); }
      | FOR IDF FROM expression TO expression STEP expression AO instructions AF {
          printf("PARSER: For loop with variable: %s\n", $2);
      };

lecture: INPUT PO IDF PF PVG { printf("PARSER: Input received into variable: %s\n", $3); };

ecriture: OUTPUT PO STRING COMMA IDF PF PVG { printf("PARSER: Outputting: %s with variable: %s\n", $3, $5); };
        | OUTPUT PO STRING PF PVG { printf("PARSER: Outputting: %s\n", $3); };

conditions: expression { printf("PARSER: Condition checked.\n"); }
          | conditions OR conditions { printf("PARSER: OR condition processed.\n"); }
          | conditions AND conditions { printf("PARSER: AND condition processed.\n"); }
          | PO conditions PF { printf("PARSER: Parenthesized condition.\n"); }
          | expression EGAL expression { printf("PARSER: Equality condition processed.\n"); }
          | expression INF expression { printf("PARSER: Less than condition processed.\n"); }
          | expression SUP expression { printf("PARSER: Greater than condition processed.\n"); }
          | expression SUPEG expression { printf("PARSER: Greater than or equal condition processed.\n"); }
          | expression INFEG expression { printf("PARSER: Less than or equal condition processed.\n"); }
          | expression EGALITE expression { printf("PARSER: Exact equality condition processed.\n"); }
          | expression DIFFERENT expression { printf("PARSER: Not equal condition processed.\n"); }
          | NOT conditions { printf("PARSER: NOT condition processed.\n"); };

expression: INTEGER { printf("PARSER: Integer expression: %d\n", $1); }
          | FLOATING { printf("PARSER: Floating point expression: %f\n", $1); }
          | IDF { printf("PARSER: Variable expression: %s\n", $1); }
          | expression PLUS expression { printf("PARSER: Addition operation.\n"); }
          | IDF CO expression CF { printf("PARSER: Array expression.\n"); }
          | expression MINUS expression { printf("PARSER: Subtraction operation.\n"); }
          | expression MULT expression { printf("PARSER: Multiplication operation.\n"); }
          | expression DIV expression { printf("PARSER: Division operation.\n"); }
          | PO expression PF { printf("PARSER: Parenthesized expression.\n"); };

%%

int main() {
    printf("Debut de l'analyse syntaxique...\n");
    yyparse();
    printf("Fin de l'analyse syntaxique.\n");
    return 0;
}

void yyerror(const char* msg) {
    printf("Erreur Syntaxique a la ligne %d : %s\n", nb_ligne, msg);
}
