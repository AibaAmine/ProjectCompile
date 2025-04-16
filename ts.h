#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 10000
typedef struct TypeTS
{
    int state;
    char name[20];
    char code[20];
    char type[20];
    char val[20];
    int array_size;
    char val_array[MAX_ARRAY_SIZE][20];
    struct TypeTS *next;
} TypeTS;

typedef struct TypeSM
{
    int state;
    char nomEntite[20];
    char Code[20];
    struct TypeSM *next;
} TypeSM;

TypeTS *TS_head = NULL;
TypeSM *tabM_head = NULL;
TypeSM *tabS_head = NULL;

void initialization()
{
    TS_head = NULL;
    tabM_head = NULL;
    tabS_head = NULL;
}

void inserer(char entite[], char code[], char type[], char val[], int table)
{
    if (table == 1)
    {
        TypeTS *new_node = malloc(sizeof(TypeTS));
        new_node->state = 1;
        strcpy(new_node->name, entite);
        strcpy(new_node->code, code);
        strcpy(new_node->type, type);
        strcpy(new_node->val, val);
        new_node->next = TS_head;
        TS_head = new_node;
        printf("***** Inserted: name=%s, code=%s, type=%s, val=%s\n", entite, code, type, val);
    }
    else
    {
        TypeSM *new_node = malloc(sizeof(TypeSM));
        new_node->state = 1;
        strcpy(new_node->nomEntite, entite);
        strcpy(new_node->Code, code);
        new_node->next = (table == 2) ? tabM_head : tabS_head;

        if (table == 2)
            tabM_head = new_node;
        else
            tabS_head = new_node;
    }
}


void Rechercher(char entite[], char code[], char type[], char val[], int y)
{
    if (y == 1)
    {
        TypeTS *current = TS_head;
        while (current != NULL)
        {
            if (strcmp(current->name, entite) == 0)
            {
                if (strcmp(type, "") != 0 && strcmp(current->type, type) != 0)
                {
                    strcpy(current->type, type);
                    printf(">> Updated type of %s to %s\n", entite, type);
                }
                if (strcmp(val, "") != 0 && strcmp(current->val, val) != 0)
                {
                    strcpy(current->val, val);
                    printf(">> Updated value of %s to %s\n", entite, val);
                }
                return;
            }
            current = current->next;
        }
        
        inserer(entite, code, type, val, 1);
        printf(">> Inserted new identifier: %s\n", entite);
    }
    else
    {
        TypeSM **head = (y == 2) ? &tabM_head : &tabS_head;
        TypeSM *current = *head;
        while (current != NULL)
        {
            if (strcmp(current->nomEntite, entite) == 0)
            return;
            current = current->next;
        }
        inserer(entite, code, "", "", y);
    }
}

bool verifierIdf(char *idf) {
    if (strlen(idf) > 14) {
        printf("Error: Identifier too long: %s\n", idf);
        return 0;
    } else if (strstr(idf, "__") != NULL) {
        printf("Error: Identifier contains '__': %s\n", idf);
        return 0;
    } else if (idf[strlen(idf) - 1] == '_') {
        printf("Error: Identifier ends with '_': %s\n", idf);
        return 0;
    }
    return 1;
}

char *get_value(char *name)
{
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current->val;
        }
        current = current->next;
    }
}

void setArraySize(char *idf, int size)
{
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, idf) == 0)
        {
            current->array_size = size;
            for (int i = 0; i < size; i++)
            {
                strcpy(current->val_array[i], "");
            }
            printf(">> Set %s array_size to %d\n", idf, size);
            return;
        }
        current = current->next;
    }
}

void setArrayElement(char *idf, int index, char *val)
{
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, idf) == 0 && strstr(current->type, "[") != NULL)
        {
            if (current->array_size == 0)
            {
                printf("Error semantique: Array '%s' size not initialized.\n", idf);
                return;
            }
            if (index >= 0 && index < current->array_size)
            {
                strcpy(current->val_array[index], val);
                printf("*********>> Set %s[%d] to %s\n", idf, index, val);
            }
            else
            {
                printf("Error semantique: Index %d out of bounds for '%s' (size %d).\n", index, idf, current->array_size);
            }
            return;
        }
        current = current->next;
    }
    printf("Error semantique: '%s' not found or not an array.\n", idf);
}

bool is_integer(const char *str)
{
    if (!str || !*str)
        return false; 

    
    if (*str == '+' || *str == '-')
        str++;

    bool hasDot = false;
    bool hasNonZeroAfterDot = false;
    bool hasDigitBeforeDot = false;

    while (*str)
    {
        if (isdigit(*str))
        {
            if (!hasDot)
            {
                hasDigitBeforeDot = true; 
            }
            else if (*str != '0')
            {
                hasNonZeroAfterDot = true; 
            }
        }
        else if (*str == '.')
        {
            if (hasDot)
                return false; 
            hasDot = true;
        }
        else
        {
            return false; 
        }
        str++;
    }

    return hasDigitBeforeDot && (!hasDot || !hasNonZeroAfterDot);
}

