#include "outilsArbre.h"
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if(argc>1)
    {
        arbre* a = lireArbre(argv[1]);
        afficherArbreIteratif(a);
        detruireArbre(&a);
        comparaisonArbreHachage(argv[1], 11);
    }
    else
    {
        printf("Paramètre attendu: fichier.txt");
    }
    return 0;
}
