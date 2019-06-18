#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int dado;
    struct elem *prox;
}celula;

celula *lista;

void cria_fila()
{
    lista = malloc(sizeof(celula));
    lista -> prox = lista;
}

int enfileira(int y, celula *lista)
{
    celula *nova;
    nova = malloc(sizeof(celula));
    nova -> prox = lista -> prox;
    lista -> prox = nova;
    lista -> conteudo = y;
    return nova;
}

int desenfileira(lista *lista)
{
    celula *p;
    p = lista -> prox;
    int x = p -> conteudo;
    lista -> prox = p -> prox;
    free(p);
    return x;
}
void imprimir_fila()
{

}
