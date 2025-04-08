#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TypeTS {
    int state;
    char name[20];
    char code[20];
    char type[20];
    char val[20];
    struct TypeTS *next;
} TypeTS;

typedef struct TypeSM {
    int state;
    char nomEntite[20];
    char Code[20];
    struct TypeSM *next;
} TypeSM;

TypeTS *TS_head = NULL;
TypeSM *tabM_head = NULL;
TypeSM *tabS_head = NULL;

void initialization() {
    TS_head = NULL;
    tabM_head = NULL;
    tabS_head = NULL;
}

void inserer(char entite[], char code[], char type[], char val[], int table) {
    if (table == 1) {
        TypeTS *new_node = malloc(sizeof(TypeTS));
        new_node->state = 1;
        strcpy(new_node->name, entite);
        strcpy(new_node->code, code);
        strcpy(new_node->type, type);
        strcpy(new_node->val, val);
        new_node->next = TS_head;
        TS_head = new_node;
    } else {
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

void Rechercher(char entite[], char code[], char type[], char val[], int y) {
    if (y == 1) {
        TypeTS *current = TS_head;
        while (current != NULL) {
            if (strcmp(current->name, entite) == 0) {
                if (strcmp(type, "") != 0 && strcmp(current->type, type) != 0) {
                    strcpy(current->type, type);
                    printf(">> Updated type of %s to %s\n", entite, type);
                }
                if (strcmp(val, "") != 0 && strcmp(current->val, val) != 0) {
                    strcpy(current->val, val);
                    printf(">> Updated value of %s to %s\n", entite, val);
                }
                return;
            }
            current = current->next;
        }
        inserer(entite, code, type, val, 1);
        printf(">> Inserted new identifier: %s\n", entite);
    } else {
        TypeSM **head = (y == 2) ? &tabM_head : &tabS_head;
        TypeSM *current = *head;
        while (current != NULL) {
            if (strcmp(current->nomEntite, entite) == 0) return;
            current = current->next;
        }
        inserer(entite, code, "", "", y);
    }
}

char *get_value(char *name) {
    TypeTS *current = TS_head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            return current->val;
        }
        current = current->next;
    }
}

void afficher() {
    printf("/*************** Table des symboles IDF ***************/\n");
    printf("_____________________________________________________________________\n");
    printf("| Nom_Entite  | Code_Entite  | Type_Entite   | Val_Entite    |\n");
    printf("_____________________________________________________________________\n");

    TypeTS *ptrTS = TS_head;
    while (ptrTS) {
        printf("|%12s |%12s |%12s |%12s |\n", ptrTS->name, ptrTS->code, ptrTS->type, ptrTS->val);
        ptrTS = ptrTS->next;
    }

    printf("\n/*************** Table des symboles mots clés ***************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite  | CodeEntite  |\n");
    printf("_____________________________________\n");

    TypeSM *ptrM = tabM_head;
    while (ptrM) {
        printf("|%12s |%12s |\n", ptrM->nomEntite, ptrM->Code);
        ptrM = ptrM->next;
    }

    printf("\n/*************** Table des symboles séparateurs ***************/\n");
    printf("_____________________________________\n");
    printf("| NomEntite  | CodeEntite  |\n");
    printf("_____________________________________\n");

    TypeSM *ptrS = tabS_head;
    while (ptrS) {
        printf("|%12s |%12s |\n", ptrS->nomEntite, ptrS->Code);
        ptrS = ptrS->next;
    }
}

void verifierDoubleDeclaration(char *idf, char *type) {
    TypeTS *current = TS_head;
    while (current) {
        if (strcmp(current->name, idf) == 0 && strcmp(current->type, "") != 0) {
            printf("Erreur semantique: Double declaration de la variable '%s'\n", idf);
            exit(1);
        }
        current = current->next;
    }
}

void verifierDeclaration(char *idf) {
    TypeTS *current = TS_head;
    while (current) {
        if (strcmp(current->name, idf) == 0 && strcmp(current->type, "") != 0)
            return;
        current = current->next;
    }
    printf("Erreur semantique: Variable '%s' non declaree\n", idf);
    exit(1);
}

char *getType(char *idf) {
    static char type[20];
    TypeTS *current = TS_head;
    while (current) {
        if (strcmp(current->name, idf) == 0) {
            strcpy(type, current->type);
            return type;
        }
        current = current->next;
    }
    strcpy(type, "");
    return type;
}

int isConstant(char *idf) {
    TypeTS *current = TS_head;
    while (current) {
        if (strcmp(current->name, idf) == 0) {
            if(strcmp(current->code, "CONST" ) == 0 && strcmp(current->val, "") != 0) {
                return 1;
            }
        }
        current = current->next;
    }
    return 0;
}

int isNumeric(char *val) {
    char *endptr;
    strtod(val, &endptr);
    return (*endptr == '\0');
}

void verifierConstanteModification(char *idf) {
    printf("%d\n", isConstant(idf));
    if (isConstant(idf) == 1) {
        printf("Erreur semantique: Tentative de modification de la constante '%s'\n", idf);
        exit(1);      

    }
}


void verifierTypeCompatible(char *idf1, char *idf2, char op) {
    char *type1 = getType(idf1);
    char *type2 = getType(idf2);

    if (strcmp(type1, "") == 0 || strcmp(type2, "") == 0)
        return;

    int isArray1 = (strstr(type1, "[]") != NULL);
    int isArray2 = (strstr(type2, "[]") != NULL);

    if (isArray1 != isArray2) {
        printf("Erreur semantique: Incompatibilite de type entre '%s' (%s) et '%s' (%s)\n",
               idf1, type1, idf2, type2);
        return;
    }

    if (strcmp(type1, "int") == 0 && strcmp(type2, "float") == 0 && op == '=') {
        printf("Attention: Conversion implicite de float a int pour '%s' := '%s'\n", idf1, idf2);
    } else if (!(strcmp(type1, "float") == 0 && strcmp(type2, "int") == 0) && strcmp(type1, type2) != 0) {
        printf("Erreur semantique: Incompatibilite de type entre '%s' (%s) et '%s' (%s)\n",
               idf1, type1, idf2, type2);
    }
}

void verifierAffectation(char *idf_left, char *idf_right_or_val, int is_const) {
    verifierDeclaration(idf_left);
    verifierConstanteModification(idf_left);

    if (!is_const) {
        verifierDeclaration(idf_right_or_val);
        verifierTypeCompatible(idf_left, idf_right_or_val, '=');
    } else {
        char *left_type = getType(idf_left);
        if (strcmp(left_type, "") == 0) return;

        if (strcmp(left_type, "int") == 0) {
            char *endptr;
            strtol(idf_right_or_val, &endptr, 10);
            if (*endptr != '\0') {
                printf("Erreur semantique: Valeur '%s' incompatible avec le type 'int' de '%s'\n",
                       idf_right_or_val, idf_left);
            }
        } else if (strcmp(left_type, "float") == 0) {
            if (!isNumeric(idf_right_or_val)) {
                printf("Erreur semantique: Valeur '%s' incompatible avec le type 'float' de '%s'\n",
                       idf_right_or_val, idf_left);
            }
        }
    }
}

void cleanup() {
    TypeTS *tempTS;
    while (TS_head) {
        tempTS = TS_head;
        TS_head = TS_head->next;
        free(tempTS);
    }

    TypeSM *tempSM;
    while (tabM_head) {
        tempSM = tabM_head;
        tabM_head = tabM_head->next;
        free(tempSM);
    }

    while (tabS_head) {
        tempSM = tabS_head;
        tabS_head = tabS_head->next;
        free(tempSM);
    }
}
