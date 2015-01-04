#ifndef _OUTILSLISTE_H_
#define _OUTILSLISTE_H
#include "liste.h"

void afficherListe(liste* l);
liste* lire(char* f);
int compterListe(liste* l);
int vide(liste* l);
cellule* tete(liste* l);
cellule* queueListe(liste* l);

#endif /* _OUTILSLISTE_H_*/
