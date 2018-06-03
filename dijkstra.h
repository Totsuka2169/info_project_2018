#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "graphe.h"
#include "listes.h"

void dijkstra(int depart, int arrivee, GRAPHE* graphe);

void init_dijkstra(GRAPHE* graphe, int depart);

int min_PCC(GRAPHE* graphe);

SOMMET* chemin_dijkstra(GRAPHE* graphe, int arrivee);

void visualiser_chemin(SOMMET* chemin, int dist);

#endif
