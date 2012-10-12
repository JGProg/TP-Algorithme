#include "liste.h"

Liste *list = NULL;

// \pre Aucun
// \post Creation d'une nouvelle liste vierge
Liste *Nouvelle_Liste(void)
{
    Liste *nouvList = malloc(sizeof *nouvList);
    if (nouvList != NULL)
    {
        nouvList->longueur = 0;
        nouvList->tete = NULL;
        nouvList->queue = NULL;
    }
    return nouvList;
}

// \pre La liste existe
// \post Ajout de l'élément sans prendre en compte si la liste doublement chainée est triée
Liste *AjouterElement(Liste *list, int valeur)
{
    if (list != NULL)
    {
        struct element *nouvElement = malloc(sizeof *nouvElement);
        if (nouvElement != NULL)//Test malloc
        {
            nouvElement->valeur = valeur;
            nouvElement->succ = NULL;
            if (list->queue == NULL)
            {
                nouvElement->pre = NULL;
                list->tete = nouvElement;
                list->queue = nouvElement;
            }
            else
            {
                list->queue->succ = nouvElement;
                nouvElement->pre = list->queue;
                list->queue = nouvElement;
            }
            list->longueur++; /* Incrémentation de la taille de la liste */
        }
    }
    return list; /* on retourne notre nouvelle liste */
}

// \pre La liste existe
// \post Insertion de la valeur en tête de liste
Liste *AJouterEnDebutDeListe(Liste *list, int valeur)
{
    if (list != NULL)
    {
        struct element *nouvElement = malloc(sizeof *nouvElement);
        if (nouvElement != NULL)
        {
            nouvElement->valeur = valeur;
            nouvElement->pre = NULL;
            if (list->queue == NULL)
            {
                nouvElement->succ = NULL;
                list->tete = nouvElement;
                list->queue = nouvElement;
            }
            else
            {
                list->tete->pre = nouvElement;
                nouvElement->succ = list->tete;
                list->tete = nouvElement;
            }
            list->longueur++;
        }
    }
    return list;
}


// \pre La liste existe
// \post Insertion de la valeur dans une chaine triée
Liste *InsertionTrie(Liste *list, int valeur)
{
    if (list != NULL)
    {
        struct element *p_temp = list->tete;
        while (p_temp != NULL && p_temp->valeur < valeur )
        {
            p_temp = p_temp->succ;
        }
        
        if(p_temp == NULL)
        {
            list = AjouterElement(list, valeur);
        }
        else
        {
            if (p_temp->pre == NULL)
            {
                list = AJouterEnDebutDeListe(list, valeur);
            }
            else
            {
                struct element *nouvElement = malloc(sizeof *nouvElement);
                if (nouvElement != NULL)
                {
                    nouvElement->valeur = valeur;
                    p_temp->succ->pre = nouvElement;
                    p_temp->pre->succ = nouvElement;
                    nouvElement->pre = p_temp->pre;
                    nouvElement->succ = p_temp;
                    list->longueur++;
                }
            }
        }
    }
    return list;
}


// \pre La liste existe
// \post Suppresion de la liste
void SupprimerListe(Liste **list)
{
    if (*list != NULL)
    {
        struct element *p_temp = (*list)->tete;
        while (p_temp != NULL)
        {
            struct element *p_del = p_temp;
            p_temp = p_temp->succ;
            free(p_del);
        }
        free(*list), *list = NULL;
    }
}

// \pre Aucun
// \post Affiche NULL si la liste n'existe pas sinon elle affiche la liste avec NULL à la fin
void AfficherListe(Liste *list)
{
    if (list != NULL)
    {
        struct element *p_temp = list->tete;
        while (p_temp != NULL)
        {
            printf("%d -> ", p_temp->valeur);
            fflush(stdout);
            p_temp = p_temp->succ;
        }
    }
    printf("NULL\n");
}

// \pre La liste existe
// \post La première occurence de la valeur a été supprimé de la liste
Liste *SuppressionElement(Liste *list, int valeur)
{
    if (list != NULL)
    {
        struct element *p_temp = list->tete;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (p_temp->valeur == valeur)
            {
                if (p_temp->succ == NULL)
                {
                    list->queue = p_temp->pre;
                    list->queue->succ = NULL;
                }
                else if (p_temp->pre == NULL)
                {
                    list->tete = p_temp->succ;
                    list->tete->pre = NULL;
                }
                else
                {
                    p_temp->succ->pre = p_temp->pre;
                    p_temp->pre->succ = p_temp->succ;
                }
                free(p_temp);
                list->longueur--;
                found = 1;
            }
            else
            {
                p_temp = p_temp->succ;
            }
        }
    }
    return list;
}

// \pre La liste existe
// \post Suppression toutes les valeurs ayant cette même valeur
Liste *SuppressionOccurenceElement(Liste *list, int valeur)
{
    if (list != NULL)
    {
        struct element *p_temp = list->tete;
        while (p_temp != NULL)
        {
            if (p_temp->valeur == valeur)
            {
                struct element *p_del = p_temp;
                p_temp = p_temp->succ;
                if (p_del->succ == NULL)
                {
                    list->queue = p_del->pre;
                    list->queue->succ = NULL;
                }
                else if (p_del->pre == NULL)
                {
                    list->tete = p_del->succ;
                    list->tete->pre = NULL;
                }
                else
                {
                    p_del->succ->pre = p_del->pre;
                    p_del->pre->succ = p_del->succ;
                }
                free(p_del);
                list->longueur--;
            }
            else
            {
                p_temp = p_temp->succ;
            }
        }
    }
    return list;
}

// \pre La liste existe
// \post Si la valeur a été trouvé on retourne le pointeur de l'élement sinon NULL
Liste *RechercheElement(Liste *list, int valeur)
{
    Liste *ret = NULL;
    if (list != NULL)
    {
        struct element *p_temp = list->tete;
        int found = 0;
        while (p_temp != NULL && !found)
        {
            if (p_temp->valeur == valeur)
            {
                ret = Nouvelle_Liste();
                ret = AjouterElement(ret, valeur);
                found = 1;
            }
            else
            {
                p_temp = p_temp->succ;
            }
        }
    }
    return ret;
}