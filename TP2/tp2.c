#include "Arbre.h"
#include "stdio.h"

int main(void)
{
    //Initialisation des valeurs pour tester les fonnctions.
    int ValCherche1 = 50;
    int Valchercher2 = 50;
    int Valsupprimer = 1;
    int suc = 3;
    int pre = 54;
    int Nopre = 0;
    int nosuc = 54;
    //Création des variables
    Arbre * arbre;
    Arbre* temp;
    int boolean;
    
    //Creation de l'arbre
    arbre= creer(3);
    inserer(arbre, 54);
    inserer(arbre, 1);
    inserer(arbre, 0);
    inserer(arbre, 49);
    inserer(arbre, 50);
    inserer(arbre, 51);
    inserer(arbre, 52);
    
    //Affichage de l'arbre
    printf("\n--------Affichage simple -------------\n");
    afficher(arbre); printf("\n");
    
    //Affichage complexe
    printf("\n--------Affichage complexe-------------\n");
    afficher2(arbre); printf("\n");
    
    printf("\n--------Taille-------------\n");
    printf("taille: %d\n",taille(arbre));
    
    printf("\n--------Somme-------------\n");
    printf("somme: %d\n",somme(arbre));
    
    printf("\n--------Moyenne-------------\n");
    printf("moyenne: %d\n",moyenne(arbre));
    
    printf("\n--------Hauteur-------------\n");
    printf("hauteur: %d\n",hauteur(arbre));

    
    //Cherche
    printf("\n--------Chercher 1-------------\n");
    temp = chercher(arbre, ValCherche1);
    if(temp !=NULL)
        printf("cherche: %d\n",temp->valeur);
    else
        printf("Non trouvé\n");
    
    //Chercher 2
    printf("\n--------Chercher 2-------------\n");
    temp = chercher2(arbre,Valchercher2);
    if(temp !=NULL)
        printf("cherche: %d\n",temp->valeur);
    else
        printf("Non trouvé\n");
    
    
    
    //Fonction vérifie
    printf("\n--------Verifie-------------\n");
    boolean = verifie(arbre);
    if(boolean == 1)
        printf("Arbre verifie\n");
    else
         printf("Arbre ne verifie pas\n");
    
    
    //Minimum
    printf("\n--------Minimum-------------\n");
    temp =minimum(arbre);
    if(temp !=NULL)
        printf("Minimum: %d\n",temp->valeur);
    else
        printf("Minimum: Il n'en a pas\n");
    
    //Maximum
    printf("\n--------maximum-------------\n");
    temp = maximum(arbre);
    if(temp !=NULL)
        printf("Maximum: %d\n",temp->valeur);
    else
        printf("Maximum: Il n'en a pas\n");
    
    //Supprimer Valeur
    printf("\n--------Supprimer valeur %d-------------\n",Valsupprimer);
    temp = supprimer(arbre,Valsupprimer);
    if(temp !=NULL)
        printf("Supprimer: %d\n",Valsupprimer);
    else
        printf("Valeur non trouvé\n");
    
    afficher2(arbre);printf("\n");
    
    //Succ
    printf("\n--------Successeur de %d-------------\n",suc);
    temp = successeur(arbre,suc);
    if(temp != NULL)
        printf("Successeur: %d\n",temp->valeur);
    else
        printf("Successeur : Il n'y en a pas\n");
    
    printf("\n--------Successeur de %d-------------\n",nosuc);
    temp = successeur(arbre,nosuc);
    if(temp != NULL)
        printf("Successeur: %d\n",temp->valeur);
    else
        printf("Successeur : Il n'y en a pas\n");

    
      
    //Predecesseur
    printf("\n--------Predecesseur de %d-------------\n",pre);
    temp = predecesseur(arbre,pre);
    if(temp !=NULL)
        printf("Predecesseur: %d\n",temp->valeur);
    else
        printf("Predecesseur: Il n'y en a pas\n");
    
    //Predecesseur
    printf("\n--------Predecesseur de  %d-------------\n",Nopre);
    temp = predecesseur(arbre,Nopre);
    if(temp !=NULL)
        printf("Predecesseur: %d\n",temp->valeur);
    else
        printf("Predecesseur: Il n'y en a pas\n");

    
    //Destruction
    printf("\n--------Destruction-------------\n");
    detruire(arbre);
    
    
    printf("\n--------Equivalent-------------\n");
    Arbre * arbre1;
    arbre1= creer(3);
    inserer(arbre1, 54);
    inserer(arbre1, 1);
    inserer(arbre1, 0);
    inserer(arbre1, 49);
    inserer(arbre1, 50);
    inserer(arbre1, 51);
    inserer(arbre1, 52);
    
    Arbre * arbre2;
    arbre2= creer(3);
    inserer(arbre2, 54);
    inserer(arbre2, 1);
    inserer(arbre2, 0);
    inserer(arbre2, 49);
    inserer(arbre2, 50);
    inserer(arbre2, 51);
    inserer(arbre2, 52);
    printf("Arbre 1 : ");afficher(arbre1);printf("\n");
    printf("Arbre 2 : ");afficher(arbre2);printf("\n");
    boolean = equivalents(arbre1,arbre2);
    if(boolean == 1)
        printf("Equivalent: Oui\n");
    else
        printf("Equivalent: Non\n");
    supprimer(arbre2,52);
    
    printf("\n--------Equivalent-------------\n");
    printf("Arbre 1 : ");afficher(arbre1);printf("\n");
    printf("Arbre 2 : ");afficher(arbre2);printf("\n");
    boolean = equivalents(arbre1,arbre2);
    if(boolean == 1)
        printf("Equivalent: Oui\n");
    else
        printf("Equivalent: Non\n");
    detruire(arbre1);
    detruire(arbre2);
    
    
    printf("\n--------Fusion-------------\n");
    arbre1= creer(3);
    inserer(arbre1, 54);
    inserer(arbre1, 1);
    inserer(arbre1, 0);
    inserer(arbre1, 49);
    inserer(arbre1, 50);
    inserer(arbre1, 51);
    inserer(arbre1, 52);
    arbre2= creer(5);
    inserer(arbre2, 10);
    inserer(arbre2, 4);
    
    afficher2(arbre1);printf("\n");
    afficher2(arbre2);printf("\n");
    
    afficher(fusion(arbre1,arbre2));
    
    return 0;
}
