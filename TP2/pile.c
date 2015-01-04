#include "pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

pile* creerPile(int n)
{
    pile* p = (pile*) malloc(sizeof(pile));
    p->t = (int*)malloc(sizeof(int)*n);
    p->capacite = n;
    p->taille = 0;
    return p;
}

void detruirePile(pile* p)
{
    if(p->t!=NULL)
    {
        free(p->t);
    }
}

int capacitePile(pile* p)
{
    return p->capacite;
}

int pileVide(pile* p)
{
    return p->taille == 0;
}

int pilePleine(pile* p)
{
    return p->capacite == p->taille;
}

void empiler(pile* p,int a)
{
    if(!pilePleine(p))
    {
        p->t[p->taille] = a;
        p->taille++;
    }
}

int depiler(pile* p)
{
    if(!pileVide(p))
    {
        p->taille--;
        return p->t[p->taille];
    }
    else
    {
        return INT_MAX;
    }

}

int sommet(pile* p)
{
    if(!pileVide(p))
    {
        return p->t[p->taille - 1];
    }
    else
    {
        return INT_MAX;
    }

}



int taillePile(pile* p)
{
    return p->taille;
}