int is_initialized(char *idf)
{
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, idf) == 0)
        {
            return strcmp(current->val, "") != 0;
        }
        current = current->next;
    }
    return 0; 
}

bool is_float(const char *str) {
    if (*str == '+' || *str == '-') str++;  

    if (!*str)
        return false; 
    bool hasDigit = false;
    bool hasDot = false;

    while (*str)
    {
        if (isdigit(*str))
        {
            hasDigit = true;
        }
        else if (*str == '.')
        {
            if (hasDot)
                return false; 
            hasDot = true;
        }
        else
        {
            return false; 
        }
        str++;
    }

    return hasDot && hasDigit; 
}

void afficher()
{
    printf("/*************** Table des symboles IDF ***************/\n");
    printf("_____________________________________________________________________\n");
    printf("| Nom_Entite  | Code_Entite  | Type_Entite   | Val_Entite    |\n");
    printf("_____________________________________________________________________\n");
    TypeTS *ptrTS = TS_head;
    while (ptrTS)
    {
        printf("|%12s |%12s |%12s |%12s |\n", ptrTS->name, ptrTS->code, ptrTS->type, ptrTS->val);
        if (strstr(ptrTS->type, "[") != NULL && ptrTS->array_size > 0)
        {
            for (int i = 0; i < ptrTS->array_size; i++)
            {
                if (strcmp(ptrTS->val_array[i], "") != 0)
                {
                    printf("|         ->   %s[%d]         |             |%12s |\n", ptrTS->name, i, ptrTS->val_array[i]);
                }
            }
        }
        ptrTS = ptrTS->next;
    }


    printf("\n/*************** Table des symboles mots cles ***************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite  | CodeEntite  |\n");
    printf("_____________________________________\n");

    TypeSM *ptrM = tabM_head;
    while (ptrM)
    {
        printf("|%12s |%12s |\n", ptrM->nomEntite, ptrM->Code);
        ptrM = ptrM->next;
    }

    printf("\n/*************** Table des symboles séparateurs ***************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite  | CodeEntite  |\n");
    printf("_____________________________________\n");

    TypeSM *ptrS = tabS_head;
    while (ptrS)
    {
        printf("|%12s |%12s |\n", ptrS->nomEntite, ptrS->Code);
        ptrS = ptrS->next;
    }
}

void verifierDoubleDeclaration(char *idf, char *type)
{
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, idf) == 0 && strcmp(current->type, "") != 0)
        {
            printf("Error semantique: Double declaration de la variable '%s'\n", idf);
            return;
        }
        current = current->next;
    }
    return;
}

void verifierDeclaration(char *idf)
{
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, idf) == 0 && strcmp(current->type, "") != 0)
            return;
        current = current->next;
    }
    printf("Error semantique: Variable '%s' non declaree\n", idf);
    return;
}

char *getType(char *idf)
{
    static char type[20];
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, idf) == 0)
        {
            strcpy(type, current->type);
            return type;
        }
        current = current->next;
    }
    strcpy(type, "");
    return type;
}

int isConstant(char *idf)
{
    TypeTS *current = TS_head;
    while (current)
    {
        if (strcmp(current->name, idf) == 0)
        {
            if (strcmp(current->code, "CONST") == 0)
            {
                printf(" ***** %s is a constant\n", idf);
                return 1; 
            }
        }
        current = current->next;
    }
    return 0; 
}

int verifierConstanteModification(char *idf)
{
    if (isConstant(idf) == 1)
    {
        printf("Error semantique: Tentative de modification de la constante '%s'\n", idf);
        printf("Operation will be ignored\n");
        return 1;
    }
    return 0;
}

bool verifierTypeCompatibility(char *idf, char *exprValue)
{
    const char *varType = getType(idf);

    if (strncmp(varType, "float", 5) == 0)
    {
        if (is_float(exprValue) || is_integer(exprValue))
        {
            return true;
        }
        else
        {
            printf("Error: Type mismatch for '%s' (expected float or integer convertible to float, got '%s').\n", idf, exprValue);
            printf("Operation will be ignored.\n");
            return false;
        }
    }
    else if (strncmp(varType, "int", 3) == 0)
    {
        if (is_integer(exprValue))
        {
            return true;
        }
        else
        {
            printf("Error: Type mismatch for '%s' (expected integer, got '%s').\n", idf, exprValue);
            printf("Operation will be ignored.\n");
            return false;
        }
    }
    else
    {
        printf("PARSER: Unknown type for variable '%s'.\n", idf);
        return false;
    }
}

void cleanup()
{
    TypeTS *tempTS;
    while (TS_head)
    {
        tempTS = TS_head;
        TS_head = TS_head->next;
        free(tempTS);
    }

    TypeSM *tempSM;
    while (tabM_head)
    {
        tempSM = tabM_head;
        tabM_head = tabM_head->next;
        free(tempSM);
    }

    while (tabS_head)
    {
        tempSM = tabS_head;
        tabS_head = tabS_head->next;
        free(tempSM);
    }
}
