#include "outilsGraphe.h"

int main(int argc, char* argv[])
{
    if(argc>1)
    {
        graphe* g = creerGraphe(argv[1]);
        sommet*** s = dijkstra_complet(g);
        if(s != NULL)
        {
            printf("\nAlgorithme de dijkstra: execution pour tous les sommets\n");
            afficherDijkstraComplet(g, s);
        }
        sommet** s2 = bellman_ford(g, 0);
        printf("\nAlgorithme de Bellman-ford: execution depuis le sommet 0")
        afficherChemins(g, s2, 0);

    }
    else
    {
        printf("Paramètre attendu: fichier.txt");
    }


}
