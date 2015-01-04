#ifndef _OUTILSTABLEHACHAGE_H_
#define _OUTILSTABLEHACHAGE_H_
#include "tableHachage.h"

void afficherTableHachage(tableHachage* h);
int convertirChEntier(char* s);
int hachage(int k, int n);
void insererHachage(tableHachage* h, cellule* c);
cellule* rechercherHachage(tableHachage* h, char* s);
void supprimerHachage(tableHachage* h, cellule* c);
tableHachage* lireHachage(char* f, int n);
int compterTableHachage(tableHachage* h);
void equilibreHachage(tableHachage* h);
void comparaisonTemps(char* f, int n);


#endif /* _OUTILSTABLEHACHAGE_H_*/
