#ifndef _HANOI_H_
#define _HANOI_H_

#include "pile.h"

struct hanoi
{
    pile** p;
    int n;
};

typedef struct hanoi hanoi;

hanoi* creerHanoi(int n);
void afficherHanoi(hanoi* h);
void afficherHanoi2(hanoi* h);
int deplacerDisque(hanoi* h, int tourDepart, int tourArrivee);
int gagne(hanoi* h);
void hanoiAutomatique(int n,int t);
void jouer(int n);
char *afficherDisque(char *chaine, int tailleTours, int valDisque);
int simulationDeplacement(hanoi* h,int d, int a);

#endif // _HANOI_H_
