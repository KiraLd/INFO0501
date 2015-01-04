#include "liste.h"
#include "cellule.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

liste* creerListe()
{
    liste* l = (liste*) malloc( sizeof(liste) );
    l->tete = NULL;
    return l;
}

void detruireListe(liste** l)
{
    if(l != NULL)
    {
        if(l[0] != NULL)
        {
            if(l[0]->tete != NULL)
            {
                cellule* temp = l[0]->tete;
                supprimerCellule(l[0], l[0]->tete);
                free(temp);
                if(l[0]->tete != NULL)
                {
                    detruireListe(l);
                }
            }
        }
    }

}

void inserer(liste* l, cellule* c)
{
    cellule* temp = l->tete;
    if(temp == NULL)
    {
        l->tete = c;
    }
    else
    {
        temp->prev = c;
        c->next = temp;
        l->tete = c;
    }
}

cellule* rechercher(liste* l, char* m)
{
    if(l->tete == NULL)
    {
        return NULL;
    }
    else
    {
        cellule* temp = l->tete;
        while(temp != NULL)
        {
            if( !strcmp(temp->mot, m) )
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

}

void supprimerCellule(liste* l, cellule* c)
{
    if(l->tete == c)
    {
        l->tete = c->next;
        if(l->tete != NULL)
        {
            l->tete->prev = NULL;
        }
    }
    else
    {
        c->prev->next = c->next;
        if(c->next != NULL)
        {
            c->next->prev = c->prev;
        }
    }
}
