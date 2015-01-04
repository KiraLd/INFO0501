#ifndef _TABLEHACHAGE_H_
#define _TABLEHACHAGE_H_
#include "outilsListe.h"
struct hachage
{
    int n;
    liste** l;
};

typedef struct hachage tableHachage;

tableHachage* creerTableHachage(int n);
void detruireTableHachage(tableHachage* h);

#endif /* _TABLEHACHAGE_H_*/
