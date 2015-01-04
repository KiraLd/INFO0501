#ifndef _TAS_H_
#define _TAS_H_
#include "types.h"

struct tas{
    int taille;
    int longueur;
    int* tab;
    char** taches;
};
typedef struct tas tas;



int parent(int i);
int gauche(int i);
int droite(int i);
void entasserMax(tas* t, int i);
void construireTasMax(tas* t);
tas* creerTas(int n);
void afficher_tas(tas* t);
tas* test_tas(int n);

struct file_priorite{
    tas* t;
};

typedef struct file_priorite fileP;

fileP* lire_tache(char* f);
fileP* creerFileP(int n);
fileP* construireFileP(fileP* f);
fileP* afficherFileP(fileP* f);
int extraire_max_tas(fileP* f);
void augmenter_cle_tas(fileP* f,int i, int cle);
void inserer_tas_max(fileP* f, int cle, char* t);


#endif // _TAS_H_
