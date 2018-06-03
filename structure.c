#include "structure.h"

//Dans ce fichier se trouvent les différentes fonctions de gestions des listes et structures
//Création de structures, ajout en tête, suppression d'élément, ...


void visualiser_liste(T_SOMMET s) {
	T_SOMMET p = s;									//Sommet de travail
	L_ARC v = p.voisins;								//Pointeur sur le premier voisin
	printf("Sommet %d relié à ", p.num);                                          //On affiche le sommet (son numéro)
	while(v != NULL) {                                         			// Tant qu'on n'a pas atteint le dernier voisin
		printf("%d (%lf), ",v->val.arrivee, v->val.cout);                          //On affiche l'arc (numéro du voisin et coût du trajet)
		v=v->suiv;                                           			  // On passe au voisin suivant
	}
	printf("\n");                                               			// Retour à la ligne pour la lisibilité
}


//Libère une liste allouée dynamiquement
void liberer_liste(L_ARC L)
{
	while(L != NULL) {                                         			// Tant que la liste n'est pas vide
		L = supprimer_tete(L);                                  		// Suppression de l'élément en tête
	}
}

// Crée un sommet correspondant à la station lue dans le fichier
//T_SOMMET creer_sommet(int numero, double lat, double longi, char* line) {
//	T_SOMMET* sommet = calloc(1, sizeof(*sommet));                			// On crée un pointeur sur un SOMMET et lui alloue de la mémoire
//	sommet->num = numero;                                  				// On ajoute le numéro du sommet
//	sommet->x = lat;                                  				// On ajoute la latitude
//	sommet->y = longi;                                  				// On ajoute la longitude
//	strcpy(sommet->nom, line);                                  			// On ajoute le nom
//	sommet->PCC = 0;                                            			// Initialisation du PCC
//	sommet->pere = NULL;                                        			// Initialisation arbitraire du père à NULL (pour le passage dans un tas)
//	sommet->voisins = NULL; 							// Initialisation de la liste des voisins
//	sommet->passage = 0;                                     			//Initialisation du passage à 0
//	return *sommet;                                            			// On renvoie le *SOMMET créé
//}

// Crée un sommet correspondant à la station lue dans le fichier
T_SOMMET creer_sommet(int numero, double lat, double longi, char* line) {
	T_SOMMET* sommet = calloc(1, sizeof(*sommet));                			
	sommet->num = numero;                                  				
	sommet->x = lat;                                  				
	sommet->y = longi;                                  				
	strcpy(sommet->nom, line);                                  			                                 
	sommet->voisins = NULL; 							                                     			
	return *sommet;                                            			
}

T_ARC creer_arc(int arrivee, double cout) {						//Fonction de création d'un arc
	T_ARC arc;
	arc.arrivee = arrivee;								//On affecte les valeurs correspondantes
	arc.cout = cout;
	return arc;									//On renvoie l'arc crée
}

// Ajoute un élément contenant un pointeur sur un SOMMET à une liste
L_ARC ajout_tete(L_ARC L, T_ARC nv_arc) {
	L_ARC p = calloc(1, sizeof(*p));                         			// On alloue de la mémoire à la liste de voisins
	if(p == NULL) {                                             			// Si l'allocation est ratée
		printf("Ajout impossible\n");                           		// On affiche l'erreur
		return NULL;                                            		// On renvoie NULL
	}
	p->val = nv_arc;                                             			//L'ajout est un arc, on remplit la valeur de cet arc
	p->suiv = L;                                                			//On fait pointer sur la L_SOMMET L pour placer l'élément en tête
	return p;                                                   			//On renvoie la nouvelle liste
}

// Supprime l'élément en tête d'un liste
L_ARC supprimer_tete(L_ARC L) {
	L_ARC q;                                                			// On crée une L_SOMMET
	if(L == NULL) {                                            			// Si la L_SOMMET était déjà vide
		return NULL;                                            		// On renvoie NULL
	}
	q = L->suiv;                                              			// Sauvegarde de l'adresse du deuxième élément (potentiellement NULL)
	free(L);                                                    			// Libération de la mémoire du premier élément
	return q;                                                 			// On renvoie q (donc la L_SOMMET initiale sans l'élément de tête)
}

T_SOMMET* creer_chemin(T_SOMMET s) {							//Fonction de création d'un chemin
	T_SOMMET* chemin = calloc(1, sizeof(*chemin));					//On alloue de la mémoire
	return NULL;									//On renvoie NULL
}

T_SOMMET* ajout_tete_chemin(T_SOMMET* chemin, T_SOMMET nv_sommet) {				//Fonction d'ajout en tête pour un chemin
	T_SOMMET* p = calloc(1, sizeof(*p));						//On alloue de la mémoire à un sommet
	if(p == NULL) {                                             			// Si l'allocation est ratée
		printf("Ajout impossible\n");						//On affiche l'erreur
		return NULL;								//On retourne NULL
	}
	p->num = nv_sommet.num;								//assignation des valeurs du sommet
	p->x = nv_sommet.x;
	p->y = nv_sommet.y;
	p->PCC = nv_sommet.PCC;
	p->passage = nv_sommet.passage;
	p->voisins = nv_sommet.voisins;
	strcpy(p->nom, nv_sommet.nom);
	p->pere = chemin;								//On pointe sur la liste, ce qui ajoute le nouvel élément en tête
	return p;									//On retourne le nouveau chemin
}
