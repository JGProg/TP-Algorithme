#include <stdio.h>
#include "liste.h"

int main(void) 
{

    Liste* list = Nouvelle_Liste();
    
    //Ajouter des élements
    int i;
    for (i=1; i<7; i++) {
        AjouterElement(list, i);
    }
    AfficherListe(list);
    
    //Insertion en fin de liste chainée
    InsertionTrie(list, 37);
    AfficherListe(list);
    
    //Insertion dans la liste chainée
    InsertionTrie(list, 3);
    AfficherListe(list);
    
    //Insertion premier élément
    InsertionTrie(list, 0);
    AfficherListe(list);
    
    //Recherche des valeurs
    printf("Recherche de la valeur 42 %s\n",(char*)RechercheElement(list, 42));
    printf("Recherche de la valeur 3 : %d\n",(int)RechercheElement(list, 3));
    
    //Suppresion d'une seule valeur
    SuppressionElement(list, 37);
    AfficherListe(list);
    
    //supprimer toutes les occurrences de l'entier 3 dans la liste list
    SuppressionOccurenceElement(list, 3);
    AfficherListe(list);
	return 0;
}
