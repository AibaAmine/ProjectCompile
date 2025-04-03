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
            printf(">>>> L'entite %s existe deja\n", entite);
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
            printf(">>>> L'entite %s existe deja\n", entite);
        }
        break;
    }
}

void get_value(char* name, char* result) {
    for (int i = 0; i < 200; i++) {
        if (TS[i].state == 1 && strcmp(TS[i].name, name) == 0) {
            strcpy(result, TS[i].val);  // Copy stored value
            return;
        }
    }
    strcpy(result, "0");  // Default value if not found
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