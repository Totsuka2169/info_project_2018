#ifndef __STRUCTURE_H_
#define __STRUCTURE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//typedef struct SOMMET SOMMET;			//Structure sommet
//struct SOMMET {				//Caractéristiques du sommet
//	int num;				//Numéro du sommet
//	double x, y;				//Longitude Latitude
//	char nom[128];				//Nom du sommet
//	struct L_ARC* voisins;			//Liste des voisins
//	int PCC;				//Poids dans le chemin PCC
//	int passage;				//Valeur binaire pour savoir si on passe par le sommet ou non
//	struct SOMMET* pere;			//Pointeur sur le sommet précédant dans le chemin
//};

typedef struct { 					
	int num;				
	double x, y;				
	char nom_ligne[128];				
	L_ARC voisins;			
} T_SOMMET;					


//typedef struct ARC ARC;			//Structure arc
//struct ARC {
//int arrivee;					//Numéro du sommet voivin
//	double cout;				//Coût (longueur) de l'arc
//};

typedef struct {
	int arrivee;				
	double cout;			
} T_ARC;


//struct L_ARC {					//Liste des voisin, liste d'arcs
//	ARC val;				//Arc
//	struct L_ARC* suiv;			//Pointeur sur l'arc suivant dans la liste
//};

typedef struct lsucc{					
	T_ARC val;				
	struct lsucc* suiv;			
} * L_ARC;


//typedef struct GRAPHE GRAPHE;			//Structure Graphe
//struct GRAPHE {
//	SOMMET* tab;				//Tableau de sommets
//	int taille_tab;				//Taille du tableau (nombre de sommets)
//};

typedef struct {
	T_SOMMET* tab;				
	int taille_tab;				
} GRAPHE ;





void liberer_liste(L_ARC L);

T_SOMMET creer_sommet(int numero, double lat, double longi, char* line);

T_ARC creer_arc(int arrivee, double cout);

L_ARC creer_liste();

int est_vide (L_ARC L);

L_ARC ajout_tete(L_ARC L, T_ARC nv_arc);

L_ARC supprimer_tete(L_ARC L);

void visualiser_liste(T_SOMMET s);


T_SOMMET* creer_chemin(T_SOMMET s);

T_SOMMET* ajout_tete_chemin(T_SOMMET* chemin, T_SOMMET nv_sommet);

#endif
