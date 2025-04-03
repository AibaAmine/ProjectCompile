#include <stdio.h>
#include <string.h>
// nrdohom list chaine
typedef struct
{
    int state;
    char name[20];
    char code[20];
    char type[20];
    char val[20];
} TypeTS;

TypeTS TS[200];

typedef struct
{
    int state;
    char nomEntite[20];
    char Code[20];
} TypeSM;

TypeSM tabS[50], tabM[50];

void initialization()
{
    int i;
    // Initialize symbol tables
    for (i = 0; i < 200; i++)
    {
        TS[i].state = 0;
    }
    for (i = 0; i < 50; i++)
    {
        tabS[i].state = 0;
        tabM[i].state = 0;
    }
}

void inserer(char entite[], char code[], char type[], char val[], int pos, int table)
{
    switch (table)
    {
    case 1: // Identifiers & Constants Table
        TS[pos].state = 1;
        strcpy(TS[pos].name, entite);
        strcpy(TS[pos].code, code);
        strcpy(TS[pos].type, type);
        strcpy(TS[pos].val, val);
        break;
    case 2: // Keywords Table
        tabM[pos].state = 1;
        strcpy(tabM[pos].nomEntite, entite);
        strcpy(tabM[pos].Code, code);
        break;
    case 3: // Separators Table
        tabS[pos].state = 1;
        strcpy(tabS[pos].nomEntite, entite);
        strcpy(tabS[pos].Code, code);
        break;
    }
}
void Rechercher(char entite[], char code[], char type[], char val[], int y)
{
    int i;
    switch (y)
    {
    case 1: // Identifiers & Constants Table
        for (i = 0; i < 200; i++)
        {
            if (TS[i].state == 1 && strcmp(entite, TS[i].name) == 0)
            {
                // Identifier already exists, update type & value if needed
                if (strcmp(type, "") != 0 && strcmp(TS[i].type, type) != 0)
                {
                    strcpy(TS[i].type, type);
                    printf(">> Updated type of %s to %s\n", entite, type);
                }
                if (strcmp(val, "") != 0 && strcmp(TS[i].val, val) != 0)
                {
                    strcpy(TS[i].val, val);
                    printf(">> Updated value of %s to %s\n", entite, val);
                }
                return; // Stop searching once updated
            }
            if (TS[i].state == 0)
            { // Empty slot found, break to insert
                break;
            }
        }
        // Insert if the identifier does not already exist
        if (i < 200)
        {
            inserer(entite, code, type, val, i, 1);
            printf(">> Inserted new identifier: %s\n", entite);
        }
        else
        {
            printf(">> Error: Symbol table is full!\n");
        }
        break;

    case 2: // Keywords Table
        for (i = 0; i < 50 && tabM[i].state == 1 && strcmp(entite, tabM[i].nomEntite) != 0; i++)
            ;
        if (i < 50 && strcmp(entite, tabM[i].nomEntite) != 0)
        {
            inserer(entite, code, type, val, i, 2);
        }
        else
        {
            //printf(">>>> L'entite %s existe deja\n", entite);
        }
        break;

    case 3: // Separators Table
        for (i = 0; i < 50 && tabS[i].state == 1 && strcmp(entite, tabS[i].nomEntite) != 0; i++)
            ;
        if (i < 50 && strcmp(entite, tabS[i].nomEntite) != 0)
        {
            inserer(entite, code, type, val, i, 3);
        }
        else
        {
            //printf(">>>> L'entite %s existe deja\n", entite);
        }
        break;
    }
}

void get_value(char *name, char *result)
{
    for (int i = 0; i < 200; i++)
    {
        if (TS[i].state == 1 && strcmp(TS[i].name, name) == 0)
        {
            strcpy(result, TS[i].val); // Copy stored value
            return;
        }
    }
    strcpy(result, "0"); // Default value if not found
}

// case 1: // Identifiers & Constants Table
//             for (i = 0; i < 200 && TS[i].state == 1 && strcmp(entite, TS[i].name) != 0; i++);
//             if (i < 200 && strcmp(entite, TS[i].name) != 0) {
//                 inserer(entite, code, type, val, i, 1);
//             } else {
//                 printf(">>>> L'entite %s existe deja\n", entite);
//             }
//             break;

void afficher()
{
    int i;

    printf("/*************** Table des symboles IDF ***************/\n");
    printf("_____________________________________________________________________\n");
    printf("| Nom_Entite  | Code_Entite  | Type_Entite   | Val_Entite    |\n");
    printf("_____________________________________________________________________\n");

    for (i = 0; i < 200; i++)
    {
        if (TS[i].state == 1)
        {
            printf("|%12s |%12s |%12s |%12s |\n", TS[i].name, TS[i].code, TS[i].type, TS[i].val);
        }
    }

    printf("\n/*************** Table des symboles mots clés ***************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite  | CodeEntite  |\n");
    printf("_____________________________________\n");

    for (i = 0; i < 50; i++)
    {
        if (tabM[i].state == 1)
        {
            printf("|%12s |%12s |\n", tabM[i].nomEntite, tabM[i].Code);
        }
    }

    printf("\n/*************** Table des symboles séparateurs ***************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite  | CodeEntite  |\n");
    printf("_____________________________________\n");

    for (i = 0; i < 50; i++)
    {
        if (tabS[i].state == 1)
        {
            printf("|%12s |%12s |\n", tabS[i].nomEntite, tabS[i].Code);
        }
    }
}


