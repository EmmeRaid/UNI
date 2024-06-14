#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaUtenti.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{

    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100); // allocazione non riuscita
    
    if (d.p == 1)
    {
        (*pl)->dato.p1 = (*pl)->dato.p1 - 1;
    }
    if (d.p == 2)
    {
        (*pl)->dato.p2 = (*pl)->dato.p2 - 1;
    }
    if (d.p  == 3)
    {
        (*pl)->dato.p3 = (*pl)->dato.p3 - 1;
    }

    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void stampa(Lista l)
{
    while (l)
    {
        printf("Codice fiscale: %s %d %d %d %d \n", l->dato.r.code_F, l->dato.p, l->dato.p1, l->dato.p2, l->dato.p3);
        l = l->next;
    }
}

Lista *ricerca(Lista *pl, Dato d)
{
    while (*pl)
    {
        if (strcmp((*pl)->dato.r.code_F, d.r.code_F) > 1)

            break;
        pl = &(*pl)->next;
    }

    return pl;
}

void insOrd(Lista *pl, Dato d)
{
    pl = ricerca(pl, d);
    insTesta(pl, d);
}
