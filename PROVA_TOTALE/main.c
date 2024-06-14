#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaUtenti.h"

int main(int argc, char *argv[])
{
    Dato d;
    Record r;
    Lista l, l2, l3;

    d.p1 = 4;
    d.p2 = 4;
    d.p3 = 4;
    if (argc != 3)
    {
        printf("Errore: %s + File da leggere + secondo file \n", argv[0]);
        exit(-1);
    }

    FILE *pf;

    pf = fopen(argv[1], "rb");

    if (pf == NULL)
    {
        printf("Errore: %s + codicifiscali.dat \n", argv[0]);
        exit(-1);
    }

    nuovaLista(&l);
    if (&l == NULL)
    {
        printf("Errore: %s + File da leggere \n", argv[0]);
    }
    else
    {
        printf("Lista Creata \n");
    }

    while (fread(&d, sizeof(Record), 1, pf) == 1)
    {
        insOrd(&l, d); // INSERIMENTO IN TESTA DEL DATO
    }

    // CHIUSURA PRIMO FILE
    fclose(pf);
    stampa(l);

    pf = fopen(argv[2], "rt");

    if (pf == NULL)
    {
        printf("Errore: %s %s, file.txt\n", argv[0], argv[1]);
        exit(-1);
    }

    // CREAZIONE NUOVA LISTA
    nuovaLista(&l2);

    while (fscanf(pf, "%s %d", d.r.code_F, &d.p) != EOF)
    {
        insTesta(&l2, d); // INSERIMENTO IN TESTA DEL DATO AGGIORNATO
    }

    puts("aggiornamento lista");



    // CHIUSURA SECONDO FILE
    fclose(pf);
    puts("Seconda lista");
    stampa(l2);

    return (0);
}