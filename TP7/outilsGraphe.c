#include "outilsGraphe.h"
#include "tas.h"
#include "ensemble.h"
#include <stdlib.h>
#include <limits.h>
#define inf INT_MAX

sommet** parcoursLargeurListe(graphe* g, sommet* s)
{
    int i;
    int n = g->n;
    sommet** v =(sommet**)malloc(sizeof(sommet*)*n);
    for(i = 0; i<n; i++)
    {
        v[i] = creerSommet(0,0,NULL,i); //couleur 0 blanc 1 gris 2 noir
    }
    s->couleur = 1;
    s->distance = 0;
    s->pere = NULL;
    file* f = creerFile();
    enfiler(f,s);
    sommet* u = NULL;
    cellule* temp = NULL;
    while(!fileVide(f))
    {
        u = defiler(f);
        temp = g->l[u->v]->deb;
        while(temp != NULL)
        {
            if(v[temp->n]->couleur == 0)
            {
                v[temp->n]->couleur = 1;
                v[temp->n]->distance = u->distance+1;
                v[temp->n]->pere = u;
                enfiler(f,v[temp->n]);
            }
            temp = temp->suiv;
        }
        u->couleur = 2;
    }
    return v;
}

void afficherChemin(graphe* g, sommet* s, sommet* v)
{
    if(s->v==v->v)
    {
        afficherSommet(s);
    }
    else
    {
        if(v->pere == NULL)
        {
            printf("\n Pas de chemin entre le sommet %d et %d\n",s->v,v->v);
        }
        else
        {
            afficherSommet(v);
            afficherChemin(g,s,v->pere);
        }
    }
}

//export format dot
void exporterChemin(char* s_, graphe* g, sommet* s, sommet* v)
{
    FILE* f = fopen(s_,"w");
    fprintf(f, "graph G {");
    exporterCheminInter(f,g,s,v);
    fprintf(f, "\n}");
    close(f);
}

void exporterCheminInter(FILE* f, graphe* g, sommet* s, sommet* v)
{
    if(s->v!=v->v)
    {
        if(v->pere == NULL)
        {
            printf("\n Pas de chemin entre le sommet %d et %d\n",s->v,v->v);
        }
        else
        {
            fprintf(f, "\n\t%d -- %d;", v->v, v->pere->v);
            exporterCheminInter(f,g,s,v->pere);
        }
    }
}



void exporterMatrice(char* s, graphe* g)
{
    FILE* f = fopen(s,"w");
    fprintf(f, "graph G {");
    int i;
    int j;
    int n=g->n;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(g->o)
            {
                if(g->m[i][j] != 0)
                {
                    fprintf(f, "\n\t%d -- %d;", i, j);
                }
            }
            else
            {
                if(j<i)
                {
                    if(g->m[i][j] != 0)
                    {
                        fprintf(f, "\n\t%d -- %d;", i, j);
                    }
                }
            }
        }
    }
    fprintf(f, "\n}");
    close(f);
}

void exporterListe(char* s, graphe* g)
{
    FILE* f = fopen(s,"w");
    fprintf(f, "graph G {");
    cellule* c = NULL;
    int n = g->n;
    int i;
    for(i = 0; i<n; i++)
    {
        c = g->l[i]->deb;
        while(c != NULL)
        {
            fprintf(f, "\n\t%d -- %d;", i, c->n);
            c = c->suiv;
        }
    }
    fprintf(f, "\n}");
    close(f);
}

void visiterppListe(graphe* g, sommet* u, int* date, sommet** s)
{
    (*date)++;
    u->d = *date;
    u->couleur = 1;
    cellule* temp = g->l[u->v]->deb;
    while(temp != NULL)
    {
        if(s[temp->n]->couleur == 0)
        {
            s[temp->n]->pere = u;
            visiterppListe(g,s[temp->n],date,s);
        }
        temp = temp->suiv;
    }
    u->couleur = 2;
    (*date)++;
    u->f = *date;
}

