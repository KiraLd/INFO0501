#include "pile.h"
#include <stdio.h>
#include <stdlib.h>

void afficherPile(pile* p)
{
    printf("\n");
    int i;
    for(i = 0 ; i < p->taille ; i++)
    {
        printf("%d\t", p->t[i]);
    }
    printf("\n");
}

void testPile()
{
    pile* p = creerPile(10);
    int i;
    for(i = 1 ; i <= 11 ; i++)
    {
        printf("Sommet: %d\n",sommet(p));
        empiler(p,i);
        afficherPile(p);
    }
    if(pilePleine(p))
    {
        printf("La pile est pleine\n");
    }
    for(i = 1 ; i <= 11 ; i++)
    {
        printf("Sommet: %d\n",sommet(p));
        depiler(p);
        afficherPile(p);
    }
    if(pileVide(p))
    {
        printf("La pile est vide\n");
    }
}

pile* copierPile(pile* p)
{

    int i;
    pile* p2 = creerPile(p->capacite);
    for(i=0;i < p->taille;i++)
    {
        p2->t[i] = p->t[i];
        p2->taille++;
    }
    return p2;
}


