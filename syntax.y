
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *get_value(char* name);  // Declare get_value
void Rechercher(char entite[], char code[], char type[], char val[], int y);
void initialization();
void afficher();


void verifierDoubleDeclaration(char* idf, char* type);
void verifierDeclaration(char* idf);
void verifierAffectation(char* idf_left, char* idf_right_or_val, int is_const);
void verifierTypeCompatible(char* idf1, char* idf2, char op);
void verifierConstanteModification(char* idf);
void verifierDivisionParZero(char* operand);
int isNumeric(char* val);
char* getType(char* idf);
int isConstant(char* idf);


extern int yylex();
extern int nb_ligne;
void yyerror(const char* msg);

int valType;
int intValue;
float floatValue;
char* strValue;

%}

%union {
    int integer;
    float real;
    char* str;  
}
%start programme
%token MAINPRGM VAR BEGINPG ENDPG LET DEFINE CONST INT FLOAT
%token IF THEN ELSE DO WHILE FOR FROM TO STEP INPUT OUTPUT
%token PLUS MINUS MULT DIV
%token AFF EGAL INF SUP SUPEG INFEG EGALITE DIFFERENT
%token AND OR NOT
%token PVG DP COMMA PO PF AO AF CO CF
%token INTEGER FLOATING STRING IDF

%type <str> IDF STRING
%type <integer> INTEGER
%type <real> FLOATING
%type <real> value

%type <real> expression
%type <str> var_list
%type <str> affectation
%type <str> lecture
%type <str> ecriture
%type <str> declaration
%type <str> boucle
%type <str> type
%type <str> conditions



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

declaration: LET var_list DP type PVG { 
    printf("PARSER: Variable declaration of type %s.\n", $4);
    
    char* token = strtok($2, ",");
    while(token != NULL) {

        verifierDoubleDeclaration(token, $4); 

        Rechercher(token, "IDF", $4, "", 1);  // Update type for each variable
        token = strtok(NULL, ",");
    }
}
| LET var_list DP CO type PVG INTEGER CF PVG { 
    printf("PARSER: Array declaration of type %s.\n", $5);
    
    char arrayType[20];
    sprintf(arrayType, "%s[]", $5);  // Append [] to the type
    
    char* token = strtok($2, ",");
    while(token != NULL) {

        verifierDoubleDeclaration(token, arrayType);

        Rechercher(token, "IDF", arrayType, "", 1);  // Update type for each array variable
        token = strtok(NULL, ",");
    }
    }
| DEFINE CONST IDF DP type EGAL value PVG { 
    printf("%d\n", $3);
    printf("PARSER: Constant definition: %s\n", $3);

    char valStr[20];
    if (valType == 0) {  // Integer
        sprintf(valStr, "%d", intValue);
    } else if (valType == 1) {  // Float
        sprintf(valStr, "%f", floatValue);
    } else if (valType == 2) {  // String
        strcpy(valStr, strValue);  // Copy string value
    } 

    verifierDoubleDeclaration($3, $5);

    Rechercher($3, "CONST", $5, valStr, 1);  // Store constant with type and value
};



var_list: IDF { 
    printf("PARSER: Variable: %s\n", $1);
    Rechercher($1, "IDF", "", "", 1);  // Insert the variable immediately
    $$ = $1; // Pass the variable name up
}
| var_list COMMA IDF { 
    printf("PARSER: Variable list extended: %s\n", $3);
    Rechercher($3, "IDF", "", "", 1);  // Insert the additional variable
    $$ = malloc(strlen($1) + strlen($3) + 2);
    strcpy($$, $1);
    strcat($$, ",");
    strcat($$, $3);
}
;

type: INT { $$ = "int"; printf("PARSER: Type: Integer.\n"); }
    | FLOAT { $$ = "float"; printf("PARSER: Type: Float.\n"); };

