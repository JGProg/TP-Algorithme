#include "Graphe.h"


Graphe* charger_graphe(const char *fichier) {
 FILE *flot;
 Graphe* G = NULL;
 int o,b ;
 if ((flot = fopen(fichier, "r")) == NULL) {
  fprintf(stderr,"\nErreur: impossible d'ouvrir le fichier %s\n", fichier);
  return(NULL);
 } 
 while (fscanf(flot, "%i %i ", &o, &b) == 2) {
  if (o>=0 && b>=0) ajouter(G,o,b) ;
 }
 return(G) ;
}



void ajouter(Graphe* G,int o, int b) {
    if(G != NULL)
    {
        struct Sommet Som;
        Som->id = o;
        if(rechercher(b,o) == 1)
        {
            NewSommet=(struct Sommet*)malloc(sizeof (Sommet));
            NewSommet->id=a;
            NewSommet->suivant=e;
        }
    }
    else
    {
        if(rechercher(b,o) == 1)
        {
            
        }
    }
    return m;

}

//Trouver -> 1
struct _Sommet rechercher(Graphe* Sommet,int G)
{
    if (Sommet==NULL)
    {
     return NULL;
    }
    if (Sommet->id==G)
    {
        return Sommet;
    }
    return rechercher(G,Sommet->suivant);
}


void afficher(Graphe* G) {
	// à implementer..
}

void detruire(Graphe* G) {
	// à implementer..
}

void parcours_largeur(Graphe* G, int s) {
	// à implementer..
}

void imprimer_chemin(Graphe* G, int s, int v) {
	// à implementer..
}

