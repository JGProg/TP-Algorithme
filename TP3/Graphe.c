#include "Graphe.h"


Graphe* charger_graphe(const char *fichier) {
 FILE *flot;
 Graphe* G = (Sommet*)malloc(sizeof(Sommet));
 int o,b ;
 if ((flot = fopen(fichier, "r")) == NULL) {
  fprintf(stderr,"\nErreur: impossible d'ouvrir le fichier %s\n", fichier);
  return(NULL);
 } 
 while (fscanf(flot, "%i %i ", &o, &b) == 2) {
  if (o>=0 && b>=0) ajouter(G,o,b);
 }
 return(G) ;
}


Graphe* rechercher(Graphe* Sommet,int G);

//Initailise les adjacents
Adjacent* creer_Adjacent(int val)
{
    Adjacent* NewAdj =(Adjacent*)malloc(sizeof(Adjacent));
    NewAdj->sommet = val;
    NewAdj->suivant = NULL;
    NewAdj->precedent = NULL;
    return NewAdj;
}

//Initialise le Sommet
Sommet* creer_Sommet(int val)
{
    Sommet* NewSommet =(Sommet*)malloc(sizeof(Sommet));
    NewSommet->id = val;
    NewSommet->list_adjacents = NULL;
    NewSommet->suivant = NULL;
    NewSommet->precedent = NULL;
    return NewSommet;
}

//On insère le sommet
void inserer_Sommet(Graphe * G,Sommet * Som)
{
    if(G == NULL)
    {
        G = Som;
    }
    else
    {
        Som->suivant = G;
        G->precedent = Som;
        G=Som;
    }
}

void inserer_adjacent(Sommet * Som, Adjacent * a1)
{
    if(Som->list_adjacents == NULL)
    {
        Som->list_adjacents = a1;
    }
    else
    {
        a1->suivant = Som->list_adjacents;
        Som->list_adjacents->precedent = a1;
        Som->list_adjacents = a1;
    }
}

void ajouter(Graphe* G,int o, int b) {
    Sommet* Newsom = rechercher(G,b);
    Sommet* Newsom2 = rechercher(G,b);
    
    if(Newsom == NULL)
    {
        Newsom = creer_Sommet(o);
        printf("Sommet inserer %d\n",Newsom->id);
        inserer_Sommet(G,Newsom);
    }
    if(Newsom2 == NULL)
    {
        Newsom2 = creer_Sommet(o);
        printf("Sommet inserer %d\n",Newsom2->id);
        inserer_Sommet(G,Newsom2);
    }

    //Adjacent* a1 = creer_Adjacent(b);
    //inserer_adjacent(Newsom,a1);
    
    //Adjacent* a2 = creer_Adjacent(o);
    //inserer_adjacent(Newsom2,a2);

}



//Trouver -> 1
Sommet* rechercher(Graphe* Sommet,int G)
{
    if (Sommet == NULL)
    {
     return NULL;
    }
    if (Sommet->id==G)
    {
        return Sommet;
    }
    return rechercher(Sommet->suivant,G);
}


void afficher(Graphe* G) {
<<<<<<< HEAD
	
=======
    
>>>>>>> Correct problem to initialization of Graphe.
	Adjacent* temp = G->list_adjacents;
	while(temp != NULL )
	{
		printf("pere : %d ,",G->id);
		printf("frere : %d \n",temp->sommet);
		temp=temp->suivant;
<<<<<<< HEAD
		
	}
	
	if( G-> suivant != NULL )
			afficher(G->suivant);
		else 
			printf("suivant vide\n");
=======
        
	}
    
	if( G-> suivant != NULL )
        afficher(G->suivant);
    else
        printf("suivant vide\n");
>>>>>>> Correct problem to initialization of Graphe.
}

void detruire(Graphe* G) {
	if( G-> suivant != NULL )
		detruire(G->suivant);
	free(G);
		
}
void parcours_largeur(Graphe* G, int s) {
	// à implementer..
}

void imprimer_chemin(Graphe* G, int s, int v) {
	// à implementer..
}

