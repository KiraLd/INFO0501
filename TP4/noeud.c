#include "noeud.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

noeud* creerNoeud(char* m)
{
    noeud* n =(noeud*) malloc(sizeof(noeud));
    n->pere=NULL;
    n->gauche=NULL;
    n->droit=NULL;
    n->mot = (char*) malloc(sizeof(char)*50);
    strcpy(n->mot,m);
    n->occurrence = 1;
    return n;
}

void detruireNoeud(noeud** n)
{
    if(n[0] != NULL)
    {
        if(n[0]->mot!=NULL)
        {
            free(n[0]->mot);
        }
    }

}
