typedef struct
{
    char code_F[17];

} Record;

typedef struct 
{
    Record r;
    int p;
    int p1;
    int p2;
    int p3;


}Dato;

typedef struct nodo
{
    Dato dato;
    struct nodo *next;
} Nodo;

typedef Nodo *Lista;
void nuovaLista(Lista *pl);
void insTesta(Lista *pl, Dato d);
void stampa(Lista l);
void insOrd(Lista *pl, Dato d);
void aggiorna(Lista *pl, Lista *pl2);