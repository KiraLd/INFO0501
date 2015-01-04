#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "util.h"
#include "tri.h"
#include "tas.h"

int main(int argc, char* argv[])
{
    int n=20;
    int* t = creerTab(n);
    afficher(t,n);
    triFusion(t,n,0,n-1);
    afficher(t,n);
    comparaison_tri(2,100000,2);


    fileP* f = lire_tache("listeTaches1.txt");
    printf("\nLecture du fichier:\n\n");
    afficherFileP(f);

    construireFileP(f);
    printf("\nConstruction du tas\n\n");
    afficherFileP(f);

    printf("\nTache retiree: %d\n\n",extraire_max_tas(f));

    char* s1 = "faire_une_sieste";
    printf("Tache ajoutee: %s %d\n\n",s1,30);
    inserer_tas_max(f,30,s1);
    afficherFileP(f);

    printf("\nTache retiree: %d\n\n",extraire_max_tas(f));


    char* s2 = "Embeter_mon_binome";
    printf("Tache ajoutee: %s %d\n\n",s2,1);
    inserer_tas_max(f,1,s2);
    afficherFileP(f);

}
