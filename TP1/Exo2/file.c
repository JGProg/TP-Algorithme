#include "file.h"



//precondition  non
//post condition la tete de la pile est iniatilisée à 0
void init(File *f)
{
	f->tete=0;
	f->queue=0;
	f->nbDonne = 0;
}

int taille(File *f)
{
	return f->nbDonne;
}

//pre 'd' doit être un entier positif ou nul
//post l'entier 'd' est empiler sinon un message d'erreur est afficher
void enfiler(File *f, int d)
{
	if(f->nbDonne < MAX)
	{
		f->valeurs[f->queue]=d;
		f->nbDonne++;
		if(f->queue  == MAX -1)
		{
			f->queue = 0;
		}
		else
		{
			f->queue++;
		}
		
	}
	else
	{
		printf("Erreur : Il n'est pas possible d'enfiler la valeur %d. La file est pleine \n",d);
	}
}

//pre non
//post Retourne la valeur dépiler sinon -1 dans le cas de la file vide
int defiler(File *f)
{
	int ret = -1;
	if(f->nbDonne != 0)
	{
		ret = f->valeurs[f->tete];
		f->nbDonne--;
		if(f->tete == MAX -1)
		{
			f->tete = 0;
		}
		else
		{
			f->tete++;
		}
		
	}
	else
	{
		printf("Erreur : La file est vide \n");
	}
	return ret;
}

//pre non
//post retourne TRUE si la file est vide sinon non
int est_vide(File *f)
{
    int ret = FALSE;
	if(f->nbDonne == 0)
    {
        ret = TRUE;
    }
    return ret;
}

//pre non
//post retourne TRUE si la file est pleine sinon non
int  est_pleine(File *f)
{
	int ret = FALSE;
	if(f->nbDonne == MAX)
	{
		ret = TRUE;
	}
    return ret;
}

//pre non
//post affiche les valeurs présentent dans la file sinon message d'erreur
void afficher(File *f)
{
	int i=0;
	if(est_vide(f) == FALSE)
	{
		i = f->tete;
        do {
			printf("\t[ %d ] (de la tete à la queue) l'indice de la file est : %d\n", f->valeurs[i],i);
			if(i == MAX -1)
			{
				i = 0;
			}
			else
			{
				i++;
			}
        } while (i != f->queue);

	}
	else
	{
		printf("[Affichage] La file est vide ! \n");
	}
}

