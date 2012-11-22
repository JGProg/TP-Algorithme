#include "Graphe.h"

int main(void) 
{

  	/* des tests ici ... */
	Graphe* G = charger_graphe("graphe1.txt");
    printf("%d\n",G->id);
		

	return 0;
}
