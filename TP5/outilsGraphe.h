#include <stdio.h>
#include "graphe.h"


sommet** parcoursLargeurListe(graphe* g, sommet* s);
void afficherChemin(graphe* g, sommet* s, sommet* v);
void exporterMatrice(char* f, graphe* g);
void exporterListe(char* s, graphe* g);
void exporterChemin(char* s_, graphe* g, sommet* s, sommet* v);
void exporterCheminInter(FILE* f, graphe* g, sommet* s, sommet* v);
void visiterppListe(graphe* g, sommet* u, int* date, sommet** s);
void visiterppTri(graphe* g, sommet* u, int* date, sommet** s, liste* l);
sommet** parcoursProfondeurListe(graphe* g);
liste* triTopologique(graphe* g);
void afficherDate(sommet** s, int n);
arrete** arretesGraphes(graphe* g, int* n);
listeArrete* genererAcpmKruskal(graphe* g);
sommet** genererAcpmPrim(graphe* g);
void afficherSommets(sommet** s, int n);
sommet** bellman_ford(graphe* g, int so);
sommet** dijkstra(graphe* g, int so);
void afficherChemins(graphe* g, sommet** s, int so);
sommet*** dijkstra_complet(graphe* g);
void afficherDijkstraComplet(graphe* g, sommet*** s);

