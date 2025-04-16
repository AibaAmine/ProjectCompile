
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
char *getInput();
void setArrayElement(char *idf, int index, char *val);
void setArraySize(char *idf, int size);
bool is_integer(char *str);
int is_initialized(char *idf) ;
bool insererConstante(char *idf, char *type, float value);
bool is_float(char *str);
void verifierDoubleDeclaration(char* idf, char* type);
void verifierDeclaration(char* idf);
void verifierAffectation(char* idf_left, char* idf_right_or_val, int is_const);
bool verifierTypeCompatibility(char *idf, char *exprValue);
int verifierConstanteModification(char* idf);
int isNumeric(char* val);
char* getType(char* idf);
int isConstant(char* idf);
int expression_error = 0;
int idf_error = 0;
int inputVar;
bool verifierIdf(char idf[]);
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
%type <str> comparison
%type <integer> conditions

%left OR
%left AND
%right NOT
%left EGAL INF SUP SUPEG INFEG EGALITE DIFFERENT
%left PLUS MINUS
%left MULT DIV
%right PO PF  

%%

programme: MAINPRGM IDF PVG VAR declarations BEGINPG AO instructions AF ENDPG PVG {
    printf("PARSER: Programme parsed successfully. %s\n", $2);
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
        sprintf(arrayType, "%s[%d]", $5, $7);
        char* token = strtok($2, ",");
        while (token != NULL) {
            verifierDoubleDeclaration(token, arrayType);
            Rechercher(token, "IDF", arrayType, "", 1);
            setArraySize(token, $7);  // Set array_size and init val_array
            token = strtok(NULL, ",");
        }
    };
    
    | DEFINE CONST IDF DP type EGAL value PVG { 
    printf("PARSER: Constant definition: %s\n", $3);
    printf("Birgo :  %d\n", verifierIdf($3));
    if (verifierIdf($3) == 1) {
        printf("Abdou : %s\n", $3);
        verifierDoubleDeclaration($3, $5);
        char strval[64];
        sprintf(strval, "%f", $7); 
        Rechercher($3, "CONST", $5, "", 1);
        if (verifierTypeCompatibility($3, strval)) {

            if (strcmp($5, "int") == 0) {
                sprintf(strval, "%d", (int)$7);  
            }
            Rechercher($3, "CONST", $5, strval, 1); 
        } else {
            printf("Error: Failed to define constant '%s' due to type mismatch.\n", $3);
        
        }
    }
}
    

