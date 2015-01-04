#include "tableHachage.h"
#include <stdio.h>
#include <stdlib.h>

tableHachage* creerTableHachage(int n)
{
    liste** l;
    int i;
    tableHachage* h;
    h = (tableHachage*) malloc( sizeof(tableHachage) );
    h->n = n;
    l = (liste**) malloc( sizeof(liste*) * n );

    for(i = 0 ; i < n ; i++)
    {
        l[i] = creerListe();
    }
    h->l = l;
    return h;
}

void detruireTableHachage(tableHachage** h)
{
    if((*h)->l != NULL)
    {
        int i;
        for(i = 0 ; i < (*h)->n ; i++)
        {
            detruireListe(&((*h)->l[i]));
        }
    }
}

