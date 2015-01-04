#include "arbreInter.h"
#include <stdio.h>
#include <stdlib.h>

arbre* creerArbre()
{
    arbre* a = (arbre*) malloc(sizeof(arbre));
    a->racine = NULL;
    return a;
}


void detruireArbre(arbre** a)
{
    if(a[0] != NULL)
    {
        detruireNoeud(&a[0]->racine);
        detruireNoeud(&a[0]->racine->gauche);
        detruireNoeud(&a[0]->racine->droit);
        free(a[0]);
    }
}

int insererNoeud(arbre* a,noeud* n)
{
    noeud* x = a->racine;
    noeud* y = NULL;
    while(x != NULL)
    {
        y = x;
        if(strcmp(n->mot,y->mot)==0)
        {
            y->occurrence++;
            return 0;
        }
        if(strcmp(n->mot,y->mot)<0)
        {
            x = x->gauche;
        }
        else
        {
            x = x->droit;
        }
    }
    if(y == NULL)
    {
        a->racine = n;
    }
    else
    {
        n->pere = y;
        if(strcmp(n->mot,y->mot)<0)
        {
            y->gauche = n;
        }
        else
        {
            y->droit = n;
        }
    }
    return 1;
}

noeud* rechercherNoeud(arbre* a,char* m)
{
    if(a->racine!=NULL)
    {
        return rechercherNoeudIteratif(a->racine,m);
    }
    return NULL;
}

void supprimer(arbre* a,noeud* n)
{
    supprimerNoeud(a,n);
}
