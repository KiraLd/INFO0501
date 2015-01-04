#include "outilsGraphe.h"

int main(void)
{
    char* f = "graphe2.txt";
    graphe* g = creerGraphe(f);
    int n = 0;
    arrete** ar = arretesGraphes(g,&n);
    listeArrete* la = genererAcpmKruskal(g);
    int s = sommeArrete(la);
    printf("\nSomme: %d\n",s);
    sommet** s_ = genererAcpmPrim(g);
    afficherSommets(s_,g->n);
}
