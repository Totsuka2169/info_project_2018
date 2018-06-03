#include "dijkstra.h"
#define INF 0x7FFFFFFF                                                          //valeur infinie (plus grand entier)


//Dans ce fichier sont consignées les foncitons qui réalisent le plus court chemin en utilisant l'algorithme de Dijkstra.
//Il y a également une fonction qui affiche le chemin le plus court, une fois calculé
//Initialisation des varialbes du graphe,  calcul du plus court chemin, coustruction du chemin, affichage du chemin


void dijkstra(int depart, int arrivee, GRAPHE* graphe) {

  //Conditions de départ
  if (depart < 0 || depart >= graphe->taille_tab || arrivee < 0 || arrivee >= graphe->taille_tab) {
    printf ("Départ et/ou arrivée hors du graphe ! \n");                        //Erreur sur les sommets entrés par l'utilisateur
    return ;                                                                    //Fonction void donc on ne retourne rien
  }
  //initialisation de l'algorithme
  init_dijkstra(graphe, depart);


  int compteur = 0;                                                             //On crée toutes les variables utiles
  int ind = 0;                                                                  //Indice du voisin sur lequel on va travailler
  int indice = 0;                                                               //Indice du sommet validé sur lequel on va travailler
  int pcc_test;                                                                 //PCC calculé pour un sommet sur un chemin. On le garde que s'il est minimum
  SOMMET* pointeur = NULL;                                                      //Pointeur sur le dernier sommet validé
  pointeur = &((graphe->tab)[depart]);                                          //Pointeur du dernier sommé validé (passage=1)
  indice = pointeur->num;                                                       //On lui affecte l'indice correspondant pour le retrouver dans le graphe
  pointeur->passage = 1;                                                        //On passe par le sommet choisi, donc passage=1

  //On démarre l'algorithme
  while (pointeur != &((graphe->tab)[arrivee]) && compteur < graphe->taille_tab) {  //Tant qu'on n'est pas arrivé.
    compteur++;                                                                 //Pour vérifier qu'on n'est pas dans un impasse ou une boucle infinie
    L_SOMMET fleche = pointeur->voisins;                                        //On pointe le premier voisin du sommet de travail (ici le départ)
    while (fleche != NULL) {                                                    //Tant qu'il reste des voisins
      ind = fleche->val.arrivee;                                                //Indice du sommet sur lequel on va travailler
      //pointeur désigne un potentiel sommet pere pour ce voisin
      pcc_test = pointeur->PCC + fleche->val.cout;                              //On définit les PCC (dans ce cas) des voisins du sommet choisi.
      if (pcc_test < (graphe->tab)[ind].PCC) {                                  //Si le PCC calculé est plus petit que l'ancien PCC de ce sommet
        (graphe->tab)[ind].PCC = pcc_test;                                      //On actualise le PCC
        (graphe->tab)[ind].pere = pointeur;                                     //On définit un père
      }
      fleche = fleche->suiv;                                                    //On pointe sur le voisin suivant
    }
    indice = min_PCC(graphe);                                                   //min_PCC retourne l'indice du sommet au PCC min dans le graphe, avec passage=0
    pointeur = &((graphe->tab)[indice]);                                        //On pointe le nouveau sommet au PCC min
    pointeur->passage = 1;                                                      //On valide le sommet choisi. Il ne comptera plus dans le calcul de min_PCC
  }
  int dist = (graphe->tab)[arrivee].PCC;                                        //On retient la distance parcourue (la plus courte)

  SOMMET* chemin = chemin_dijkstra(graphe, arrivee);                            //On crée le chemin correspondant

  visualiser_chemin(chemin, dist);                                              //On affiche le plus court chemin
}




