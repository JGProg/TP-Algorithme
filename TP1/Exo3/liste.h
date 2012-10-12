#ifndef LISTE_H
#define LISTE_H

#include <stdio.h>
#include <stdlib.h>


struct element
{
    int valeur;
    struct element *succ;
    struct element *pre;
};

typedef struct listeStruct
{
    size_t longueur;
    struct element *queue;
    struct element *tete;
} Liste;

// \pre Aucun
// \post Creation d'une nouvelle liste vierge
Liste *Nouvelle_Liste(void);

// \pre La liste existe
// \post Suppresion de la liste
void SupprimerListe(Liste **list);

// \pre Aucun
// \post Creation d'une nouvelle liste vierge
void AfficherListe(Liste *list);

// \pre La liste existe
// \post Ajout de l'élément sans prendre en compte si la liste doublement chainée est triée
// \brief qui permet d'ajouter un entier i à la liste
Liste *AjouterElement(Liste *list, int valeur);

// \pre La liste existe
// \post Insertion de la valeur en tête de liste
Liste *AJouterEnDebutDeListe(Liste *list, int valeur);

// \pre La liste existe
// \post Insertion de la valeur dans une chaine triée
// \brief INSERER_ELEMENT(List, valeur) qui permet l'insertion d'un élément 'valeur' déjà initialisé dans la bonne place de la liste chaînée triée.
Liste *InsertionTrie(Liste *list, int valeur);

// \pre La liste existe
// \post La première occurence de la valeur a été supprimé de la liste
// \brief qui permet de supprimer l'élément 'valeur' de la liste chaînée list
Liste *SuppressionElement(Liste *list, int valeur);

// \pre La liste existe
// \post Suppression toutes les valeurs ayant cette même valeur
// \brief qui permet de supprimer toutes les occurrences de l'entier 'valeur' dans la liste 'list'
Liste *SuppressionOccurenceElement(Liste *list, int valeur);

// \pre La liste existe
// \post Si la valeur a été trouvé on retourne le pointeur de l'élement sinon NULL
// \brief qui trouve le premier élément de valeur 'valeur' dans la liste 'list' et retourne un pointeur sur cet élément. Si aucun objet de valeur 'valeur' n'apparaît dans la liste, la procédure retourne NIL.
Liste *RechercheElement(Liste *list, int valeur);

#endif
