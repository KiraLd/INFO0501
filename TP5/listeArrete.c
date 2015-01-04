#include "listeArrete.h"
#include <stdio.h>
#include <stdlib.h>

listeArrete* creerListeA()
{
    listeArrete* l = (listeArrete*)malloc(sizeof(listeArrete));
    l->deb = NULL;
    l->fin = NULL;
    return l;
}

void insererA(listeArrete* l, arrete* c)
{
    if(l->deb == NULL)
    {
        l->deb = c;
        l->fin = c;
    }
    else
    {
        l->deb->prec = c;
        c->suiv = l->deb;
        c->prec = NULL;
        l->deb = c;
    }
}



void afficherListeA(listeArrete* l)
{
    arrete* temp = l->deb;
    while(temp != NULL)
    {
        afficherArrete(temp);
        temp = temp->suiv;
    }
}

int tailleListeA(listeArrete* l)
{
    int res = 0;
    if(l->deb != NULL)
    {
        res++;
        arrete* temp = l->deb->suiv;
        while(temp != NULL)
        {
            res++;
            temp = temp->suiv;
        }
    }
    return res;
}

void detruireListePartielleA(listeArrete** l)
{
    if(*l != NULL)
    {
        arrete* temp = (*l)->deb;
        arrete* temp2 = NULL;
        while(temp != NULL)
        {
            temp2 = temp;
            temp = temp->suiv;
            detruireArrete(&temp2);
        }
        free(*l);
        *l = NULL;
    }
}


int sommeArrete(listeArrete* la)
{
    int somme = 0;
    arrete* a = la->deb;
    while(a != NULL)
    {
        somme += a->p;
        a = a->suiv;
    }
    return somme;
}
