#ifndef _PILE_H_
#define _PILE_H_
#include "liste.h"

struct pile
{
    liste* l;
};

typedef struct pile pile;

pile* creerPile();
void detruirePile(pile** p);
int pileVide(pile* p);
void empiler(pile* p,noeud* n);
noeud* depiler(pile* p);
noeud* sommet(pile* p);

#endif /* _PILE_H_*/
