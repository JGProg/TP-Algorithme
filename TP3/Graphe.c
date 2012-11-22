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
        if (o>=0 && b>=0)
            G = ajouter(G,o,b);
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

//On insÃ¨re le sommet
Graphe* inserer_Sommet(Graphe * G,Sommet * Som)
{
    if(G == NULL)
    {
        return Som;
    }
    else
    {
        Som->suivant = G;
        G->precedent = Som;
    }
    return Som;
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

Graphe* ajouter(Graphe* G,int o, int b) {
    Sommet* Newsom = rechercher(G,o);
    Sommet* Newsom2 = rechercher(G,b);
    
    if(Newsom == NULL)
    {
        Newsom = creer_Sommet(o);
        G = inserer_Sommet(G,Newsom);
    }
    if(Newsom2 == NULL)
    {
        Newsom2 = creer_Sommet(b);
        G = inserer_Sommet(G,Newsom2);
    }
    
    Adjacent* a1 = creer_Adjacent(b);
    inserer_adjacent(Newsom,a1);
    
    Adjacent* a2 = creer_Adjacent(o);
    inserer_adjacent(Newsom2,a2);
    
    return G;
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


void afficher(Graphe* G)
{
    Adjacent* temp = G->list_adjacents;
    printf("%d ",G->id);
    while(temp != NULL )
    {
        printf(" - %d ",temp->sommet);
        temp=temp->suivant;
    }
    printf("\n");
    if( G-> suivant != NULL )
        afficher(G->suivant);
}

void detruiteAdj(Adjacent * adj)
{
    if(adj->suivant != NULL)
    {
        detruiteAdj(adj->suivant);
    }
    printf("Adjacents %d\n", adj->sommet);
    free(adj);
}


void detruire(Graphe* G)
{
    if(G->suivant != NULL)
    {
        detruire(G->suivant);
    }
    detruiteAdj(G->list_adjacents);
    printf("Sommet %d\n", G->id);
    free(G);
}


void parcours_largeur(Graphe* G, int s) {
	// Ã  implementer..
}

void imprimer_chemin(Graphe* G, int s, int v) {
	// Ã  implementer..
}