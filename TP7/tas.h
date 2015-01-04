#ifndef _TAS_H_
#define _TAS_H_
#include "types.h"

struct tas{
    int taille;
    int longueur;
    int* tab;
    int* ind;
};
typedef struct tas tas;



int parent(int i);
int gauche(int i);
int droite(int i);
void entasserMin(tas* t, int i);
void construireTasMin(tas* t);
tas* creerTas(int n);
void afficher_tas(tas* t);
tas* test_tas(int n);
void detruireTas(tas** t);

struct file_priorite{
    tas* t;
};

typedef struct file_priorite fileP;
;
fileP* creerFileP(int n);
fileP* construireFileP(fileP* f);
fileP* afficherFileP(fileP* f, int i);
int extraire_min_tas(fileP* f);
void augmenter_cle_tas(fileP* f,int cle, int ind);
void inserer_tas_min(fileP* f, int cle, int ind);
int rechercherTas(fileP* f, int cle);
void detruireFileP(fileP** f);


#endif // _TAS_H_