sommet** parcoursProfondeurListe(graphe* g)
{
    int i;
    int n = g->n;
    sommet** s =(sommet**)malloc(sizeof(sommet*)*n);
    for(i = 0; i<n; i++)
    {
        s[i] = creerSommet(0,0,NULL,i); //couleur 0 blanc 1 gris 2 noir
    }
    int* date = (int*)malloc(sizeof(int));
    *date = 0;
    for(i = 0; i<n; i++)
    {
        if(s[i]->couleur == 0)
        {
            visiterppListe(g,s[i],date,s);
        }
    }
    return s;
}

void visiterppTri(graphe* g, sommet* u, int* date, sommet** s, liste* l)
{
    (*date)++;
    u->d = *date;
    u->couleur = 1;
    cellule* temp = g->l[u->v]->deb;
    while(temp != NULL)
    {
        if(s[temp->n]->couleur == 0)
        {
            s[temp->n]->pere = u;
            visiterppTri(g,s[temp->n],date,s,l);
        }
        temp = temp->suiv;
    }
    u->couleur = 2;
    (*date)++;
    u->f = *date;
    cellule* c = creerCelluleSommet(u);
    inserer(l,c);
}

liste* triTopologique(graphe* g)
{
    int i;
    int n = g->n;
    liste* l = creerListe();
    sommet** s =(sommet**)malloc(sizeof(sommet*)*n);
    for(i = 0; i<n; i++)
    {
        s[i] = creerSommet(0,0,NULL,i); //couleur 0 blanc 1 gris 2 noir
    }
    int* date = (int*)malloc(sizeof(int));
    *date = 0;
    for(i = 0; i<n; i++)
    {
        if(s[i]->couleur == 0)
        {
            visiterppTri(g,s[i],date,s,l);
        }
    }
    return l;
}

void afficherDate(sommet** s, int n)
{
    int i;
    for(i = 0; i<n; i++)
    {
        afficherSommet(s[i]);
        printf("\nDébut: %d Fin: %d\n",s[i]->d,s[i]->f);
    }
}


arrete** arretesGraphes(graphe* g, int* n)
{
    int i;
    int nbarretes = 0;
    for(i = 0; i < g->n ; i++)
    {
        nbarretes += tailleListe(g->l[i]);
    }
    *n = nbarretes;
    arrete** a= (arrete**)malloc(sizeof(arrete*)*nbarretes);
    cellule* temp = NULL;
    int j = 0;
    for(i = 0; i < g->n ; i++)
    {
        temp = g->l[i]->deb;
        while(temp != NULL)
        {
            a[j] = creerArrete(i,temp->n,temp->p);
            temp = temp->suiv;
            j++;
        }
    }
    return a;
}

listeArrete* genererAcpmKruskal(graphe* g)
{
    int n_ar;
    arrete** ar = arretesGraphes(g,&n_ar);
    triArretes(ar,n_ar);

    int n = g->n;
    ensemble** e = (ensemble**)malloc(sizeof(ensemble*)*n);
    sommet** s_ = (sommet**)malloc(sizeof(sommet*)*n);
    int i;
    for(i = 0; i<n; i++)
    {
        s_[i] = creerSommet(0,0,NULL,i);
        e[i] = creerEnsemble(s_[i]);
    }

    listeArrete* la = creerListeA();
    int a;
    int b;

    for(i = 0; i < n_ar; i++)
    {
        a = ar[i]->s1;
        b = ar[i]->s2;

        if(trouverEnsemble(s_[a]) != trouverEnsemble(s_[b]))
        {
            unionEnsemble(s_[a], s_[b]);
            insererA(la,ar[i]);
        }
    }

    return la;
}

sommet** genererAcpmPrim(graphe* g)
{
    int n = g->n;
    sommet** s = (sommet**)malloc(sizeof(sommet*)*n);
    int i;
    s[0] = creerSommet(1,0,NULL,0);
    cellule* temp = NULL;
    fileP* fp = creerFileP(n);
    inserer_tas_min(fp,0,0);
    for(i = 1; i<n; i++)
    {
        s[i] = creerSommet(0,inf,s[0],i);
        inserer_tas_min(fp,i,inf);

    }
    s[0]->couleur = 1;
    int k;
    int u;
    int v = 0;
    int p = 0;
    arrete* a = NULL;
    for(k = 0; k<n; k++)
    {
        u = extraire_min_tas(fp);
        s[u]->couleur = 1;
        temp = g->l[u]->deb;
        while(temp != NULL)
        {
            v = temp->n;
            p = temp->p;
            if(s[v]->couleur == 0 && p < s[v]->distance)
            {
                s[v]->distance = p;
                s[v]->pere = s[u];
                augmenter_cle_tas(fp,v,p);
            }
            temp = temp->suiv;
        }
    }
    detruireFileP(&fp);
    return s;
}

