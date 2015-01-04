#include "outilsGraphe.h"

int main(void)
{
    char* f = "graphe1.txt";
    graphe* g = creerGraphe(f);
    sommet** v = parcoursProfondeurListe(g);
    afficherDate(v,g->n);
}
