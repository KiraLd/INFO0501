#include "outilsGraphe.h"

int main(int argc, char* argv[])
{
    if(argc>1)
    {
        graphe* g = creerGraphe(argv[1]);
        sommet** v = parcoursProfondeurListe(g);
        afficherDate(v,g->n);
    }
    else
    {
        printf("Paramètre attendu: fichier.txt");
    }
}
