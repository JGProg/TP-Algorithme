#include <stdio.h>
#include "file.h"

int main(void) 
{
	File f ;
	init(&f);
	int i=0;
    
    //Emfile une fois de trop
    printf("Enfile les données (MAX+1) il doit y avoir une erreur\n");
	for(i=0;i<8;i++)
	{
		enfiler(&f, i);
	}
    
    printf("\nPremier affichage après enfilation + 1\n");
    afficher(&f);
    
    //Test dans le cas on dépile plus qu'il y a d'élément
    printf("\nDéfile les données (MAX+1) il doit y avoir une erreur\n");
    for(i=0;i<8;i++)
    {
        defiler(&f);
    }
    printf("\nDeuxième affichage après défilation de tous les éléments (Vide normalement)\n");
	afficher(&f);
    
    //Enfile un seul chiffre
    enfiler(&f, 42);
    
    printf("\nTroisième affichage après enfilation de la valeur 42\n");
	afficher(&f);
	return 0;
    
}
