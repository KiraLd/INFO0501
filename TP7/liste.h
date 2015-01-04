#ifndef _LISTE_H_
#define _LISTE_H_
#include "cellule.h"

struct liste
{
    cellule* deb;
    cellule* fin;
};

typedef struct liste liste;

liste* creerListe();
void inserer(liste* l, cellule* c);
void afficherListe(liste* l);
int tailleListe(liste* l);
void detruireListePartielle(liste** l);

#endif // _LISTE_H_
