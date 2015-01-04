#ifndef _PILE_H_
#define _PILE_H_

struct pile
{
    int* t;
    int capacite;
    int taille;
};

typedef struct pile pile;

pile* creerPile(int n);
void detruirePile(pile* p);
int capacitePile(pile* p);
int pileVide(pile* p);
int pilePleine(pile* p);
void empiler(pile* p,int a);
int depiler(pile* p);
int sommet(pile* p);
int taillePile(pile* p);

#endif // _PILE_H_
