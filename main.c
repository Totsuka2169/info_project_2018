#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>
#include "listes.h"
#include "struct.h"
#include "dijkstra.h"
#include "main.h"

//Fonction main qui contient notamment le menu textuel


int main(int argc, char const *argv[]) {

	GRAPHE* graphe = calloc(1,sizeof(GRAPHE));                                    // On crée un graphe et on lui alloue de la mémoire
  int depart, arrivee;                                                          // On crée les variables départ et arrivée
  char* file = "graphe2.txt";                                                   //On définit ici le fichier à lire.



	if(construire_graphe(graphe, file) != 1) {                                    // Si la construction du graphe n'a pas renvoyé 1
		printf("Erreur, le graphe n'a pas pu être constuit !\n");                   // Alors il y a une erreur : on l'affiche
		return EXIT_FAILURE;                                                        // On arrête le programme
	}

    while(1) {                                                                  // On crée un "menu" d'options du programme, sur les valeurs de 'menu' (cf fonction)
        switch(menu()) {
            case 0 :
                printf("Vous allez quitter le programme. \n")   ;               // Cas 0 : Quitter le programme
                return 0;                                                       // On retourne 0
                break;

                case 1 :                                                        // Cas 1 : afficher le graphe
                printf("GRAPHE du fichier : \n");
                visualiser_graphe(*graphe);                                     // On affiche le graphe
                break;

                case 2 :                                                        // Cas 2 : Calcul du chemin le plus court
                printf("Numéro du sommet de départ ? \n");                      // On demande le sommet de départ
                scanf("%d", &depart);                                           // On récupère la valeur saisie au clavier

                printf("Numéro du sommet d'arrivée ? \n");                      // On demande le sommet d'arrivée
                scanf("%d", &arrivee);
                                                        //On récupère la valeur saisie au clavier
                dijkstra(depart, arrivee, graphe);                              // On lance l'algorithme de calcul du plus court chemin
                break;

            default :
                break;
        }
    }
    return 1;
}



// Cette fonction affiche le menu et renvoie un choix valide
int menu()
{
    int choix;                                                                  // Entier pour stocker notre choix

    printf("Choisissez une proposition :\n");                                   // On fait l'affichage des différentes options
    printf("\t1 : Affichage du graphe correspondant au fichier\n");             // Afficher le graphe
    printf("\t2 : Calcul du chemin le plus court entre deux sommets\n");        // Calcul du chemin le plus court
    printf("\t0 : Quitter le programme\n");                                     // Sortie du programme

    do {
        printf("Votre choix :");                                                // On demande à l'utilisateur de faire son choix
        scanf("%d", &choix);                                                    // On stocke la réponse utilisateur dans 'choix'
        printf("\n");

        if(choix < 0 || choix > 2) {                                            // Si on n'est pas sur une des options proposées
            printf("Choix invalide\n");                                         // On l'indique
        }
    } while(choix < 0 && choix > 2);                                            // On boucle de manière à avoir une option de sélectionnée

    return choix;                                                               // On renvoie 'choix', qui correspond à l'option choisie par l'utilisateur
}
