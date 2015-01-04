#ifndef _SOMMET_H_
#define _SOMMET_H_
#include <stddef.h>

struct sommet
{
    int couleur;
    int distance;
    struct sommet* pere;
    int v;  //valeur du sommet
    int d;  //date début traitement
    int f;  //date fin traitement
    void* ensemble;
};
typedef struct sommet sommet;

sommet* creerSommet(int c, int d, sommet* p, int v);
void afficherSommet(sommet* s);

#endif // _SOMMET_H_
