#ifndef _UTIL_H_
#define _UTIL_H_


int* lire(char* f, int* n);
int* creerTab(int n);
int* copie(int* tab, int n);
int* fusion(int* tab1, int n1, int* tab2, int n2);
void fusion2(int* tab,int n, int d, int p, int f);
void temp_execution_insertion(int n);
void temp_execution_tas(int n);
void temp_execution_fusion(int n);
void temp_execution_rapide(int n);
void temp_execution_bulle(int n);
void comparaison_tri(int d,int max, int pas);
void copie_string(char* s1, char* s2, int n);


#endif // _UTIL_H_
