#include <stdio.h>
#include <stdlib.h>
#include "Arbre.h"
unsigned int max(int a,int b);

//OK
Arbre* creer(int valeur)
{
	Arbre * racine;
	racine= (Arbre*)malloc(sizeof(Arbre));
	racine->gauche=(NULL);
	racine->droit=(NULL);
	racine->valeur=valeur;	
	//printf("%d inséré dans l'arbre.\n",valeur);
	return racine;
}

//OK
void detruire(Arbre* racine)
{

	if(racine->gauche!=NULL)
		detruire(racine->gauche);
	if(racine->droit!=NULL)
		detruire(racine->droit);
	
		
	//printf("noeud %d  à détruire\n",racine->valeur);
	free(racine);
	
}

//OK
struct Noeud* inserer(Arbre* noeud, int valeur)
{
        if (noeud == NULL) {
            return(creer(valeur));
        }
        else {
            if (valeur < noeud->valeur)
                noeud->gauche = inserer(noeud->gauche, valeur);
            else
                noeud->droit = inserer(noeud->droit, valeur);
            
            return(noeud);
        } 
}

//OK
void afficher(Arbre* racine)
{
    if(racine!=NULL)
    {
        afficher(racine->gauche);
	
        printf("%d;",racine->valeur);
	
        afficher(racine->droit);
    }
}

//OK
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

//OK
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

//OK
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

// OK
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

//OK
unsigned int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

//OK
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

//OK
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

//OK
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

//OK
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

//OK
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

//OK
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

//OK
struct Noeud* successeur(Arbre* racine, int valeur)
{
    if(chercher(racine,valeur) == NULL || maximum(racine)->valeur == valeur)
    {
        return NULL;
    }
    struct Noeud* temp = NULL;
    while(racine != NULL && valeur != racine->valeur)
	{
		if(valeur < racine->valeur)
		{
            temp = racine;
			racine = racine->gauche;
		}
		else
		{
            temp = racine;
			racine = racine->droit;
		}
	}
    if (racine == NULL)
    {
        return NULL;
    }
    else
    {
        return temp;
    }

}


//NOK
struct Noeud* predecesseur(Arbre* racine, int valeur)
{
    if(chercher(racine,valeur) == NULL || minimum(racine)->valeur == valeur)
    {
        return NULL;
    }
    struct Noeud* temp = NULL;
    while(racine != NULL && valeur != racine->valeur)
	{
		if(valeur < racine->valeur)
		{
            temp = racine;
			racine = racine->gauche;
		}
		else
		{
            temp = racine;
			racine = racine->droit;
		}
	}
    if (racine == NULL)
    {
        return NULL;
    }
    else
    {
        return temp;
    }
}



//OK
Arbre* fusion(Arbre* arbre1, Arbre* arbre2)
{
   
    if(arbre2 != NULL && arbre1 != NULL)
    {
        // On recherche pour voir si la valeur arbre 1 est dans l'arbre 2
        if (chercher(arbre2,arbre1->valeur) == NULL)
        {
            // Dans le cas non on l'insère
            inserer(arbre2, arbre1->valeur);
        }

        // On fait de même pour l'arbre gauche et droite
        arbre2 = fusion(arbre1->gauche, arbre2);
        
        arbre2 = fusion(arbre1->droit, arbre2);
        return arbre2;
	}
    if (arbre2 == NULL )
    {
		return arbre1;
    }
    else if (arbre1 == NULL)
    {
		return arbre2;
    }
}


//OK
int equivalents(Arbre* arbre1, Arbre* arbre2)
{
    if (arbre1==NULL && arbre2==NULL) return 1;
    else if (arbre1!=NULL && arbre2!=NULL)
    {
        return(
               arbre1->valeur == arbre2->valeur &&
               equivalents(arbre1->gauche, arbre2->gauche) &&
               equivalents(arbre1->droit, arbre2->droit)
               );
    }
    else return 0 ;
} 
