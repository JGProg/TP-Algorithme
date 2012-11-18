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
    
    //On supprime tous les souss arbres gauche
	if(racine->gauche!=NULL)
		detruire(racine->gauche);
    //On supprime tous les sous arbres droit
	if(racine->droit!=NULL)
		detruire(racine->droit);
	//printf("noeud %d  à détruire\n",racine->valeur);
	free(racine);
	
}

//OK
struct Noeud* inserer(Arbre* noeud, int valeur)
{
    
    if (noeud == NULL)
    {
        return(creer(valeur));
    }
    else
    {
        // On rajoute la valeur à gauche si la valeur est inférieur
        if (valeur < noeud->valeur)
        {
            noeud->gauche = inserer(noeud->gauche, valeur);
        }
        // On rajoute la valeur à droite si la valeur est supérieur
        else
        {
            noeud->droit = inserer(noeud->droit, valeur);
        }
        return(noeud);
    }
}

//OK
// Affichage en préordre. On affiche le sous arbre gauche puis la racine puis le sous arbre droit
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
// De même que l'affichage.
void afficher2(Arbre* racine)
{
	if(racine!=NULL)
	{
        //On est sur le premier noeud {
		printf("{");
        //On affiche tous les sous arbres gauches
		afficher2(racine->gauche);
        //On affiche la racine
		printf(",%d,",racine->valeur);
        //On affiche tous les sous abres droits
		afficher2(racine->droit);
		//On a finit l'affichage du noeud }
        printf("}");
	}
	else
    {
        //Dans le cas ou nous n'avons pas de sous arbre gauche ou droit on affiche '_'
		printf("_");
    }
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
//Même règle que pour l'affichage. Parcourt sous arbre gauche, on compte, puis sous arbre droit
int taille(Arbre* racine)
{
    //Static permet d'instancier une seule fois la variable 
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
    //Compte le nombre maximum de sous arbre gauche
    int nbNoeudGauche = hauteur(racine->gauche);
    
    //Compte le nombre maximum de sous arbre droit
    int nbNoeudDroit = hauteur(racine->droit);
    
    //Retourne le maximum entre les deux sous arbre
    return max(nbNoeudDroit,nbNoeudGauche)+1;
}

//OK
//Fonction intermédiaire permettant de trouvé le maximum entre deux entiers
unsigned int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

//OK
//Même principe que la hauteur
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
//No comment
int moyenne(Arbre* racine)
{
	return somme(racine)/taille(racine);
}


//Function récursive
struct Noeud* chercher(Arbre* racine, int valeur)
{
    //Dans le cas ou la racine est null ou la valeur est trouvée
	if(racine == NULL || valeur == racine->valeur)
	{
        if(racine == NULL)
        {
            //Retourn null
            racine = NULL;
        }
        else
        {
            //On retourne la racine
            racine = racine;
        }
	}
    //Dans le cas ou nous n'avons pas encore trouvée la valeur on regarde dans les sous arbre
    else
    {
        //On regarde à gauche si valeur inférieur
        if(valeur < racine->valeur)
        {
            racine = chercher(racine->gauche,valeur);
        }
        //On regarde à droite dans le cas contraire
        else
        {
            racine = chercher(racine->droit,valeur);
        }
        
    }
    return racine;
}

//OK
//Fonction itérative
struct Noeud* chercher2(Arbre* racine, int valeur)
{
    //On recherche si on est arriver à NULL ou si on a trouvé la valeur.
    //On regarde d'abord si on est a nil sinon débordement
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
    //Si on n'a pas trouvé
    if (racine == NULL)
    {
        return NULL;
    }
    //SI on a trouvé
    else
    {
        return racine;
    }
}

//OK
struct Noeud* minimum(Arbre* racine)
{
	struct Noeud* min = racine;
    //S'il existe un sous arbre gauche alors on regarde le minimum du sous abre gauche
    if (racine->gauche)
    {
        struct Noeud* MiniGauche = minimum(racine->gauche);
        if(min->valeur >= MiniGauche->valeur )
        {
             min = MiniGauche;
        }
    }
     //S'il existe un sous arbre droit alors on regarde le minimum du sous abre droit
    if (racine->droit)
    {
        struct Noeud* MiniDroite = minimum(racine->droit);
        if(min->valeur >= MiniDroite->valeur)
        {
            min = MiniDroite;
        }
    }
    return min;
}

//OK
//De même que minimum
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
		if (NoeudASupprimer->gauche==NULL) //s'il n'y a pas de sous abre gauche, on retourne sous abre droit
        {
			return NoeudASupprimer->droit;
        }
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
    struct Noeud* temp = racine;
    
    // Dans le cas ou la valeur n'est pas présente
    // OU
    // la valeur est maxmimum alors la valeur ne peut avoir de succeseur
    if(chercher(racine,valeur) == NULL || maximum(racine)->valeur == valeur)
    {
        temp = NULL;
    }
    //Dans le cas ou la valeur est le maximum du sous arbre gauche
    //Alors la maximum est la racine
    else if(valeur == maximum(temp->gauche)->valeur)
    {
        temp =  racine;
    }
    //Dans le cas ou la racine est la valeur
    //Alors on retourne la valeur minimum du sous arbre droit
    else if(racine->valeur == valeur)
    {
        temp = minimum(racine->droit);
    }
    //Dans le cas ou le minimum est la valeur rechercher
    //Alors on retourne la deuxième plus petit valeur
    else if(minimum(racine->gauche)->valeur ==valeur)
    {
        supprimer(temp,valeur);
        temp = minimum(temp);
    }
    //Dans tous les autres cas
    else
    {
        //On regarde si la valeur est dans le sous arbre droit
        temp = chercher(racine->droit,valeur);
        
        //Dans le cas ou il est dans le sous arbre gauche
        if(temp !=NULL)
        {
            //On regarde alors le minimum du sous abre droit
            temp = minimum(temp->droit);
        }
        //On va supprimer tous les minimum jusqu'à arriver sur notre valeur
        else
        {
            temp = racine;
            int mini =minimum(temp->gauche)->valeur;
            while (valeur <= mini)
            {
                supprimer(temp,mini);
                mini =minimum(temp->gauche)->valeur;
            }
            temp = maximum(temp);
        }
    }
    return temp;
    
}


