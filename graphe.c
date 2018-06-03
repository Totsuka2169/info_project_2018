#include "graphe.h"


//Dans ce fichier se trouve la fonction qui ouvre le fichier, lit ses valurs, et construit les graphe correspondant
//Il y a égalementune deuxième fonciton qui permet d'afficher le graphe sur demande del'utilisateur


int construire_graphe(GRAPHE* graphe, char* nom_fic) {												  //Renvoie 1 en cas de succès

	FILE* route = fopen(nom_fic, "r");                                            // On ouvre le fichier
	if(route == NULL) {                                                           // Si rien dans le fichier texte
		printf("Le fichier %s semble vide, ERREUR \n", nom_fic);                    // On annonce l'erreur
		return 0;                                                     					    // On renvoie 0
	}

	//Lecture du fichier
	int nb_sommet, nb_axe;																												//On crée les variables qui nous serviront pas la suite
	int depart, arrivee;
	double cout;
	int i, j;
	char titre[512];
	int numero;
	double longi, lat;
	char line[128];
	fscanf(route,"%d %d", &(nb_sommet), &(nb_axe));																//On lit le nombre de sommets et d'axes.
	fgets(titre, 511, route); 																										//Lecture de la ligne inutile (Sommets du graphe)

	graphe->tab=calloc(nb_sommet, sizeof(SOMMET*));																//On alloue de la mémoire pour le graphe
	graphe->taille_tab=nb_sommet;
	if (graphe->tab==NULL) {																											//On vérifie que l'allocation s'est bien déroulée
		printf ("Erreur d'allocation du graphe \n");
		return 0;
	}

	//Je dois lire la première ligne de sommet avant la boucle for, pour ne pas crée d'erreur
	fscanf(route, "%d %lf %lf %s", &(numero), &(lat), &(longi), line);						//On lit les valeurs des sommets, et on les met dans les variables correspondantes
	fgets(titre, 511, route);																											//Lecture de la dernière chaîne de caractère qui peut présenter des espaces
	for (i=0; i<nb_sommet; i++) {																									//Pour lire toutes les lignes de sommets.
		fscanf(route, "%d %lf %lf %s", &(numero), &(lat), &(longi), line);					//On lit les valeurs de sommet
		fgets(titre, 511, route);
		if (titre[strlen(titre)-1]<32) {titre[strlen(titre)-1]=0;}									//Gestion du caractère espace
		//Il faut maintenant utiliser ces données.
		(graphe->tab)[i] = creer_sommet(numero, lat, longi, line);									//On crée un sommet correspondant aux valeurs lues
	}

	fgets(titre, 511, route);																											//Lecture de la ligne inutile (Arrêtes du graphe)
	for (j=0; j<nb_axe; j++) {																										//Pour tous les axes du fichier
		fscanf(route, "%d %d %lf", &(depart), &(arrivee), &(cout));									//On lit les valeurs de l'axe
		//Il faut maintenant utiliser ces données.
		ARC nv_arc = creer_arc(arrivee, cout);																			//On crée l'arc correpsondant puis on l'ajoute à la liste des voisins
		(graphe->tab)[depart].voisins = ajout_tete((graphe->tab)[depart].voisins, nv_arc);
		while (fgetc(route) != '\n') {}																							//saut de ligne
	}

	if (route != NULL) {																													//Fermeture du chier si son pointeur n'est pas NULL
		//fclose(route);
	}

	return 1;																																			//On retourne 1 : le programme s'est bien déroulé
}



void visualiser_graphe(GRAPHE graphe) {																					//Fonction de visualisation du graphe
	int i;
	printf("Visualisation du graphe : \n");
	for(i=0; i<graphe.taille_tab; i++) {                             					  	// On parcourt le graphe
	  visualiser_liste((graphe.tab)[i]);																					//Fonction de visualisation du sommet et de ses voisins
	}
	printf("\n \n");																															//On saute deux lignes pour plus de clarté
}
