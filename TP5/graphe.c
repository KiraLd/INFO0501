#include "graphe.h"
#include "tas.h"
#include "file.h"
#include "listeArrete.h"
#include "ensemble.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define inf INT_MAX


liste** creerListesAdjacences(char* f, int* n)
{

    FILE* fichier = fopen(f, "r");
    cellule* c_ = NULL;
    int temp1;
    int temp2;
    int o = 0;
    int v = 0;
    int c = 0;
    char* s = (char*)malloc(sizeof(char)*50);
    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",n);
    liste** l =(liste**)malloc(sizeof(liste*)*(*n));
    int i;
    int temp3 = 0;
    for(i = 0; i<*n; i++)
    {
        l[i] = creerListe();
    }

    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",&o);
    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",&v);
    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",&c);
    fscanf(fichier,"%s",s);
    while(fscanf(fichier,"%s",s)!=-1)
    {
        if(strcmp(s,"finDefAretes")!=0)
        {
            temp1 = atoi(s);
            fscanf(fichier,"%d",&temp2);
            if(v)
            {
                fscanf(fichier,"%d",&temp3);
            }

            if(o)
            {
                if(v)
                {
                    c_ = creerCellule(temp2,temp3);
                    inserer(l[temp1],c_);
                }
                else
                {
                    c_ = creerCellule(temp2,1);
                    inserer(l[temp1],c_);
                }
            }
            else
            {
                if(v)
                {
                    c_ = creerCellule(temp2,temp3);
                    inserer(l[temp1],c_);
                    c_ = creerCellule(temp1,temp3);
                    inserer(l[temp2],c_);
                }
                else
                {
                    c_ = creerCellule(temp2,1);
                    inserer(l[temp1],c_);
                    c_ = creerCellule(temp1,1);
                    inserer(l[temp2],c_);
                }

            }
        }
    }
    close(f);
    return l;
}


int** creerMatriceAdjacences(char* f,int* n)
{
    FILE* fichier = fopen(f, "r");
    int temp1;
    int temp2;
    int o = 0;
    int v = 0;
    int c = 0;
    char* s = (char*)malloc(sizeof(char)*50);
    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",n);
    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",&o);
    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",&v);
    fscanf(fichier,"%s",s);
    fscanf(fichier,"%d",&c);
    int** tab = (int**)malloc(sizeof(int*)*(*n));
    int i;
    int j;
    for(i=0; i<*n; i++)
    {
        tab[i] = (int*)malloc(sizeof(int)*(*n));
        for(j=0; j<*n; j++)
        {
            tab[i][j]=0;
        }
    }
    int temp3 = 0;
    fscanf(fichier,"%s",s);
    while(fscanf(fichier,"%s",s)!=-1)
    {
        if(strcmp(s,"finDefAretes")!=0)
        {
            temp1 = atoi(s);
            fscanf(fichier,"%d",&temp2);
            if(v)
            {
                fscanf(fichier,"%d",&temp3);
            }
            if(o)
            {
                if(v)
                {
                    tab[temp1][temp2] = temp3;
                }
                else
                {
                    tab[temp1][temp2] = 1;
                }
            }
            else
            {
                if(v)
                {
                    tab[temp1][temp2] = temp3;
                    tab[temp2][temp1] = temp3;
                }
                else
                {
                    tab[temp1][temp2] = 1;
                    tab[temp2][temp1] = 1;
                }

            }
        }
    }
    close(f);
    return tab;
}

void afficherMatriceAdjacences(graphe* g)
{
    int i;
    int n = g->n;
    int j;
    for(i = 0; i < n ; i++ )
    {
        for(j = 0; j<n; j++)
        {
            printf(" %d ",g->m[i][j]);
        }
        printf("\n");
    }
}

void afficherListesAdjacences(graphe* g)
{
    int n = g->n;
    int i;
    for(i = 0; i<n; i++)
    {
        printf("\nListe: %d\n",i);
        afficherListe(g->l[i]);
    }

}

graphe* creerGraphe(char* f)
{
    graphe* g = (graphe*)malloc(sizeof(graphe));
    int* n = (int*)malloc(sizeof(int));
    g->l = creerListesAdjacences(f,n);
    g->m = creerMatriceAdjacences(f,n);
    g->n = *n;
    return g;

}

void detruireGraphe(graphe** g)
{
    if(g != NULL)
    {
        if(*g != NULL)
        {
            if((*g)->l != NULL)
            {
                detruireListePartielle((*g)->l);
            }
            if((*g)->m != NULL)
            {
                free((*g)->m);
            }
            free(*g);
        }
    }
}

