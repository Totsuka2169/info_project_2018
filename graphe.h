#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "listes.h"




int construire_graphe(GRAPHE* graphe, char* nom_fic);

void voisins(SOMMET* sommet, GRAPHE graphe);

SOMMET* trouver(char* nom, GRAPHE graphe);

void visualiser_graphe(GRAPHE graphe);

void affiche_voisins(char* nom, GRAPHE graphe);


#endif