//OK
struct Noeud* predecesseur(Arbre* racine, int valeur)
{
    struct Noeud* temp = racine;
    
    // Dans le cas ou la valeur n'est pas présente
    // OU
    // la valeur est minimum alors la valeur ne peut avoir de succeseur
    if(chercher(racine,valeur) == NULL || minimum(racine)->valeur == valeur)
    {
        temp = NULL;
    }
    //Dans le cas ou la valeur est le maximum du sous arbre gauche
    //Alors la minimum est la racine
    else if(valeur == minimum(temp->droit)->valeur)
    {
        temp = racine;
    }
    //Dans le cas ou la racine est la valeur
    //Alors on retourne la valeur maximum du sous arbre gauhe
    else if(racine->valeur == valeur)
    {
        temp = maximum(racine->gauche);
    }
    //Dans le cas ou le minimum est la valeur rechercher
    //Alors on retourne la deuxième plus grande valeur
    else if(maximum(racine->droit)->valeur ==valeur)
    {
        supprimer(temp,valeur);
        temp = maximum(temp);
    }
    //Dans tous les autres cas
    else
    {
        //On regarde si la valeur est dans le sous arbre gauche
        temp = chercher(racine->gauche,valeur);
        
        //Dans le cas ou il est dans le sous arbre droit
        if(temp !=NULL)
        {
            //On regarde alors le maxi du sous abre gauche
            temp = maximum(temp->gauche);
        }
         //On va supprimer tous les minimum jusqu'à arriver sur notre valeur
        else
        {
            temp = racine;
            
            int maxi =maximum(temp->droit)->valeur;
            while (valeur <= maxi)
            {
                supprimer(temp,maxi);
                maxi =maximum(temp->droit)->valeur;
            }
            temp = maximum(temp);
        }
    }
    return temp;
}



// NOK
// Probleme avec le return temp ajoute un '%' à la fin.
// Ce n'est pas un problème d'affichage.
// Si l'on fait un simple return arbre2 dans la fonction on se retrouve aussi avec ce '%'. Problème non corrigé.
Arbre* fusion(Arbre* arbre1, Arbre* arbre2)
{
    Arbre * temp = arbre2;
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
        temp = arbre2;
	}
    else
    {
        if (arbre2 == NULL )
        {
            temp = arbre1;
        }
        else if (arbre1 == NULL)
        {
            temp = arbre2;
        }
    }
    return temp;
}


//OK
int equivalents(Arbre* arbre1, Arbre* arbre2)
{
    if (arbre1==NULL && arbre2==NULL)
    {
        return 1;
    }
    else if (arbre1!=NULL && arbre2!=NULL)
    {
        //On regarde si tous les sous abres sont égals à 1
        //Dans le cas ou l'un échoue cela retourne 0
        return(
               arbre1->valeur == arbre2->valeur &&
               equivalents(arbre1->gauche, arbre2->gauche) &&
               equivalents(arbre1->droit, arbre2->droit)
               );
    }
    else
    {
        return 0 ;
    }
} 
