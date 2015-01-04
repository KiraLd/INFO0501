#ifndef _ARBREINTER_H_
#define _ARBREINTER_H_

#include "arbre.h"

noeud* rechercherNoeudRecursif(noeud* n,char* m);
noeud* rechercherNoeudIteratif(noeud* n,char* m);
void transplanter(arbre* a,noeud* u, noeud* v);
void supprimerNoeud(arbre* a,noeud* z);
noeud* minimumArbre(noeud* x);
noeud* maximumArbre(noeud* x);
noeud* successeurArbre(noeud* x);
void afficherNoeudRecursif(noeud* n);
void afficherNoeudIteratif(noeud* a);

#endif /* _ARBREINTER_H_*/
