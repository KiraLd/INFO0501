#ifndef _NOEUD_H_
#define _NOEUD_H_

struct noeud
{
    int occurrence;
    struct noeud* pere;
    struct noeud* gauche;
    struct noeud* droit;
    char* mot;
};

typedef struct noeud noeud;

noeud* creerNoeud(char* m);
void detruireNoeud(noeud** n);

#endif /* _NOEUD_H_*/