void init_dijkstra(GRAPHE* graphe, int depart) {                                //Fonction d'initialisation des variables des sommets
  int i;
  SOMMET* pointeur = NULL;                                                      //Pointeur sur le sommet de travail
  for (i = 0; i < graphe->taille_tab; i++) {                                    //On parcourt tout le graphe
    pointeur = &((graphe->tab)[i]);                                             //On pointe sur un sommet du graphe
    pointeur->PCC = INF;                                                        //Valeur infinie au début (pour être sûr de calculer un PCC plus petit par la suite)
    pointeur->pere = NULL;                                                      //Aucun prédécesseur car aucun calcul de fait
    pointeur->passage = 0;                                                      // On est encore passé par aucun sommet
  }
  (graphe->tab)[depart].PCC = 0;                                                //On fixe le PCC du départ à 0
  (graphe->tab)[depart].passage = 1;                                            //On valide le sommet départ car on passe par lui
}                                                                               //Fin de l'initialisation



int min_PCC(GRAPHE* graphe) {                                                   //Fonction qui regarde quel sommet a le plus petit PCC, et peut donc être validé
  int i;
  int min = INF;                                                                //Minimum infini pour démarrer
  int ind;                                                                      //Indice du sommet au PCC minimum qu'on retournera
  SOMMET* arrow = NULL;                                                         //Pointeur sur le sommet de travail.
  for (i=0; i<graphe->taille_tab; i++) {                                        //On parcourt le graphe
    arrow = &((graphe->tab)[i]);                                                //On pointe le sommet i du graphe
    if (arrow->PCC < min && arrow->passage == 0) {                              //Si PCC min et sommé non validé.
      ind = arrow->num;                                                         // arrow->num=i = indice du sommet au PCC min
      min = arrow->PCC;                                                         //On actualise le min
    }
  }
  return ind;                                                                   //On retourne l'indice du sommet avec le PCC min
}

SOMMET* chemin_dijkstra(GRAPHE* graphe, int arrivee) {                          //Fonction de création de la liste chemin
  SOMMET* chemin = &((graphe->tab)[arrivee]);                                   //On obtient les informations de arrivée avec un pointeur sur pere
  SOMMET* circuit = creer_chemin((graphe->tab)[arrivee]);                       //Chemin que l'on retournera. On l'initialise sur NULL
  SOMMET* fleche = chemin;                                                      //Pointeur de navigation dans le chemin
  while (fleche != NULL) {                                                      //Tant qu'il reste des sommets sur le chemin
    SOMMET nv_sommet;                                                           //On définit un nouveau sommet avec les paramètres suuivants :
    nv_sommet.num = fleche->num;
    nv_sommet.x = fleche->x;
    nv_sommet.y = fleche->y;
    nv_sommet.PCC = fleche->PCC;
    nv_sommet.passage = fleche->passage;
    nv_sommet.pere = fleche->pere;
    nv_sommet.voisins = fleche->voisins;
    strcpy(nv_sommet.nom, fleche->nom);
    circuit = ajout_tete_chemin(circuit, nv_sommet);                            //On ajoute ce nouveau sommet au circuit, pour construire le chemin réponse
    fleche = fleche->pere;                                                      //On pointe sur le sommet-étape du chemin suivant
  }
  return circuit;                                                               //On renvoie le chemin calculé, dans le bon sens (départ -> arrivée)
}


void visualiser_chemin(SOMMET* chemin, int dist) {                              //Fonction d'affichage du chemin, sur le même modèle que l'affichage du graphe
  SOMMET* fleche = chemin;                                                      //Pointeur de navigation
  printf("Chemin le plus court trouvé d'un poids de %d\n", dist);
  while (fleche != NULL) {                                                      //Tant qu'il reste de sommets dans le chemin
    printf("%d (%lf, %lf) %s \n", fleche->num, fleche->x, fleche->y, fleche->nom);    //On affiche les paramètres utiles du sommet
    fleche = fleche->pere;                                                      //On pointe sur le sommet suivant
  }
  printf ("\n \n");                                                             //On saute deux lignes pour plus de clarté
}
