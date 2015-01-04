#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

liste* creerListe()
{
    liste* l = (liste*)malloc(sizeof(liste));
    l->deb = NULL;
    l->fin = NULL;
    return l;
}

void inserer(liste* l, cellule* c)
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



void afficherListe(liste* l)
{
    cellule* temp = l->deb;
    while(temp != NULL)
    {
        afficherCellule(temp);
        temp = temp->suiv;
    }
}

int tailleListe(liste* l)
{
    int res = 0;
    if(l->deb != NULL)
    {
        res++;
        cellule* temp = l->deb->suiv;
        while(temp != NULL)
        {
            res++;
            temp = temp->suiv;
        }
    }
    return res;
}

void detruireListePartielle(liste** l)
{
    if(*l != NULL)
    {
        cellule* temp = (*l)->deb;
        cellule* temp2 = NULL;
        while(temp != NULL)
        {
            temp2 = temp;
            temp = temp->suiv;
            detruireCellule(&temp2);
        }
        free(*l);
        *l = NULL;
    }
}
