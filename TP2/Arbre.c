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

//TODO
int verifie(Arbre* racine)
{
    return 0;
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
	if(racine==NULL)
	{
		return 0;
	}
    int nbNoeudGauche = hauteur(racine->gauche);
    int nbNoeudDroit = hauteur(racine->droit);
    return max(nbNoeudDroit,nbNoeudGauche)+1;
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
	struct Noeud* min = racine;
    if (racine->gauche)
    {
        struct Noeud* MiniGauche = minimum(racine->gauche);
        min = (min->valeur < MiniGauche->valeur ) ? min : MiniGauche;
    }
    if (racine->droit)
    {
        struct Noeud* MiniDroite = minimum(racine->droit);
        min = (min->valeur < MiniDroite->valeur ) ? min : MiniDroite;
    }
    return min;
}

struct Noeud* maximum(Arbre* racine)
{
	struct Noeud* max = racine;
    if (racine->gauche)
    {
        struct Noeud* MaxiGauche = maximum(racine->gauche);
        max = (max->valeur > MaxiGauche->valeur ) ? max : MaxiGauche;
    }
    if (racine->droit)
    {
        struct Noeud* MaxiDroite = maximum (racine->droit);
        max = (max->valeur > MaxiDroite->valeur ) ? max : MaxiDroite;
    }
    return max;
}

struct Noeud* supprimer(Arbre * Racine, int valeur)
{
	struct Noeud* NoeudASupprimer;
	if (Racine->valeur==valeur) // on a trouvé l'élément à supprimer
	{
		NoeudASupprimer=Racine;
		if (NoeudASupprimer->gauche==NULL) //si ya pa de gauche, on retourne droit
			return NoeudASupprimer->droit;
		else
		{
			Racine=NoeudASupprimer->gauche; //sinon on recherche dans gauche l'endroit pour insérer le droit
            while (Racine->droit!=NULL)
            {
                Racine=Racine->droit;
            }
            Racine->droit=NoeudASupprimer->droit;
			return NoeudASupprimer->gauche;
		}
		free(NoeudASupprimer);
	}
	else
	{
		if (Racine->valeur>valeur)
		{
			Racine->gauche=supprimer(Racine->gauche,valeur);
		}
		else
		{
			Racine->droit=supprimer(Racine->droit,valeur);
		}
	}
	return Racine;
}
