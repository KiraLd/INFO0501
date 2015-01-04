#include "outilsArbre.h"
#include "arbreInter.h"
#include <stdio.h>
#include <stdlib.h>
#include "outilsTableHachage.h"
#include <stddef.h>
#include <time.h>
#include <string.h>

void afficherArbreRecursif(arbre* a)
{
    afficherNoeudRecursif(a->racine);
}

void afficherArbreIteratif(arbre* a)
{
    afficherNoeudIteratif(a->racine);
}



arbre* lireArbre(char*f)
{
    FILE* fichier = fopen(f,"r");
    char* temp =(char*)malloc(sizeof(char)*50);
    arbre* a = creerArbre();
    noeud* n = NULL;
    while(fscanf(fichier,"%s",temp)!=-1)
    {
        if(strlen(temp)<27)
        {
            n = creerNoeud(temp);
            insererNoeud(a,n);
        }
    }
    close(fichier);
    return a;
}

void exporter(char* s,arbre* a)
{
    FILE* f = fopen(s,"w");
    fprintf(f, "graph G {");
    exporterNoeud(f,a->racine);
    fprintf(f, "\n}");
}

void exporterNoeud(FILE* f,noeud* n)
{
    if(n!=NULL)
    {
        if(n->gauche!=NULL)
        {
            fprintf(f, "\n\t%s -- %s;", n->mot, n->gauche->mot);
            exporterNoeud(f,n->gauche);
        }
        if(n->droit!=NULL)
        {
            fprintf(f, "\n\t%s -- %s;", n->mot, n->droit->mot);
            exporterNoeud(f,n->droit);
        }
    }
}

int compterArbre(arbre* a)
{
    return compterNoeud(a->racine);
}

int compterNoeud(noeud* n)
{
    if(n!=NULL)
    {
        return 1 + compterNoeud(n->gauche) + compterNoeud(n->droit);
    }
    return 0;
}

void comparaisonArbreHachage(char* f, int n)
{

    clock_t t1;
    clock_t t2;
    double duree;
    arbre* a;
    int nb;
    tableHachage* h;

    printf("\n\nFichier: %s\n\n",f);
    t1 = clock();
    a = lireArbre(f);
    t2 = clock();
    duree = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Arbre: %2.1f secondes\n", duree);
    nb = compterArbre(a);
    printf("\nNombre: %d\n", nb);
    printf("\nHauteur: %d\n", hauteur(a));
    detruireArbre(&a);

    comparaisonTemps(f,n);
}

int hauteur(arbre* a)
{
    if(a != NULL)
    {
        return hauteurNoeud(a->racine);
    }
    return 0;
}

int hauteurNoeud(noeud* n)
{
    if(n ==  NULL)
    {
        return 0;
    }
    else
    {
        return 1 + maximum(hauteurNoeud(n->gauche), hauteurNoeud(n->droit));
    }
}

int maximum(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
