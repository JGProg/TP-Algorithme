/*===============================================================*
 * Grenoble INP - ESISAR                                         *
 * TP 3 - CS316                                                  *
 * Enseignant: Bassem DEBBABI (dbassem@gmail.com)                *
 * Source: http://debbabi.net/teaching/cs316                     *
 *===============================================================*/

#ifndef GRAPHE_H
#define GRAPHE_H

#include <stdlib.h>
#include <stdio.h>


typedef struct _Adjacent {
    int sommet;
    struct _Adjacent* suivant;
    struct _Adjacent* precedent;
} Adjacent;

typedef struct _Sommet {
    int id;
    struct _Adjacent *list_adjacents;
    struct _Sommet *suivant;
    struct _Sommet *precedent;
    int distance;
    int couleur;
    struct _Sommet parent;
} Sommet;

typedef Sommet Graphe;

/* @Exercice 1
 * Charger un graphe depuis un fichier
 * chaque ligne correspond à un arc. Un ligne commence par le numero
 * du sommet origine, suivi par le sommet but.
 * Un exemple de fichier :
 
 1 2
 1 3
 2 4
 2 2
 
 */
Graphe* charger_graphe(const char *fichier);

/* Ajoute un arc
 * G : le Graphe
 * s : sommet origine
 * b : sommet but
 */
Graphe* ajouter(Graphe* G,int o, int b);

/* @ Exercice 1
 * Afficher le graphe.
 * Un exemple d'affichage:
 
 Le graphe a 2 sommets :
 1 -- 2
 1 -- 3
 2 -- 4
 2 -- 2
 Le graphe a 3 arcs.
 */
void afficher(Graphe* G);

/* @ Exercice 1
 * Detruire un Graphe.
 * Liberer l'espace mémoire occupé par le graphe.
 */
void detruire(Graphe* G);

/* @Exercice 2
 * Parcours en largeur du graphe
 * G : Graphe
 * s : sommet du graphe
 */
void parcours_largeur(Graphe* G, int s);

/* @ Exercice 3
 * G : Graphe
 * s : sommet du graphe
 * v : destination
 */
void imprimer_chemin(Graphe* G, int s, int v);

#endif