var_list: IDF { 
    printf("PARSER: Variable: %s\n", $1);
    if(verifierIdf($1) == 1) {
        Rechercher($1, "IDF", "", "", 1);
        $$ = $1;
    }else{
        $$ = "";
    }
}
| var_list COMMA IDF { 
    printf("PARSER: Variable list extended: %s\n", $3);
    if (verifierIdf($3) == 1) {
        Rechercher($3, "IDF", "", "", 1);
        $$ = malloc(strlen($1) + strlen($3) + 2);
        strcpy($$, $1);
        strcat($$, ",");
        strcat($$, $3);
    } else {
        $$ = $1; // Keep the previous list if the new IDF is invalid
        printf("PARSER: Invalid identifier %s ignored.\n", $3);
    }
};

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
        char strval[64];
        sprintf(strval, "%f", $3);  // Convert expression result to string

        if (verifierConstanteModification($1) == 0) {
            if (expression_error) {
                printf("PARSER: Assignment ignored due to invalid expression (e.g., division by zero).\n");
                expression_error = 0;
            } else if (idf_error) {
                printf("PARSER: Assignment ignored due to invalid variable value.\n");
                idf_error = 0;
            } else if (verifierTypeCompatibility($1, strval)) {
                // Adjust value format based on type
                const char *varType = getType($1);

                if (strcmp(varType, "float") == 0) {
                    sprintf(strval, "%f", $3);
                    if (is_float(strval) || is_integer(strval)) {
                        Rechercher($1, "IDF", "", strval, 1);

                    }else {
                        printf("Error: Type mismatch (expected float or integer convertible to float).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else if (strcmp(varType, "int") == 0) {
                    sprintf(strval, "%f", $3);
                    if (is_integer(strval)) {
                        sprintf(strval, "%d", (int)$3);
                        Rechercher($1, "IDF", "", strval, 1);

                    } else {
                        printf("Error: Type mismatch (expected integer).\n");
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

           | IDF CO expression CF AFF expression PVG {
    printf("PARSER: Assignment to array variable: %s\n", $1);
    verifierDeclaration($1);
    if (verifierConstanteModification($1) == 0) {
        char strval[64];
        sprintf(strval, "%f", $6);
        const char *varType = getType($1);
        if (strstr(varType, "[") == NULL) {
            printf("Erreur semantique: '%s' is not an array.\n", $1);
        } else if (expression_error) {
            printf("PARSER: Assignment ignored due to invalid expression\n");
        } else if (idf_error) {
            printf("PARSER: Assignment ignored due to invalid variable value.\n");
        } else if (verifierTypeCompatibility($1, strval)) {
            int index = (int)$3;
            if (strncmp(varType, "int", 3) == 0) {
                sprintf(strval, "%d", (int)$6);
            }
            setArrayElement($1, index, strval);
        }
    }
    expression_error = 0;
    idf_error = 0;
}

expression: value { 
        $$ = $1; 
    }
  | IDF { 
        verifierDeclaration($1);
        char *value = get_value($1);
        if (is_initialized($1) == 0) {
            printf("Error: Variable %s not initialized.\n", $1);
            idf_error = 1;
            $$ = 0;
        }
        if (is_integer(value)) {
            int result = atoi(value);
            $$ = result;
            printf("Integer value: %d\n", result);
        } else if (is_float(value)) {
            float result = atof(value);
            $$ = result;
            printf("Float value: %.2f\n", result);
        }
    }  
  | expression PLUS expression { 
        $$ = $1 + $3; 
        printf("PARSER: Addition operation. %f\n", $$); 
    }
  | expression MINUS expression { 
        $$ = $1 - $3; 
        printf("PARSER: Subtraction operation. %f - %f = %f\n", $1, $3, $$); 
    }
  | expression MULT expression { 
        $$ = $1 * $3; 
        printf("PARSER: Multiplication operation. %f\n", $$); 
    }
  | expression DIV expression { 
        if ($3 == 0) {
            printf("PARSER: Division by zero error.\n");
            printf("Operation will be ignored.\n");
            expression_error = 1;  // Mark the expression as invalid
            $$ = 0;
        } else {
            $$ = $1 / $3;  
        }
    }
  | PO expression PF { 
        $$ = $2; 
        printf("PARSER: Parenthesized expression : %f\n", $2); 
    }
  | IDF CO expression CF { 
        printf("PARSER: Array expression.\n"); 
        char *valStr;
        valStr = get_value($1);
        $$ = atoi(valStr);
        verifierDeclaration($1);
    }
condition: IF PO conditions PF THEN AO instructions AF ELSE AO instructions AF {printf("PARSER: If-Else condition processed.\n");
    if ($3 == 1) {
        printf("PARSER: If condition is true.\n");
    } else {
        printf("PARSER: If condition is false.\n");
    }
}
        | IF PO conditions PF THEN AO instructions AF { printf("PARSER: If condition processed.\n"); 
        if ($3 == 1) {
        printf("PARSER: If condition is true.\n");
        } else {
            printf("PARSER: If condition is false.\n");
        }
        };

boucle: DO AO instructions AF WHILE PO conditions PF PVG { printf("PARSER: Do-While loop processed.\n"); }
      | FOR IDF FROM expression TO expression STEP expression AO instructions AF {
          printf("PARSER: For loop with variable: %s\n", $2);
          verifierDeclaration($2);
        char strval[64];
        sprintf(strval, "%f", $4);  // Convert expression result to string

        if (verifierConstanteModification($2) == 0) {
           if (idf_error) {
                printf("PARSER: Assignment ignored due to invalid variable value.\n");
                idf_error = 0;
            } else if (verifierTypeCompatibility($2, strval)) {
                // Adjust value format based on type
                const char *varType = getType($2);

                if (strcmp(varType, "float") == 0) {
                    sprintf(strval, "%f", $4);
                    if (is_float(strval) || is_integer(strval)) {
                        Rechercher($2, "IDF", "", strval, 1);

                    }else {
                        printf("Error: Type mismatch (expected float or integer convertible to float).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else if (strcmp(varType, "int") == 0) {
                    sprintf(strval, "%f", $4);
                    if (is_integer(strval)) {
                        sprintf(strval, "%d", (int)$4);
                        Rechercher($2, "IDF", "", strval, 1);

                    } else {
                        printf("Error: Type mismatch (expected integer).\n");
                        printf("Operation will be ignored.\n");
                    }
                } else {
                    printf("PARSER: Unknown type for variable %s.\n", $2);
                }
            }
        }
        expression_error = 0;  // Reset after processing
        idf_error = 0;  // Reset after processing
     };
lecture: INPUT PO IDF PF PVG { printf("PARSER: Input received into variable: %s\n", $3);

    verifierDeclaration($3);
    verifierConstanteModification($3);

  };

ecriture: OUTPUT PO STRING COMMA IDF PF PVG { printf("PARSER: Outputting: %s with variable: %s\n", $3, $5);
    verifierDeclaration($5);
}

        | OUTPUT PO STRING PF PVG { printf("PARSER: Outputting: %s\n", $3); };


conditions: expression comparison expression {
        if (idf_error == 1) {
            printf("Error semantique: Variable non initialisee dans la condition\n");
            idf_error = 0;
            $$ = 0;  
        } else {
            if (strcmp($2, "SUP") == 0) {
                $$ = ($1 > $3) ? 1 : 0;
            } else if (strcmp($2, "INF") == 0) {
                $$ = ($1 < $3) ? 1 : 0;
            } else if (strcmp($2, "EGALITE") == 0) {
                $$ = (($1 - $3) < 0) ? 1 : 0; 
            } else if (strcmp($2, "SUPEG") == 0) {
                $$ = ($1 >= $3 ) ? 1 : 0; 
            } else if (strcmp($2, "INFEG") == 0) {
                $$ = ($1 <= $3) ? 1 : 0;  
            } else if (strcmp($2, "DIFFERENT") == 0) {
                $$ = (($1 - $3) >= 0) ? 1 : 0;  
            } else {
                $$ = 0;  
            }
            printf("PARSER: Comparison condition processed: %s, result = %d\n", $2, $$);
        }
    }
  | conditions OR conditions {
        $$ = ($1 || $3) ? 1 : 0;
        printf("PARSER: OR condition processed, result = %d\n", $$);
    }
  | conditions AND conditions {
        $$ = ($1 && $3) ? 1 : 0;
        printf("PARSER: AND condition processed, result = %d\n", $$);
    }
  | PO conditions PF {
        $$ = $2;
        printf("PARSER: Parenthesized condition processed, result = %d\n", $$);
    }
  | NOT PO conditions PF {
        $$ = ($3 == 0) ? 1 : 0;
        printf("PARSER: NOT condition processed, result = %d\n", $$);
    }
;

/* Comparison rule */
comparison: SUP {
        $$ = "SUP";
        printf("PARSER: Greater than condition processed.\n");
    }
  | INF {
        $$ = "INF";
        printf("PARSER: Less than condition processed.\n");
    }
  | EGALITE {
        $$ = "EGALITE";
        printf("PARSER: Equality condition processed.\n");
    }
  | SUPEG {
        $$ = "SUPEG";
        printf("PARSER: Greater than or equal condition processed.\n");
    }
  | INFEG {
        $$ = "INFEG";
        printf("PARSER: Less than or equal condition processed.\n");
    }
  | DIFFERENT {
        $$ = "DIFFERENT";
        printf("PARSER: Not equal condition processed.\n");
    }
;    
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
    printf("Error Syntaxique a la ligne %d : %s\n", nb_ligne, msg);
}