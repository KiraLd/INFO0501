#include "outilsListe.h"
#include <stddef.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void afficherListe(liste* l)
{
    cellule* temp = l->tete;
    while(temp != NULL)
    {
        printf("%s\n", temp->mot);
        temp = temp->next;
    }
    printf("\n");
}

liste* lire(char* f)
{
    FILE* fichier = fopen(f,"r");
    char* temp = (char*) malloc( sizeof(char) * 50 );
    cellule* temp_c = NULL;
    liste* l = creerListe();
    cellule* r = NULL;
    while(fscanf(fichier, "%s", temp) != -1)
    {
        r = rechercher(l, temp);
        if(r == NULL)
        {
            temp_c = creerCellule(temp);
            inserer(l, temp_c);
        }
    }
    return l;
}

int compterListe(liste* l)
{
    if(l->tete == NULL)
    {
        return 0;
    }
    else
    {
        cellule* temp = l->tete;
        int k = 1;
        while(temp->next != NULL)
        {
            temp = temp->next;
            k++;
        }
        return k;
    }
}

int vide(liste* l)
{
    return l->tete == NULL;
}

cellule* tete(liste* l)
{
    return l->tete;
}

cellule* queueListe(liste* l)
{
    return l->tete;
}


