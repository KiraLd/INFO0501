#ifndef _LISTEARRETE_H_
#define _LISTEARRETE_H_
#include "arrete.h"

struct listeArrete
{
    arrete* deb;
    arrete* fin;
};

typedef struct listeArrete listeArrete;

listeArrete* creerListeA();
void insererA(listeArrete* l, arrete* c);
void afficherListeA(listeArrete* l);
int tailleListeA(listeArrete* l);
void detruireListePartielleA(listeArrete** l);
int sommeArrete(listeArrete* la);

#endif
