#include "arbreInter.h"
#include "pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

noeud* rechercherNoeudRecursif(noeud* n,char* m)
{
    if(strcmp(m,n->mot) == 0)
    {
        return n;
    }
    else
    {
        if(strcmp(m,n->mot) < 0 && n->gauche!=NULL)
        {
            return rechercherNoeudRecursif(n->gauche,m);
        }
        if(strcmp(m,n->mot) >= 0 && n->droit!=NULL)
        {
            return rechercherNoeudRecursif(n->droit,m);
        }
        else if(n->gauche==NULL)
        {
            return NULL;
        }
    }
    return NULL;
}

noeud* rechercherNoeudIteratif(noeud* n,char* m)
{
    noeud* temp = n;
    while(temp != NULL && strcmp(m, temp->mot) != 0)
    {
        if(strcmp(m, temp->mot) < 0)
        {
            temp = temp->gauche;
        }
        else
        {
            temp = temp->droit;
        }
    }
    return temp;
}

void transplanter(arbre* a,noeud* u, noeud* v)
{
    if(u->pere == NULL)
    {
        a->racine = v;
    }
    else if(u == u->pere->gauche)
    {
        u->pere->gauche = v;
    }
    else
    {
        u->pere->droit = v;
    }
    if(v!=NULL)
    {
        v->pere = u->pere;
    }
}

void supprimerNoeud(arbre* a,noeud* z)
{
    if(z->gauche == NULL)
    {
        transplanter(a,z,z->droit);
        detruireNoeud(&z);
    }
    else if(z->droit == NULL)
    {
        transplanter(a,z,z->gauche);
        detruireNoeud(&z);
    }
    else
    {
        noeud* y = minimumArbre(z);
        if(y->pere != z)
        {
            transplanter(a,y,y->droit);
            y->droit = z->droit;
            y->droit->pere = z->droit;
            transplanter(a,z,y);
            y->gauche = z->gauche;
            y->gauche->pere = y;
            detruireNoeud(&z);
        }
    }

}

noeud* minimumArbre(noeud* x)
{
    noeud* temp = x;
    while(temp->gauche!=NULL)
    {
        temp = temp->gauche;
    }
    return temp;

}

noeud* maximumArbre(noeud* x)
{
    noeud* temp = x;
    while(temp->droit != NULL)
    {
        temp = temp->droit;
    }
    return temp;
}

noeud* successeurArbre(noeud* x)
{
    if(x->droit !=NULL)
    {
        return minimumArbre(x->droit);
    }
    else
    {
        noeud* y = x->pere;
        noeud* temp = x;
        while(y!=NULL && temp==y->droit)
        {
            temp = y;
            y = y->pere;
        }
        return y;
    }
}

void afficherNoeudRecursif(noeud* n)
{
    if(n!=NULL)
    {
        printf("\n%s %d\n",n->mot,n->occurrence);
        afficherNoeudRecursif(n->gauche);
        afficherNoeudRecursif(n->droit);
    }

}

void afficherNoeudIteratif(noeud* a)
{
    pile* p = creerPile();

    noeud* n = NULL;
    if(a != NULL)
    {
        empiler(p, a);
        while(!pileVide(p))
        {
            n = depiler(p);
            printf("\n%s %d\n", n->mot, n->occurrence);
            if(n->droit != NULL)
            {
                empiler(p,n->droit);
            }
            if(n->gauche != NULL)
            {
                empiler(p, n->gauche);
            }
        }
    }
}
