#include "outilsArbre.h"
#include <string.h>
#include <math.h>
#include <time.h>

int main(void)
{
    char* f = "dico_ae.txt";
    arbre* a = lireArbre(f);
    afficherArbreIteratif(a);
    detruireArbre(&a);
    comparaisonArbreHachage(f, 11);
    return 0;
}
