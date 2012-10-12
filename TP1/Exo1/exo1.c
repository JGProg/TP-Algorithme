
#include "pile.h"

int main(int agrc, char * argv[]) 
{
	// Exo I - a)	
	/*Pile p ;
	init(&p);
	empiler(&p, 42);
	printf("Valeur retourner depile : %d\n", depiler(&p));
	//Test erreur depiler
	depiler(&p);
	afficher(&p);
	int i;
	for(i=0;i<=10;i++)
	{
		printf("%d\n",i);
		empiler(&p, i);
		
	}
	afficher(&p);
	*/
	// EXO I - b)
	
	/*
	Pile p ;
	init(&p);
	empiler(&p, 42);
	empiler(&p, 4962);
	
	empiler(&p, 49645);
	
	printf("Retourne valeur recherchee : %d\n", recherche(&p, 42));
	
	*/
	// EXO I - c)
	
	Pile p ;
	init(&p);
	int i=0;
	for(i=0;i<=6;i++)
	{
		empiler(&p, i);
	}
	afficher(&p);
	RetireOccurence(&p,4);
	afficher(&p);
	return 0;
}
