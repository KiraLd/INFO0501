#include "outilsGraphe.h"

int main(void)
{

    char* f = "graphe2.txt";
    graphe* g = creerGraphe(f);
    char* f2 = "export.dot";
    exporterMatrice(f2,g);
    afficherMatriceAdjacences(g);
    sommet*** s = dijkstra_complet(g);
    afficherDijkstraComplet(g, s);



}
