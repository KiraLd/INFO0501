#include "outilsGraphe.h"

int main(int argc, char* argv[])
{
    if(argc>1)
    {
        graphe* g = creerGraphe(argv[1]);
        int n = 0;
        arrete** ar = arretesGraphes(g,&n);
        listeArrete* la = genererAcpmKruskal(g);
        int s = sommeArrete(la);
        printf("\nSomme: %d\n",s);
        sommet** s_ = genererAcpmPrim(g);
        afficherSommets(s_,g->n);
    }
    else
    {
        printf("Paramètre attendu: fichier.txt");
    }
}
