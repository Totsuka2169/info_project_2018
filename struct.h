#ifndef __STRUCT_H_
#define __STRUCT_H_



typedef struct L_ARC* L_SOMMET;																									//Liste des voisins

typedef struct SOMMET SOMMET;																										//Structure sommet
struct SOMMET {																																	//Caractéristiques du sommet
	int num;																																			//Numéro du sommet
	double x, y;																																	//Longitude Latitude
	char nom[128];																																//Nom du sommet
	struct L_ARC* voisins;																												//Liste des voisins
	int PCC;																																			//Poids dans le chemin PCC
	int passage;																																	//Valeur binaire pour savoir si on passe par le sommet ou non
	struct SOMMET* pere;																													//Pointeur sur le sommet précédant dans le chemin
};


typedef struct ARC ARC;																													//Structure arc
struct ARC {
	int arrivee;																																	//Numéro du sommet voivin
	double cout;																																	//Coût (longueur) de l'arc
};


struct L_ARC {																																	//Liste des voisin, liste d'arcs
	ARC val;																																			//Arc
	struct L_ARC* suiv;																														//Pointeur sur l'arc suivant dans la liste
};



typedef struct GRAPHE GRAPHE;																										//Structure Graphe
struct GRAPHE {
	SOMMET* tab;																																	//Tableau de sommets
	int taille_tab;																																//Taille du tableau (nombre de sommets)
};



#endif
