#ifndef PILE_H
#define PILE_H

#include <stdio.h>

#define MAX 7
#define TRUE 1
#define FALSE 0

struct Pile {
	int valeurs[MAX]; /* les donnees stockees dans la pile */
	int taille;       /* la taille courante de la pile */
};


typedef struct Pile Pile;

/* Initialiser la Pile */
void init(Pile *p);

/* Inserer une valeur dans la pile */
void empiler(Pile *p, int d);

/* Supprimer une valeur de la pile */
int depiler(Pile *p);

/* Retourner 1 si la pile est vide, 0 sinon */
int  est_vide(Pile *p);

/* Retourner 1 si la pile est pleine, 0 sinon */
int  est_pleine(Pile *p);

/* Retourner la valeur en sommet de la pile */
int  sommet(Pile *p);

/* Afficher le contenu de la pile */
void afficher(Pile *p);


int recherche(Pile * p, int valeurRecherchee);

void RetireOccurence(Pile *p,int valeur);
#endif
