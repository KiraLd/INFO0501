#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



cellule* creerCellule(char* m)
{
    cellule* c = (cellule*) malloc( sizeof(cellule) );
    c->mot = (char*) malloc( sizeof(char) * TAILLE_MAX );
    strcpy(c->mot, m);
    c->prev = NULL;
    c->next = NULL;
    return c;
}

void detruireCellule(cellule** c)
{
    if(c[0] != NULL)
    {
        if(c[0]->mot != NULL)
        {
            free(c[0]->mot);
            if(c[0]->n != NULL)
            {
                free(c[0]->n);
            }
        }
        free(c[0]);
    }


}
