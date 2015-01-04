#ifndef _ARBRE_H_
#define _ARBRE_H_

#include "noeud.h"

struct arbre
{
    noeud* racine;
};

typedef struct arbre arbre;

arbre* creerArbre();
void detruireArbre(arbre** a);
int insererNoeud(arbre* a,noeud* n);
noeud* rechercherNoeud(arbre* a,char* m);
void supprimer(arbre* a,noeud* n);

#endif /* _ARBRE_H_*/
