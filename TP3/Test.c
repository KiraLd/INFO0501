#include "outilsTableHachage.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

    if(argc>1)
    {
        comparaisonTemps(argv[1], 11);
    }
    else
    {
        printf("Paramètre attendu: fichier.txt");
    }
}
