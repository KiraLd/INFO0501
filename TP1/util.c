#include "util.h"
#include "tas.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int* lire(char* f, int* n)
{
    FILE* fichier = fopen(f, "r");
    fscanf(fichier, "%d", n);
    int temp;
    int k = 0;
    int* tab = (int*) malloc(sizeof(int) * (*n));
    while(fscanf(fichier, "%d", &temp) & k < *n)
    {
        tab[k] = temp;
        k++;
    }
    return tab;
}

fileP* lire_tache(char* f)
{
    FILE* fichier = fopen(f, "r");
    int *n = (int*) malloc(sizeof(int));
    fscanf(fichier, "%d", n);
    fileP* f2 = creerFileP(*n);
    int temp = 0;
    char* temp2 = (char*) malloc(50 * sizeof(char));
    int i;
    for(i = 0 ; i < *n ; i++)
    {
        fscanf(fichier, "%s", temp2);
        f2->t->taches[i] = strcpy(f2->t->taches[i], temp2);
        fscanf(fichier, "%d", &temp);
        f2->t->tab[i] = temp;
    }

    return f2;


}

void afficher(int* t, int n)
{
    int i;
    for(i = 0 ; i < n ; i++)
    {
        printf("%d\t", t[i]);
    }
}

void echanger(int* tab, int n, int i, int j)
{
    if(i >= 0 & i < n)
    {
        if(j >= 0 & j < n)
        {
            if(i != j)
            {
                tab[i] += tab[j];
                tab[j] = tab[i] - tab[j];
                tab[i] -= tab[j];
            }
        }
    }
}

int* creerTab(int n)
{
    int* tab = (int*)malloc(sizeof(int)*n);
    srand(time(NULL));
    int i;
    for(i=0;i<n;i++)
    {
        tab[i] = rand()%n;
    }
    return tab;
}

void melanger(int* tab, int n)
{
    srand(time(NULL));
    int i;
    for(i=0;i<n;i++)
    {
        echanger(tab,n,i,rand()%n);
    }
}

int* copie(int* tab, int n)
{
    int* tab2 =(int*)malloc(sizeof(int)*n);
    int i;
    for(i=0;i<n;i++)
    {
        tab2[i] = tab[i];
    }
    return tab2;
}

int* fusion(int* tab1, int n1, int* tab2, int n2)
{
    int* tab3 =(int*)malloc(sizeof(int)*(n1+n2));
    int i;
    int j=0;
    int k=0;
    for(i=0;i<n1+n2;i++)
    {
        if(tab1[j]<tab2[k])
        {
            tab3[i] = tab1[j];
            j++;
        }
        else
        {
            tab3[i] = tab2[k];
            k++;
        }
    }
    return tab3;
}

void fusion2(int* tab,int n, int d, int p, int f)
{
    int* temp = copie(tab,n);
    int i = d;
    int j = p+1;
    int k = d;
    while(i<=p && j<=f)
    {
        if(temp[i]<temp[j])
        {
            tab[k] = temp[i];
            i++;
        }
        else
        {
            tab[k] = temp[j];
            j++;
        }
        k++;
    }
    if(k<=f)
    {
        while(i<=p)
        {
            tab[k] = temp[i];
            k++;
            i++;
        }
        while(j<=f)
        {
            tab[k] = temp[j];
            k++;
            j++;
        }
    }
    free(temp);
}

void temp_execution_insertion(int n)
{
    printf("Tri insertion pour n = %d\n",n);
    clock_t t1,t2;
    double duree;
    int* t = creerTab(n);
    t1=clock();
    tri_insertion(t,n);
    t2=clock();
    duree=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("%2.1f secondes\n", duree);
}

void temp_execution_tas(int n)
{
    printf("Tri par tas pour n = %d\n",n);
    clock_t t1,t2;
    double duree;
    tas* t = creerTas(n);
    t1=clock();
    triParTas(t);
    t2=clock();
    duree=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("%2.1f secondes\n", duree);
}

void temp_execution_fusion(int n)
{
    printf("Tri fusion pour n = %d\n",n);
    clock_t t1,t2;
    double duree;
    int* t = creerTab(n);
    t1=clock();
    triFusion(t,n,0,n-1);
    t2=clock();
    duree=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("%2.1f secondes\n", duree);
}

void temp_execution_rapide(int n)
{
    printf("Tri rapide pour n = %d\n",n);
    clock_t t1,t2;
    double duree;
    int* t = creerTab(n);
    t1=clock();
    triRapide(t,n);
    t2=clock();
    duree=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("%2.1f secondes\n", duree);
}

void temp_execution_bulle(int n)
{
    printf("Tri a bulles pour n = %d\n",n);
    clock_t t1,t2;
    double duree;
    int* t = creerTab(n);
    t1=clock();
    triBulle(t,n);
    t2=clock();
    duree=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("%2.1f secondes\n", duree);
}

void comparaison_tri(int d,int max, int pas)
{
    int i;
    for(i=d;i<max;i=pas*i)
    {
        temp_execution_rapide(i);
        printf("\n");
        temp_execution_tas(i);
        printf("\n");
        temp_execution_insertion(i);
        printf("\n");
        temp_execution_fusion(i);
        printf("\n");
        temp_execution_bulle(i);
        printf("\n");
        printf("\n");
    }
}

void copie_string(char* s1, char* s2, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        s1[i]=s2[i];
    }
}

void echanger_char(char** t,int i, int j, int n)
{
    if(i<n&&j<n)
    {
        char* temp = t[i];
        t[i] = t[j];
        t[j] = temp;
    }

}






