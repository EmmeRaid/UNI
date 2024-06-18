#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaParole.h"

void nuovaLista(Lista *pl)
{
    *pl = NULL;
}

void insTesta(Lista *pl, Dato d)
{
    Nodo *aux = (Nodo *)malloc(sizeof(Nodo));
    if (aux == NULL)
        exit(100);
    aux->dato = d;
    aux->next = *pl;
    *pl = aux;
}

void aggiornaLista(Lista *pl, char *parola)
{
    while (pl != NULL )
    {
        strcpy((*pl)->dato.parola, parola);
        pl = &(*pl)->next;
    }
}

void stampa(Lista l)
{
    while (l)
    {
        printf("%s %d\n", l->dato.parola, l->dato.cont);
        l = l->next;
    }
}