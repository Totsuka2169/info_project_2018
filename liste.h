#ifndef __LISTE_H_
#define __LISTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

L_SOMMET creer_liste();

void liberer_liste(L_SOMMET L);

SOMMET creer_sommet(int numero, double lat, double longi, char* line);

ARC creer_arc(int arrivee, double cout);

L_SOMMET ajout_tete(L_SOMMET L, ARC nv_arc);

L_SOMMET supprimer_tete(L_SOMMET L);

void visualiser_liste(SOMMET s);


SOMMET* creer_chemin(SOMMET s);

SOMMET* ajout_tete_chemin(SOMMET* chemin, SOMMET nv_sommet);


#endif
