#include "tas.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>

int parent(int i)
{
    return (i-1)/2;
}

int gauche(int i)
{
    return 2*i;
}

int droite(int i)
{
    return (2*i)+1;
}


void entasserMin(tas* t, int i)
{
    int g,d,min;
    g = gauche(i)+1;
    d = droite(i)+1;
    if(g < t->taille && t->ind[g] < t->ind[i])
    {
        min = g;
    }
    else
    {
        min = i;
    }
    if(d <  t->taille && t->ind[d] < t->ind[min])
    {
        min = d;
    }
    if(min!=i)
    {
        echanger(t->tab,t->taille,i,min);
        echanger(t->ind,t->taille,i,min);
        entasserMin(t,min);
    }
}

void construireTasMin(tas* t)
{
    //t->taille = t->longueur;
    int i;
    for(i=(t->taille/2)-1;i>=0;i--)
    {
        entasserMin(t,i);
    }

}

tas* creerTas(int n)
{
    tas* t =(tas*)malloc(sizeof(tas));
    t->tab=creerTab(n);
    t->ind=creerTab(n);
    t->longueur=n;
    t->taille=n;
    return t;
}

void afficher_tas(tas* t)
{
        int i;
        for(i=0;i<t->taille;i++)
        {
            printf("Priorite: %d\n",t->tab[i]);
        }

}


fileP* creerFileP(int n)
{
    tas* t = (tas*)malloc(sizeof(tas));
    t->tab = creerTab(2*n);
    t->ind = creerTab(2*n);
    t->longueur = 2*n;
    t->taille = 0;
    fileP* f =(fileP*)malloc(sizeof(fileP));
    f->t=t;
    return f;

}

fileP* construireFileP(fileP* f)
{
    construireTasMin(f->t);
}

fileP* afficherFileP(fileP* f,int i)
{
    tas* t = f->t;
    if(i < t->taille && i>=0)
    {

       afficherFileP(f, gauche(i)+1);
       afficherFileP(f, droite(i)+1);
       printf("Priorite: %d\n",t->tab[i]);
    }


}

int extraire_min_tas(fileP* f)
{

    int min = f->t->tab[0];
    echanger(f->t->tab,f->t->taille,0,f->t->taille-1);
    echanger(f->t->ind,f->t->taille,0,f->t->taille-1);
    f->t->taille--;
    entasserMin(f->t,0);
    return min;
}

void augmenter_cle_tas(fileP* f,int cle, int ind)
{
    int i = rechercherTas(f,cle);
    f->t->tab[i] = cle;
    f->t->ind[i] = ind;
    construireFileP(f);
}

int rechercherTas(fileP* f, int cle)
{
    int ind = 0;
    int i = 0;
    int b = 0;
    while(!b)
    {
        if(cle == f->t->tab[i])
        {
            ind = i;
            b = 1;
        }
        i++;
    }
    return ind;
}

void inserer_tas_min(fileP* f, int cle, int ind)
{
    if(f->t->taille+1<=f->t->longueur)
    {
        f->t->tab[f->t->taille] = cle;
        f->t->ind[f->t->taille] = ind;
        f->t->taille++;
        construireFileP(f);
    }
}

void afficherFile(fileP* f)
{
    int i;
    printf("\nfile %d\n",f->t->taille);
    for(i = 0; i<f->t->taille; i++)
    {
        printf("\n%d %d\n",f->t->tab[i],f->t->ind[i]);
    }
}

void detruireTas(tas** t)
{
    if(t != NULL)
    {
        if(*t != NULL)
        {
            if((*t)->tab != NULL)
            {
                free((*t)->tab);
            }
            if((*t)->ind != NULL)
            {
                free((*t)->ind);
            }
            free(*t);
        }
    }
}

void detruireFileP(fileP** f)
{
    if(f != NULL)
    {
        if(*f != NULL)
        {
            detruireTas(&((*f)->t));
            free(*f);
        }
    }
}


