#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaParole.h"

int main(int argc, char *argv[])
{

    char parola[LUNGHEZZA];
    Lista l1;

    if (argc != 2)
    {
        printf("Uso: %s testo.txt\n", argv[0]);
        exit(-1);
    }

    FILE *pf;

    pf = fopen(argv[1], "rt");

    if (pf == NULL)
    {
        printf("Uso: %s nome_file_corretto.txt\n", argv[0]);
        exit(-1);
    }

    nuovaLista(&l1);

    while (fscanf(pf,"%s", parola) == 1)
    {
        aggiornaLista(&l1, parola);
    }


    stampa(l1);

    fclose(pf);
    return 0;
}