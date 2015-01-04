#include "outilsTableHachage.h"
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void afficherTableHachage(tableHachage* h)
{
    int i;
    int n = h->n;
    for(i = 0 ; i < n ; i++)
    {
        printf("\nListe: %d\n", i);
        sleep(1);
        if(h->l[i] == NULL)
        {
            printf("null");
        }
        afficherListe(h->l[i]);
    }
}

int convertirChEntier(char* s)
{
    int n = strlen(s);
    int i;
    int somme = 0;
    for(i = 0 ; i < n ; i++)
    {
        somme += s[i] * pow(2, n - i - 1);
    }
    return abs(somme);
}

int hachage(int k, int n)
{
    /*printf("\nhachage %d\n",k%n);*/
    return k % n;
}

void insererHachage(tableHachage* h, cellule* c)
{
    int indice = hachage(convertirChEntier(c->mot), h->n);
    inserer(h->l[indice], c);
}

cellule* rechercherHachage(tableHachage* h, char* s)
{
    int indice = hachage(convertirChEntier(s), h->n);
    return rechercher(h->l[indice], s);
}

void supprimerHachage(tableHachage* h, cellule* c)
{
    cellule* temp = NULL;
    temp = rechercherHachage(h, c->mot);
    if(temp != NULL)
    {
        int indice = hachage(convertirChEntier(c->mot), h->n);
        supprimerCellule(h->l[indice], c);
    }

}

tableHachage* lireHachage(char* f, int n)
{
    FILE* fichier = fopen(f, "r");
    char* temp = (char*) malloc(sizeof(char) * 50);
    tableHachage* h = creerTableHachage(n);
    cellule* temp_c = NULL;
    cellule* r = NULL;
    while(fscanf(fichier, "%s", temp) != -1)
    {
        if(strlen(temp)<27)
        {
            r = rechercherHachage(h, temp);
            if(r == NULL)
            {
                temp_c = creerCellule(temp);
                insererHachage(h, temp_c);
            }
        }

    }
    return h;
}

int compterTableHachage(tableHachage* h)
{
    int i;
    int n = h->n;
    int s = 0;
    for(i = 0 ; i < n ; i++)
    {
        s += compterListe(h->l[i]);
    }
    return s;
}

void equilibreHachage(tableHachage* h)
{
    int i;
    int n = h->n;
    double m = compterTableHachage(h) / n;
    int s;
    double ms = 0.0;
    printf("\nMoyenne: %f", m);
    for(i = 0 ; i < n ; i++)
    {
        s = compterListe(h->l[i]);
        printf("\nListe %d: %d Ecart: %f \n", i, s, (s*100/m)-100);
        ms += s/m;
    }
    printf("\nEcart moyen: %f\n", ms/n);
}

void comparaisonTemps(char* f, int n)
{
    clock_t t1;
    clock_t t2;
    double duree;
    tableHachage* h;
    liste* l;

    t1 = clock();
    h = lireHachage(f, n);
    t2 = clock();
    duree = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf("Temps d'execution hachage: %2.1f secondes\n", duree);
    printf("\nNombre d'elements: %d\n", compterTableHachage(h) );


    t1 = clock();
    l = lire(f);
    t2 = clock();
    duree = (double) (t2 - t1) / CLOCKS_PER_SEC;
    printf("\nTemps d'execution liste: %2.1f secondes\n", duree);
    printf("\nNombre d'elements: %d", compterListe(l) );
}

