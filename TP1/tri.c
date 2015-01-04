#include "tri.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define false 0
#define FALSE 0
#define true 1
#define TRUE 1
#define inf INT_MAX

void tri_insertion(int* tab, int n)
{
    int i,j,cle;
    for(j=1;j<n;j++)
    {
        cle = tab[j];
        i = j-1;
        while(i>=0&tab[i]>cle)
        {
            tab[i+1] = tab[i];
            i = i-1;
        }
        tab[i+1] = cle;
    }
}

void triParTas(tas* t)
{
    int temp = t->taille;
    construireTasMax(t);
    int i;
    for(i=t->taille-1;i>0;i--)
    {
        echanger(t->tab,t->taille,0,i);
        if(t->taches!=NULL)
        {
            echanger_char(t->taches,0,i,t->taille);
        }
        t->taille--;
        entasserMax(t,0);
    }
    t->taille=temp;

}

void triFusion(int * tab, int n, int d, int f)
{
    int p;
    if(d<f)
    {
        p = (d+f)/2;
        triFusion(tab,n,d,p);
        triFusion(tab,n,p+1,f);
        fusion2(tab,n,d,p,f);
    }
}

void triRapide(int *a, int n) {
    if (n < 2)
        return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r) {
        if (*l < p) {
            l++;
        }
        else if (*r > p) {
            r--;
        }
        else {
            int t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    triRapide(a, r - a + 1);
    triRapide(l, a + n - l);
}

void triBulle(int* t, int n)
{
    int b;
    int j;
    do
    {
        b = FALSE;
        for(j=0;j<n-1;j++)
        {
            if(t[j]>t[j+1])
            {
                echanger(t,n,j,j+1);
                b=TRUE;
            }
        }
    }
    while(b);
}
