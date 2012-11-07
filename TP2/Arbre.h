#ifndef ARBRE_H
#define ARBRE_H


typedef struct Noeud 
{
	int valeur;
	struct Noeud* gauche;
	struct Noeud* droit;		
} Arbre;


Arbre* creer(int valeur);

struct Noeud* inserer(Arbre* racine, int valeur);

void detruire(Arbre* racine);

void afficher(Arbre* racine);
void afficher2(Arbre* racine);
void afficher3(Arbre* racine);

int verifie(Arbre* racine);
int taille(Arbre* racine);
int hauteur(Arbre* racine);
int somme(Arbre* racine);
int moyenne(Arbre* racine);

struct Noeud* chercher(Arbre* racine, int valeur);
struct Noeud* chercher2(Arbre* racine, int valeur);
struct Noeud* minimum(Arbre* racine);
struct Noeud* maximum(Arbre* racine);

struct Noeud* supprimer(Arbre* racine, int valeur);

Arbre* fusion(Arbre* arbre1, Arbre* arbre2);
int equivalents(Arbre* arbre1, Arbre* arbre2);


#endif
