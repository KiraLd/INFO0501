#include "pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

pile* creerPile()
{
    pile* p = (pile*)malloc(sizeof(pile));
    p->l = creerListe();
    return p;
}

void detruirePile(pile** p)
{
    if(p[0] != NULL)
    {
        detruireListe(&p[0]->l);
        free(p[0]);
    }
}

int pileVide(pile* p)
{
    return p->l->tete == NULL;
}

void empiler(pile* p,noeud* n)
{
    cellule* c = creerCellule(n->mot);
    c->n = n;
    inserer(p->l, c);
}

noeud* depiler(pile* p)
{
    cellule* c = p->l->tete;
    noeud* n = c->n;
    supprimerCellule(p->l,c);
    return n;

}

noeud* sommet(pile* p)
{
    return p->l->tete->n;
}



