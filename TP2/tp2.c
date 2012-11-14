#include "Arbre.h"
#include "stdio.h"

int main(void) 
{
Arbre * arbre;
arbre= creer(500);
inserer(arbre, 1000);

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
printf("cherche: %d\n",chercher(arbre, 1));
printf("cherche: %d\n",chercher2(arbre, 0));
printf("Minimun: %d\n",minimum(arbre)->valeur);
printf("Maximum: %d\n",maximum(arbre)->valeur);
printf("Supprimer: %d\n",supprimer(arbre,49));
    afficher2(arbre);
    printf("\n");
detruire(arbre);
printf("fin\n\n\n\n");
	return 0;
}
