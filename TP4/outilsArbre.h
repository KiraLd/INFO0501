#ifndef _OUTILSARBRE_H_

#define _OUTILSARBRE_H_

#include "arbre.h"
#include <stddef.h>
#include <stdio.h>

void afficherArbreRecursif(arbre* a);
void afficherArbreIteratif(arbre* a);
arbre* lireArbre(char*f);
void exporter(char* s,arbre* a);
void exporterNoeud(FILE* f,noeud* n);
int compterArbre(arbre* a);
int compterNoeud(noeud* n);
void comparaisonArbreHachage(char* f, int n);
int hauteur(arbre* a);
int hauteurNoeud(noeud* n);
int maximum(int a, int b);

#endif /* _OUTILSARBRE_H_h*/