int min(sommet** s, int n)
{
    int min = inf;
    int ind = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        if(s[i]->couleur != 1 && s[i]->distance < min)
        {
            ind = i;
            min = s[i]->distance;
        }
    }
    return ind;
}

void afficherSommets(sommet** s, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(s[i]->pere != NULL)
        {
            printf("\n%d\n",i);
            printf("\n %d %d %d",s[i]->v, s[i]->pere->v, s[i]->distance);
        }
        else
        {
            printf("\n%d\n",i);
            printf("\n %d pas de pere %d",s[i]->v, s[i]->distance);
        }

    }
}

sommet** bellman_ford(graphe* g, int so)
{
    int n = g->n;
    sommet** s =(sommet**)malloc(sizeof(sommet*)*n);
    s[so] = creerSommet(0,0,NULL,0);
    int i;
    for(i = 0; i <n; i++)
    {
        if(i != so)
        {
            s[i] = creerSommet(0,inf,NULL,i);
        }
    }
    int fin = 0;
    cellule* temp = NULL;
    while(fin == 0)
    {
        fin = 1;
        for(i = 0; i < n; i++)
        {
            temp = g->l[i]->deb;
            while(temp != NULL)
            {
                if(s[i]->distance + temp->p < s[temp->n]->distance)
                {
                    s[temp->n]->distance = s[i]->distance + temp->p;
                    s[temp->n]->pere = s[i];
                    fin = 0;
                }
                temp = temp->suiv;
            }
        }
    }
    return s;
    //fonction afficherChemin pour voir le résultat
}

sommet** dijkstra(graphe* g, int so)
{
    int n = g->n;
    sommet** s =(sommet**)malloc(sizeof(sommet*)*n);
    int i;
    fileP* f = creerFileP(n);
    for(i = 0; i < n; i++)
    {
        s[i] = creerSommet(0,inf,s[so],i);
        if( i != so)
        {
            inserer_tas_min(f,i,inf);
        }
    }
    s[so] = creerSommet(1,0,NULL,so);
    inserer_tas_min(f,so,0);
    int u,j;
    cellule* temp = NULL;
    for(i = 1; i < n; i++)
    {
        u = extraire_min_tas(f);
        s[u]->couleur = 1;
        temp = g->l[u]->deb;
        printf("\n u %d\n",u);
        while(temp != NULL)
        {
            if(s[temp->n]->couleur == 0)
            {
                if(g->m[u][temp->n] < 0)
                {
                    printf("Erreur: poids négatif");
                    return NULL;
                }
                if(s[temp->n]->distance > s[u]->distance + g->m[u][temp->n])
                {
                    s[temp->n]->distance = s[u]->distance + g->m[u][temp->n];
                    inserer_tas_min(f,temp->n,s[temp->n]->distance);
                    s[temp->n]->pere = s[u];
                }
            }
            temp = temp->suiv;
        }
    }
    detruireFileP(&f);
    return s;
}

sommet*** dijkstra_complet(graphe* g)
{
    int i;
    int n = g->n;
    sommet*** s = (sommet***)malloc(sizeof(sommet**)*n);
    for(i = 0; i < n; i++)
    {
        s[i] = dijkstra(g,i);
    }
    return s;
}

void afficherDijkstraComplet(graphe* g, sommet*** s)
{
    int i;
    int n = g->n;
    for(i = 0; i < n; i++)
    {
        afficherChemins(g,s[i],i);
    }
}

void afficherChemins(graphe* g, sommet** s, int so)
{
    int i;
    int n = g->n;
    for(i = 0; i < n; i++)
    {
        if(i != so)
        {
            printf("\n Chemin entre %d et %d\n",so,i);
            afficherChemin(g, s[so], s[i]);
        }
    }
}

