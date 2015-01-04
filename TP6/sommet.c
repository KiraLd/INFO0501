#include "sommet.h"
#include <stdio.h>
#include <stdlib.h>

sommet* creerSommet(int c, int d, sommet* p, int v)
{
    sommet* s =(sommet*)malloc(sizeof(sommet));
    s->couleur = c;
    s->distance = d;
    s->pere = p;
    s->v = v;
    s->d = -1;
    s->f = -1;
    s->ensemble = NULL;
    return s;
}

void afficherSommet(sommet* s)
{
    if(s !=NULL)
    {
        printf("\n Sommet %d\n",s->v);
    }

}
