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

int enfileira(int y, celula *fi)
{
    celula *nova;
    nova = malloc(sizeof(celula));
    nova -> prox = fi -> prox;
    fi -> prox = nova;
    fi -> conteudo = y;
    return nova;
}

int desenfileira(lista *fi)
{
    celula *p;
    p = fi -> prox;
    int x = p -> conteudo;
    fi -> prox = p -> prox;
    free(p);
    return x;
}
void imprimir_fila(lista *le)
{

}
