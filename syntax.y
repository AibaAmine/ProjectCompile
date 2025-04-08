
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>


char *get_value(char* name);  // Declare get_value
void Rechercher(char entite[], char code[], char type[], char val[], int y);
void inserer(char entite[], char code[], char type[], char val[], int y);
void initialization();
void afficher();

bool is_integer(char *str);

bool is_float(char *str);
void verifierDoubleDeclaration(char* idf, char* type);
void verifierDeclaration(char* idf);
void verifierAffectation(char* idf_left, char* idf_right_or_val, int is_const);
void verifierTypeCompatible(char* idf1, char* idf2, char op);
int verifierConstanteModification(char* idf);
int isNumeric(char* val);
char* getType(char* idf);
int isConstant(char* idf);
int expression_error = 0;
int idf_error = 0;

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
%left PF
%right PO

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
    printf("PARSER: Constant definition: %s\n", $3);
    char valStr[20];
    strcpy(valStr, "vide");

    char strval[20];
    sprintf(strval, "%f", $7);  // Convert value to string for checking
    printf("sfmljqdfmqj: Value string: %s\n", strval);
    if (strcmp($5, "float") == 0) {
        if (is_float(strval) || is_integer(strval)) {  // Accept integers as valid floats
            sprintf(valStr, "%f", $7);  
        } else {
            printf("ERROR: Value '%s' is not a valid float.\n", strval);
        }
    } else if (strcmp($5, "int") == 0) {
        if (is_integer(strval)) {
            sprintf(valStr, "%d", (int)$7);
        } else {
            printf("ERROR: Value '%s' is not a valid integer.\n", strval);
        }
    } else {
        printf("ERROR: Unknown type for constant.\n");
    }

    verifierDoubleDeclaration($3, $5);
    Rechercher($3, "CONST", $5, valStr, 1);
}


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
    // valType = 0;  // Integer type
    // intValue = $1;  // Store integer value
    $$ = (float)$1;  // Store integer value
}
| FLOATING { 
    // valType = 1;  // Float type
    // floatValue = $1;  // Store float value
    $$ = $1;  // Store float value
}
| STRING { 
    // valType = 2;  // String type
    // strValue = malloc(strlen($1) + 1);  // Allocate memory for string
};


instructions: instruction {printf("PARSER: Single instruction processed.\n");
      }
            | instructions instruction { printf("PARSER: Multiple instructions processed.\n"); };

instruction: affectation { printf("PARSER: Affectation processed.\n"); }
           | condition { printf("PARSER: Condition processed.\n"); }
           | boucle { printf("PARSER: Loop processed.\n"); }
           | lecture { printf("PARSER: Input instruction processed.\n"); }
           | ecriture { printf("PARSER: Output instruction processed.\n"); };

affectation:
    IDF AFF expression PVG {
        printf("PARSER: Assignment to variable: %s\n", $1);

        verifierDeclaration($1);
        char vide[64];
        sprintf(vide, "%f", $3);  // Convert expression result to string for type checking
        if (verifierConstanteModification($1) == 0) {
            if (expression_error) {
                printf("PARSER: Assignment ignored due to invalid expression (e.g., division by zero).\n");
                expression_error = 0;  // Reset for the next statement
            } else if(idf_error) {
                printf("PARSER: Assignment ignored due to invalid variable value.\n");
                idf_error = 0;  // Reset for the next statement
            }
            else {
                char strval[64];
                const char *varType = getType($1);

                if (strcmp(varType, "float") == 0) {
                    sprintf(strval, "%f", $3);
                    if (is_float(strval) && !is_integer(strval)) {
                        Rechercher($1, "IDF", "", strval, 1);

                    }else {
                        printf("PARSER: Type mismatch (expected float or integer convertible to float).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else if (strcmp(varType, "int") == 0) {
                    sprintf(strval, "%f", $3);
                    if (is_integer(strval)) {
                        sprintf(strval, "%d", (int)$3);
                        Rechercher($1, "IDF", "", strval, 1);

                    } else {
                        printf("PARSER: Type mismatch (expected integer).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else {
                    printf("PARSER: Unknown type for variable %s.\n", $1);
                }
            }
        }
        expression_error = 0;  // Reset after processing
        idf_error = 0;  // Reset after processing
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
          | expression INF expression { printf("PARSER: Less than condition processed.\n");
          idf_error = 0;  // Reset for the next statement
           }
          | expression SUP expression { printf("PARSER: Greater than condition processed.\n"); }
          | expression SUPEG expression { printf("PARSER: Greater than or equal condition processed.\n"); }
          | expression INFEG expression { printf("PARSER: Less than or equal condition processed.\n"); }
          | expression EGALITE expression { printf("PARSER: Exact equality condition processed.\n"); }
          | expression DIFFERENT expression { printf("PARSER: Not equal condition processed.\n"); }
          | NOT conditions { printf("PARSER: NOT condition processed.\n"); };

expression: value { $$ = $1; }
          | IDF { 

             verifierDeclaration($1);
             printf("lebgaa: Variable used: %s\n", $1);
            char *value = get_value($1); // Retrieve the value as a string
            printf("abdou: Variable value retrieved: %s\n", value);
            if (value == NULL || strcmp(value, "") == 0) {
                printf("Error: Variable %s not initialized.\n", $1);
                idf_error = 1;
                $$ =0;  // Mark the variable as undeclared
            } else {
                // Check if the value is an integer or float
                printf("Variable value: %s\n", value);
            }
            if (is_integer(value)) {
                // Handle integer
                int result = atoi(value); // Convert string to integer
                $$ = result;
                printf("Integer value: %d\n", result);
            } else if (is_float(value)) {
                // Handle float
                float result = atof(value); // Convert string to float
                $$ = result;
                printf("Float value: %.2f\n", result);
            }
          }  
          | expression PLUS expression { $$ = $1 + $3; printf("PARSER: Addition operation. %f\n",$$); }
          | expression MINUS expression { $$ = $1 - $3; printf("PARSER: Subtraction operation. %f - %f = %f\n",$1,$3,$$); }
          | expression MULT expression { $$ = $1 * $3; printf("PARSER: Multiplication operation. %f\n",$$); }
          | PO expression PF { $$ = $2; printf("PARSER: Parenthesized expression : %f\n", $2);};
          | expression DIV expression { 
                if($3 == 0) {
                    printf("PARSER: Division by zero error.\n");
                    printf("Operation will be ignored.\n");
                    expression_error = 1;  // Mark the expression as invalid
                    $$ = 0;
                } else {
                    $$ = $1 / $3;  
                }
          }
          | IDF CO expression CF { printf("PARSER: Array expression.\n"); 
          char *valStr;
              valStr = get_value($1);
              $$ = atoi(valStr);

           verifierDeclaration($1);
           
           }
%%

int main() {
    printf("Debut de l'analyse syntaxique...\n");
    initialization();
    expression_error = 0; 
    idf_error = 0;
    yyparse();
    afficher();
    printf("Fin de l'analyse syntaxique.\n");
    return 0;
}

void yyerror(const char* msg) {
    printf("Erreur Syntaxique a la ligne %d : %s\n", nb_ligne, msg);
}