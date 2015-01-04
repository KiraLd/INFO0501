#ifndef _LISTE_H_
#define _LISTE_H_

#include "cellule.h"

struct liste {
    cellule* tete;
};

typedef struct liste liste;

liste* creerListe();
void detruireListe(liste** l);
void inserer(liste* l, cellule* c);
cellule* rechercher(liste* l, char* m);
void supprimerCellule(liste* l, cellule* c);

#endif /* _LISTE_H_*/
