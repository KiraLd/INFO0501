#include "hanoi.h"
#include "outilsPile.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hanoi* creerHanoi(int n)
{
    hanoi* h = (hanoi*) malloc(sizeof(hanoi));
    h->n = n;
    h->p = (pile**) malloc(sizeof(pile*) * 3);
    h->p[0] = creerPile(n);
    int i;
    for(i = n ; i > 0 ; i--)
    {
        empiler(h->p[0],i);
    }
    h->p[1] =creerPile(n);
    h->p[2] = creerPile(n);
    return h;
}

void afficherHanoi(hanoi* h)
{
    printf("Etat actuel:\n");
    printf("Tour 1:\n");
    afficherPile(h->p[0]);
    printf("Tour 2:\n");
    afficherPile(h->p[1]);
    printf("Tour 3:\n");
    afficherPile(h->p[2]);
}

int deplacerDisque(hanoi* h, int tourDepart, int tourArrivee)
{
    if(tourDepart > 0 && tourArrivee > 0 && tourDepart < 4 && tourArrivee < 4)
    {
        if(tourDepart != tourArrivee)
        {
            if(h->p[tourArrivee - 1]->taille < h->n)
            {
                if(h->p[tourDepart - 1]->taille > 0)
                {
                    if(sommet(h->p[tourDepart - 1]) < sommet(h->p[tourArrivee - 1]) || pileVide(h->p[tourArrivee - 1]))
                    {
                        empiler(h->p[tourArrivee - 1],depiler(h->p[tourDepart - 1]));
                        return 1;
                    }
                    else
                    {
                        //disque trop grand
                        return 0;
                    }
                }
                else
                {
                    //tour de départ vide
                    return -1;
                }
                //tour d'arrive pleine
                return -2;
            }
            //tours identiques, pas de déplacement nécéssaire
            return -3;
        }
    }
    else
    {
        //indices non valide
        return -4;
    }
}

int gagne(hanoi* h)
{
    return pilePleine(h->p[1])||pilePleine(h->p[2]);
}

void hanoiAutomatique(int n,int t)
{
    hanoi* h = creerHanoi(n);
    int i = 0;
    int d,a;
    int* p;
    int k = 0;
    while(!gagne(h))
    {
        if(t != 0)
        {

            afficherHanoi2(h);
            printf("Deplacement: %d\n",k + 1);
        }
       // printf("\n");
        if(i % 3 == 0)  //4
        {
            if(simulationDeplacement(h,1,3) > 0)
            {
                d = 1;
                a = 3;
            }
            else
            {
                d = 3;
                a = 1;
            }
        }
        else if(i % 3 == 1) //3
        {
            if(simulationDeplacement(h,1,2)>0)
            {
                d=1;
                a=2;
            }
            else
            {
                d=2;
                a=1;
            }
        }
        else        //5
        {
            if(simulationDeplacement(h,3,2) > 0)
            {
                d = 3;
                a = 2;
            }
            else
            {
                d = 2;
                a = 3;
            }
        }
        deplacerDisque(h,d,a);
        i++;
        sleep(t);
        k++;
    }
    if(t != 0)
    {
        afficherHanoi2(h);
    }
    printf("\nNombre de deplacements: %d",k);
}

void jouer(int n)
{
    hanoi* h = creerHanoi(n);
    int d,a,r,k;
    k = 0;
    while(!gagne(h))
    {
        printf("Deplacement: %d\n",k + 1);
        printf("\n\n");
        afficherHanoi2(h);
        printf("\nTour de depart:\n");
        scanf("%d",&d);;
        printf("\nTour d'arrivee\n\n");
        scanf("%d",&a);
        r = deplacerDisque(h,d,a);
        k++;
    }
    printf("\nNombre de deplacement: %d\n",k);
}

void afficherHanoi2(hanoi* h)
{
    int i, j;
	char chaine[50];
	pile **toursTemp = (pile **) malloc(sizeof(pile *) * 3);

	for (i = 0; i < 3; i++) {
		toursTemp[i] = copierPile(h->p[i]);
	}

	for (i = 0; i < 100; i++)
		printf("\n");
	for (i = 0; i < h->n; i++) {
		for (j = 0; j < 3; j++) {
			if (i < h->n - taillePile(h->p[j])) {
				printf("%s", afficherDisque(chaine, h->n, 0));
			}
			else {
				printf("%s", afficherDisque(chaine, h->n, depiler(toursTemp[j])));
			}
		}
		printf("\n");
	}
	for (i = 0; i < (h->n * 2 + 1) * 3; i++);
		printf("\n");
	for (i = 0; i < 3; i++) {
		detruirePile(toursTemp[i]);
	}

	free(toursTemp);
}

char *afficherDisque(char *chaine, int tailleTours, int valDisque) {
	int i;
	strcpy(chaine, "");
	for (i = 0; i < tailleTours - valDisque; i++)
		strcat(chaine, " ");
	for (i = 0; i < valDisque; i++)
		strcat(chaine, "*");
	strcat(chaine, " ");
	for (i = 0; i < valDisque; i++)
		strcat(chaine, "*");
	for (i = 0; i < tailleTours - valDisque; i++)
		strcat(chaine, " ");
	return chaine;
}

int simulationDeplacement(hanoi* h,int tourDepart, int tourArrivee)
{
    if(tourDepart>0&&tourArrivee>0&&tourDepart<4&&tourArrivee<4)
    {
        if(tourDepart!=tourArrivee)
        {
            if(h->p[tourArrivee-1]->taille<h->n)
            {
                if(h->p[tourDepart-1]->taille>0)
                {
                    if(sommet(h->p[tourDepart-1])<sommet(h->p[tourArrivee-1])||pileVide(h->p[tourArrivee-1]))
                    {
                        return 1;
                    }
                    else
                    {
                        //disque trop grand
                        return 0;
                    }
                }
                else
                {
                    //tour de départ vide
                    return -1;
                }
                //tour d'arrive pleine
                return -2;
            }
            //tours identiques, pas de déplacement nécéssaire
            return -3;
        }
    }
    else
    {
        //indices non valide
        return -4;
    }
}
