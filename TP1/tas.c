#include "tas.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int parent(int i)
{
    return (i - 1) / 2;
}

int gauche(int i)
{
    return 2 * i;
}

int droite(int i)
{
    return (2 * i) + 1;
}


void entasserMax(tas* t, int i)
{
    int g, d, max;
    g = gauche(i) + 1;
    d = droite(i) + 1;
    if(g < t->taille && t->tab[g] > t->tab[i])
    {
        max = g;
    }
    else
    {
        max = i;
    }
    if(d <  t->taille && t->tab[d] > t->tab[max])
    {
        max = d;
    }
    if(max != i)
    {
        echanger(t->tab,t->taille, i, max);
        if(t->taches != NULL)
        {
            echanger_char(t->taches, i, max, t->taille);
        }
        entasserMax(t, max);
    }
}

void construireTasMax(tas* t)
{
    int i;
    for(i = (t->taille / 2) - 1 ; i >= 0 ; i--)
    {
        entasserMax(t, i);
    }

}

tas* creerTas(int n)
{
    tas* t = (tas*) malloc(sizeof(tas));
    t->tab = creerTab(n);
    t->longueur = n;
    t->taille = n;
    t->taches = NULL;
    return t;
}

void afficher_tas(tas* t)
{
    if(t->taches[0] == NULL)
    {
        afficher(t->tab, t->longueur);
    }else
    {
        int i;
        for(i = 0 ; i < t->taille ; i++)
        {
            printf("Priorite: %d\n", t->tab[i]);
            printf("Tache: %s\n", t->taches[i]);
        }
    }

}

tas* test_tas(int n)
{
   tas* t = creerTas(n);
   afficher_tas(t);
   printf("\n");
   triParTas(t);
   return t;
}

fileP* creerFileP(int n)
{
    tas* t = (tas*) malloc(sizeof(tas));
    t->tab = creerTab(2 * n);
    t->longueur = 2 * n;
    t->taille = n;
    t->taches = (char**) malloc(sizeof(char*) * 2 * n);
    int i;
    for(i = 0 ; i < 2 * n ; i++)
    {
        t->taches[i] = (char*) malloc(50 * sizeof(char));
    }
    fileP* f = (fileP*) malloc(sizeof(fileP));
    f->t = t;
    return f;

}

fileP* construireFileP(fileP* f)
{
    construireTasMax(f->t);
}

fileP* afficherFileP(fileP* f)
{
    afficher_tas(f->t);
}

//à corriger
int extraire_max_tas(fileP* f)
{

    int max = f->t->tab[0];
    echanger(f->t->tab,f->t->taille,0,f->t->taille-1);
    f->t->taille--;
    entasserMax(f->t,0);
    return max;
}

//à corriger
void augmenter_cle_tas(fileP* f,int i, int cle)
{
    f->t->tab[i]=cle;
    construireFileP(f);
}

void inserer_tas_max(fileP* f, int cle, char* t)
{
    if(f->t->taille+1<=f->t->longueur)
    {
        f->t->taille++;
        f->t->taches[f->t->taille-1]=t;
        augmenter_cle_tas(f,f->t->taille-1,cle);
    }
}