// Check if a variable is already declared with a type
void verifierDoubleDeclaration(char *idf, char *type)
{
    for (int i = 0; i < 200; i++)
    {
        if (TS[i].state == 1 && strcmp(TS[i].name, idf) == 0)
        {
            // If the type is not empty, it's already declared
            if (strcmp(TS[i].type, "") != 0)
            {
                printf("Erreur sémantique: Double déclaration de la variable '%s'\n", idf);
                return;
            }
        }
    }
    // Not a double declaration, proceed with the type assignment
}

// Verify if a variable has been declared before use
void verifierDeclaration(char *idf)
{
    int found = 0;
    for (int i = 0; i < 200; i++)
    {
        if (TS[i].state == 1 && strcmp(TS[i].name, idf) == 0)
        {
            // Check if the type is assigned (meaning it's declared)
            if (strcmp(TS[i].type, "") != 0)
            {
                found = 1;
                break;
            }
        }
    }

    if (!found)
    {
        printf("Erreur sémantique: Variable '%s' non déclarée\n", idf);
    }
}

// Get the type of an identifier
char *getType(char *idf)
{
    static char type[20]; // Static to ensure it persists after function returns

    for (int i = 0; i < 200; i++)
    {
        if (TS[i].state == 1 && strcmp(TS[i].name, idf) == 0)
        {
            strcpy(type, TS[i].type);
            return type;
        }
    }

    strcpy(type, "");
    return type;
}

// Check if an identifier is a constant
int isConstant(char *idf)
{
    for (int i = 0; i < 200; i++)
    {
        if (TS[i].state == 1 && strcmp(TS[i].name, idf) == 0)
        {
            if (strcmp(TS[i].code, "CONST") == 0)
            {
                return 1; // It is a constant
            }
            return 0; // It's a variable, not a constant
        }
    }
    return 0; // Not found, assume not a constant
}


// Check if a string represents a numeric value
int isNumeric(char *val)
{
    char *endptr;
    strtod(val, &endptr);
    // If endptr is at the end of the string, the entire string is numeric
    return (*endptr == '\0');
}

// Verify that a constant is not being modified
void verifierConstanteModification(char *idf)
{
    if (isConstant(idf))
    {
        printf("Erreur sémantique: Tentative de modification de la constante '%s'\n", idf);
    }
}

// Check for division by zero
void verifierDivisionParZero(char *operand)
{
    // If operand is a numeric literal
    if (isNumeric(operand) && atof(operand) == 0)
    {
        printf("Erreur sémantique: Division par zéro\n");
    }
    // If operand is a variable or constant, check its value
    else
    {
        for (int i = 0; i < 200; i++)
        {
            if (TS[i].state == 1 && strcmp(TS[i].name, operand) == 0)
            {
                if (strcmp(TS[i].val, "0") == 0)
                {
                    printf("Erreur sémantique: Division par zéro (variable '%s' vaut 0)\n", operand);
                }
                break;
            }
        }
    }
}

// Verify type compatibility between two identifiers
void verifierTypeCompatible(char *idf1, char *idf2, char op)
{
    char *type1 = getType(idf1);
    char *type2 = getType(idf2);

    // Skip check if either is not declared
    if (strcmp(type1, "") == 0 || strcmp(type2, "") == 0)
    {
        return;
    }

    // Check for array types
    int isArray1 = (strstr(type1, "[]") != NULL);
    int isArray2 = (strstr(type2, "[]") != NULL);

    // Arrays have special handling - incompatible with regular types
    if (isArray1 != isArray2)
    {
        printf("Erreur sémantique: Incompatibilité de type entre '%s' (%s) et '%s' (%s)\n",
               idf1, type1, idf2, type2);
        return;
    }

    // For simple numeric types
    if (strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0)
    {
        if (op == '=')
        {
            printf("Attention: Conversion implicite de float à int pour '%s' := '%s'\n", idf1, idf2);
        }
    }
    else if (strcmp(type1, "float") == 0 && strcmp(type2, "int") == 0)
    {
        // This is generally safe, no warning needed
    }
    else if (strcmp(type1, type2) != 0)
    {
        printf("Erreur sémantique: Incompatibilité de type entre '%s' (%s) et '%s' (%s)\n",
               idf1, type1, idf2, type2);
    }
}

// Check assignment operation for semantic correctness
void verifierAffectation(char *idf_left, char *idf_right_or_val, int is_const)
{
    // First check if the left side is a declared variable
    verifierDeclaration(idf_left);

    // Check if trying to modify a constant
    verifierConstanteModification(idf_left);

    // If right side is a variable (not a constant value)
    if (!is_const)
    {
        verifierDeclaration(idf_right_or_val);
        verifierTypeCompatible(idf_left, idf_right_or_val, '=');
    }
    // If right side is a constant value, ensure it's compatible with left side type
    else
    {
        char *left_type = getType(idf_left);

        // Skip if left side not declared
        if (strcmp(left_type, "") == 0)
        {
            return;
        }

        // Type check for constant assignment
        if (strcmp(left_type, "int") == 0)
        {
            // Check if the value is a valid integer
            char *endptr;
            strtol(idf_right_or_val, &endptr, 10);
            if (*endptr != '\0')
            {
                printf("Erreur sémantique: Valeur '%s' incompatible avec le type 'int' de '%s'\n",
                       idf_right_or_val, idf_left);
            }
        }
        else if (strcmp(left_type, "float") == 0)
        {
            // Both int and float values are acceptable for float variables
            if (!isNumeric(idf_right_or_val))
            {
                printf("Erreur sémantique: Valeur '%s' incompatible avec le type 'float' de '%s'\n",
                       idf_right_or_val, idf_left);
            }
        }
    }
}