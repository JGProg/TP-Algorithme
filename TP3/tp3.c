#include "Graphe.h"

int main(void) 
{

  	/* des tests ici ... */
	Graphe* G = charger_graphe("graphe1.txt");
    afficher(G);
    detruire(G);
		

	return 0;
}
