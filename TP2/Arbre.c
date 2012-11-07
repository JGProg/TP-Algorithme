#include <stdio.h>
#include <stdlib.h>
#include "Arbre.h"
unsigned int max(int a,int b);

Arbre* creer(int valeur)
{
	Arbre * racine;
	racine= (Arbre*)malloc(sizeof(Arbre));
	racine->gauche=(NULL);
	racine->droit=(NULL);
	racine->valeur=valeur;	
	printf("%d inséré dans l'arbre.\n",valeur);
	return racine;
}

void detruire(Arbre* racine)
{

	if(racine->gauche!=NULL)
		detruire(racine->gauche);
	if(racine->droit!=NULL)
		detruire(racine->droit);
	
		
	printf("noeud %d  à détruire\n",racine->valeur);	
	free(racine);
	
}

struct Noeud* inserer(Arbre* noeud, int valeur)
{
	struct Noeud* sauvnoeud= noeud;
 	
	while(noeud!=NULL)
	{
	sauvnoeud= noeud;
	if( valeur > noeud->valeur)
		{
			noeud=noeud->droit;
		}
		else
		{
			noeud=noeud->gauche;
		}
	}
	noeud = creer(valeur);	
	if(sauvnoeud!=NULL)
	{
		if( valeur < sauvnoeud->valeur)
			sauvnoeud->gauche=noeud;
		else
			sauvnoeud->droit =noeud;
	}	
	return noeud;
}


void afficher(Arbre* racine)
{
if(racine!=NULL)
{
	afficher(racine->gauche);
	
	printf("%d ;",racine->valeur);
	
	afficher(racine->droit);
		
}
}
void afficher2(Arbre* racine)
{
if(racine!=NULL)
{
	printf("{");
	
	afficher2(racine->gauche);
	
	printf(",%d,",racine->valeur);
		
	afficher2(racine->droit);
	printf("}");
}
else 
	printf("_");
}

int verifie(Arbre* racine)
{

}
int taille(Arbre* racine)
{
	static int nbnoeud=0;
	if(racine!=NULL)
	{
		
	taille(racine->gauche);
	nbnoeud++;
	taille(racine->droit);

	}
	return nbnoeud;
}
int hauteur(Arbre* racine)
{
	if(racine!=NULL)
	{
		return 1 + max(hauteur(racine->gauche),hauteur(racine->droit));
	}
	else
	{
		return 0;
	}
}

unsigned int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int somme(Arbre* racine)
{
	static int ressomme=0;
	if(racine!=NULL)
	{
		
	somme(racine->gauche);
	ressomme+=racine->valeur;
	somme(racine->droit);

	}
	return ressomme;
}
int moyenne(Arbre* racine)
{
	return somme(racine)/taille(racine);
}


/* Exo 6 */
struct Noeud* chercher(Arbre* racine, int valeur)
{
	if(racine == NULL || valeur == racine->valeur)
	{
		return racine;
	}
	if(valeur < racine->valeur)
	{
		chercher(racine->gauche,valeur);
	}
	else
	{
		chercher(racine->droit,valeur);
	}
		
}

struct Noeud* chercher2(Arbre* racine, int valeur)
{
	while(racine != NULL && valeur != racine->valeur)
	{
		if(valeur < racine->valeur)
		{
			racine = racine->gauche;
		}
		else
		{
			racine = racine->droit;
		}
	}
	return racine;
		
}

struct Noeud* minimum(Arbre* racine)
{


}

struct Noeud* maximum(Arbre* racine)
{


}
