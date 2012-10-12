#include "pile.h"

void init( Pile *p ) {
	p->taille = -1;
}

int est_vide( Pile *p ) {
	if (p->taille == -1)
		return 1;
	else
		return 0;
}

int est_pleine( Pile *p ) {
	if (p->taille == 99) /* notre pile contient au max 100 elements */
		return 1;
	else
		return 0;
}

void empiler( Pile *p, int v ) {
	if (est_pleine(p)) {
		printf("erreur: empiler: la pile est pleine\n");
		return; /* ne fait rien */
	}
	p->taille = p->taille + 1;
	p->valeurs[ p->taille ] = v;
}

int depiler( Pile *p ) {
	float resultat;
	if (est_vide(p)) {
		printf("erreur: depiler: la pile est vide\n");
		return 0; /* ? renvoie 0 */
		/* note: on pourrait appeler exit(1); pour terminer
         le programme */
	}
	resultat = p->valeurs[ p->taille ];
	p->taille = p->taille-1;
	return resultat;
}

/* Affiche l'etat de la pile,
 pratique pour les tests
 */
void  afficher( Pile *p ) {
	int i;
	printf("etat de la pile:\n");
    
	/* on utilise la pile comme un tableau */
	for (i=0; i <= p->taille; i++)
		printf("\t[ %d ]\n", p->valeurs[i]);
}



int recherche(Pile * p, int valeurRecherchee)
{
	int ret = 0;
	int i =0;
	while((i < (p->taille)) && ((p->valeurs[i]) != valeurRecherchee))
	{
		i++;
	}	 
	if(p->valeurs[i] == valeurRecherchee)
	{
		ret = p->taille +1 - i;
	}
	return ret;
}

void RetireOccurence(Pile *p,int valeur)
{
	Pile p2 ;
	init(&p2);
	int i =0,j=0;
	j=recherche(p,valeur);
	printf("On enleve le %d en dépilant %d fois\n",valeur,j);
    if(j != 0)
    {
        for(i=1;i<j;i++)
        {
            empiler(&p2, depiler(p));
        }
        depiler(p);
        i=0;
        while(i<=p2.taille)
        {
            empiler(p,p2.valeurs[p2.taille -i]);
            i++;
        }
    }

}

