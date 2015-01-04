#include "util.h"
#include "tas.h"
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int* lire(char* f, int* n)
{
    FILE* fichier = fopen(f,"r");
    fscanf(fichier,"%d",n);
    int temp;
    int k=0;
    int* tab = (int*) malloc(sizeof(int)*(*n));
    while(fscanf(fichier,"%d",&temp)&k<*n)
    {
        tab[k]=temp;
        k++;
    }
    return tab;
}



void afficher(int* t, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",t[i]);
    }
}

void afficherMatrice(int** t, int n, int m)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",t[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void echanger(int* tab,int n,int i, int j)
{
    if(i>=0&i<n)
    {
        if(j>=0&j<n)
        {
            if(i!=j)
            {
                tab[i]+=tab[j];
                tab[j]=tab[i]-tab[j];
                tab[i]-=tab[j];
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

void detruireMatrice(int*** t, int n)
{
    if(t != NULL)
    {
        if(*t != NULL)
        {
            int i;
            for(i = n-1; i >= 0; i++)
            {
                if((*t)[i] != NULL)
                {
                    free((*t)[i]);
                }
            }
            free(*t);
        }
    }
}