value: INTEGER { 
    valType = 0;  // Integer type
    intValue = $1;  // Store integer value
}
| FLOATING { 
    valType = 1;  // Float type
    floatValue = $1;  // Store float value
}
| STRING { 
    valType = 2;  // String type
    strValue = malloc(strlen($1) + 1);  // Allocate memory for string
};


instructions: instruction { printf("PARSER: Single instruction processed.\n"); }
            | instructions instruction { printf("PARSER: Multiple instructions processed.\n"); };

instruction: affectation { printf("PARSER: Affectation processed.\n"); }
           | condition { printf("PARSER: Condition processed.\n"); }
           | boucle { printf("PARSER: Loop processed.\n"); }
           | lecture { printf("PARSER: Input instruction processed.\n"); }
           | ecriture { printf("PARSER: Output instruction processed.\n"); };

affectation: IDF AFF expression PVG { printf("PARSER: Assignment to variable: %s\n", $1);

  // Add semantic checks
    verifierDeclaration($1); // Check if variable is declared
    verifierConstanteModification($1); // Check if trying to modify a constant


    char valStr[20];  // Buffer for value conversion
    if (valType == 0) {  // Integer
        sprintf(valStr, "%d", intValue);
    } else if (valType == 1) {  // Float
        sprintf(valStr, "%f", floatValue);
    } else if (valType == 2) {  // String
        strcpy(valStr, strValue);  // Copy string value
    } 

    Rechercher($1, "IDF", "", valStr, 1);  // Store computed value
    
    printf(">> Updated value of %s to %s\n", $1, valStr);
    }
           | IDF CO expression CF AFF expression PVG { printf("PARSER: Array assignment.\n"); 
            // Add semantic checks
    verifierDeclaration($1); // Check if array is declared
    verifierConstanteModification($1); // Check if trying to modify a constant
    }

condition: IF PO conditions PF THEN AO instructions AF ELSE AO instructions AF {printf("PARSER: If-Else condition processed.\n");}
        | IF PO conditions PF THEN AO instructions AF { printf("PARSER: If condition processed.\n"); };

boucle: DO AO instructions AF WHILE PO conditions PF PVG { printf("PARSER: Do-While loop processed.\n"); }
      | FOR IDF FROM expression TO expression STEP expression AO instructions AF {
          printf("PARSER: For loop with variable: %s\n", $2);
     
    verifierDeclaration($2);

     };


lecture: INPUT PO IDF PF PVG { printf("PARSER: Input received into variable: %s\n", $3);

    verifierDeclaration($3);
    verifierConstanteModification($3);

  };

ecriture: OUTPUT PO STRING COMMA IDF PF PVG { printf("PARSER: Outputting: %s with variable: %s\n", $3, $5);
    verifierDeclaration($5);
}

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

expression: value { $$ = $1; }
          | IDF { 

             verifierDeclaration($1);

              char *valStr;
              valStr = get_value($1);
              printf("amine %s: %s\n", $1, valStr);
              $$ = atof(valStr);
              printf("amine 222 %f\n",  $$); 
          }  // Retrieve value from TS
          | expression PLUS expression { $$ = $1 + $3; }
          | expression MINUS expression { $$ = $1 - $3; }
          | expression MULT expression { $$ = $1 * $3; }
          | expression DIV expression { 
               // Add semantic check for division by zero
                char operand[50];
                printf("amine 000  %f\n", $3);
                sprintf(operand,"%f", $3);  // Copy the divisor
                printf("amine 111  %s\n", operand);
                verifierDivisionParZero(operand);  // Check if divisor is zero
                $$ = $1 / $3;  
          }
          
          | PO expression PF { $$ = $2; };
          | IDF CO expression CF { printf("PARSER: Array expression.\n"); 

           verifierDeclaration($1);
           
           }
%%

int main() {
    printf("Debut de l'analyse syntaxique...\n");
    initialization();
    yyparse();
    afficher();
    printf("Fin de l'analyse syntaxique.\n");
    return 0;
}

void yyerror(const char* msg) {
    printf("Erreur Syntaxique a la ligne %d : %s\n", nb_ligne, msg);
}