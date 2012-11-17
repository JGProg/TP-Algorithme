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

        if (noeud == NULL) {
            return(creer(valeur));
        }
        else {
            if (valeur <= noeud->valeur)
                noeud->gauche = inserer(noeud->gauche, valeur);
            else
                noeud->droit = inserer(noeud->droit, valeur);
            
            return(noeud);
        } 
    
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
    if (racine==NULL) return 1;

    if (racine->gauche!=NULL && maximum(racine->gauche)->valeur > racine->valeur)
        return 0;
    
    if (racine->droit!=NULL && minimum(racine->droit)->valeur <= racine->valeur)
        return 0;
    
    if (!verifie(racine->gauche) || !verifie(racine->droit))
        return 0 ;
    
    return 1;
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
        if(racine == NULL)
        {
            racine = NULL;
        }
        else
        {
            racine = racine;
        }
	}
    else
    {
        if(valeur < racine->valeur)
        {
            racine = chercher(racine->gauche,valeur);
        }
        else
        {
            racine = chercher(racine->droit,valeur);
        }

    }
    return racine;
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
    if (racine == NULL)
    {
        return NULL;
    }
    else
    {
        return racine;
    }
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

struct Noeud* successeur(Arbre* racine, int valeur)
{
	struct Noeud* a = NULL;
	struct Noeud* sucess = NULL;
	a = chercher(racine,valeur);    
    
	if(a == maximum(racine))
	{
		return a;
	}
	
	if(a->droit != NULL)
    {
		sucess = minimum(a->droit);
	}
    else
	{
		do
		{
			if(chercher(racine->droit,valeur))
			{
				racine = racine->droit;
			}
			else if(chercher(racine->gauche,valeur))
			{
				if((racine->valeur > valeur && racine->gauche->valeur < valeur) || (racine->valeur < valeur && racine->gauche->valeur > valeur))
				{
					if(racine->valeur > racine->gauche->valeur)
					{
						sucess = racine->droit;
						return sucess;
					}
					else
					{
						sucess = racine->gauche;
						return sucess;
					}
				}
				else
					racine = racine->gauche;
			}
			else
				sucess = racine;
		}while(sucess == NULL);
	}
	return sucess;
}


struct Noeud* predecesseur(Arbre* racine, int valeur)
{
    struct Noeud* a = NULL;
	struct Noeud* sucess = NULL;
	a = chercher(racine,valeur);
    
	if(a == minimum(racine))
	{
		return a;
	}
	
	if(a->gauche != NULL)
    {
		sucess = maximum(a->droit);
	}
    else
	{
		do
		{
			if(chercher(racine->droit,valeur))
			{
				racine = racine->droit;
			}
			else if(chercher(racine->gauche,valeur))
			{
				if((racine->valeur < valeur && racine->gauche->valeur > valeur) || (racine->valeur > valeur && racine->gauche->valeur < valeur))
				{
					if(racine->valeur > racine->gauche->valeur)
					{
                        printf("djhdsfhjk\n");
						sucess = racine->droit;
						return sucess;
					}
					else
					{
                         printf("l'autr if \n");
						sucess = racine->gauche;
						return sucess;
					}
				}
				else
                {
                    printf("hello \n");
					racine = racine->gauche;
                }
			}
			else
            {
				sucess = racine;
            }
		
            }while(sucess == NULL);
	}
    
	return sucess;
}



//A revoir '%' à la fin
Arbre* fusion(Arbre* arbre1, Arbre* arbre2)
{
	
    if(arbre2 != NULL && arbre1 != NULL)
    {
        if (chercher(arbre2,arbre1->valeur) == NULL)
        {
            inserer(arbre2, arbre1->valeur);
        }
        arbre2->gauche = fusion(arbre1->gauche, arbre2->gauche);
        arbre2->droit = fusion(arbre1->droit, arbre2->droit);
        return arbre2;
	}
    else if (arbre2 == NULL)
    {
		return arbre1;
    }
	else if (arbre1 == NULL)
    {
		return arbre2;
    }
}


//End
int equivalents(Arbre* arbre1, Arbre* arbre2)
{
    if (arbre1==NULL && arbre2==NULL) return 1;
    else if (arbre1!=NULL && arbre2!=NULL) {
        return(
               arbre1->valeur == arbre2->valeur &&
               equivalents(arbre1->gauche, arbre2->gauche) &&
               equivalents(arbre1->droit, arbre2->droit)
               );
    }
    else return 0 ;
} 
