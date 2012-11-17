#include "Arbre.h"
#include "stdio.h"

int main(void) 
{
Arbre * arbre;
arbre= creer(3);
inserer(arbre, 54);
inserer(arbre, 1);
inserer(arbre, 0);
inserer(arbre, 49);
inserer(arbre, 50);
inserer(arbre, 51);
inserer(arbre, 52);

afficher(arbre);

printf("\n");
afficher2(arbre);
printf("\n");
printf("taille: %d\n",taille(arbre));
printf("somme: %d\n",somme(arbre));
printf("moyenne: %d\n",moyenne(arbre));
printf("hauteur: %d\n",hauteur(arbre));
printf("cherche: %d\n",chercher(arbre, 50));
printf("cherche: %d\n",chercher2(arbre, 1));
printf("Successeur: %d\n",successeur(arbre,0)->valeur);
printf("Predecesseur: %d\n",predecesseur(arbre,3)->valeur);
    printf("Verifie: %d\n",verifie(arbre));
    

printf("Minimun: %d\n",minimum(arbre)->valeur);
printf("Maximum: %d\n",maximum(arbre)->valeur);

printf("Supprimer: %d\n",supprimer(arbre,49));
afficher2(arbre);
printf("\n");

detruire(arbre);
  
    
    
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
printf("Equivalent: %d\n",equivalents(arbre1,arbre2));
detruire(arbre1);
detruire(arbre2);
    
    
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
    

    afficher2(fusion(arbre1,arbre2));




return 0;
}
