#ifndef FILE_H
#define FILE_H
#include <stdio.h>

#define MAX 7
#define TRUE 1
#define FALSE 0

struct File 
{
	int valeurs[MAX]; /* les donnees stockees dans la pile */
	int tete;       /* la derniere de la pile */
	int queue;       /* la premiere de la pile */
	int nbDonne;
};
typedef struct File File;

/* Initialiser la file */
void init(File *f);

/* Retourner la taille courante de la file */
int taille(File *f);

/* enfiler un entier */
void enfiler(File *f, int d);

/* Retourner l'element en tete de file */
int defiler(File *f);

/* Retourner 1 si la file est vide, 0 sinon */
int  est_vide(File *f);

/* Retourner 1 si la file est pleine, 0 sinon */
int  est_pleine(File *f);

/* Afficher le contenu de la file */
void afficher(File *f);

#endif
