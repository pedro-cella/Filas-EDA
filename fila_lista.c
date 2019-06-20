#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fila_lista.h"

struct elem
{
	int dado;
	struct elem *prox;
};

typedef struct elem lista;

static lista *ListaCabeca;


void cria_fila()
{
	ListaCabeca = malloc(sizeof(lista));
	ListaCabeca->prox = ListaCabeca;
   
}

int enfileira(int y)
{
   lista *nova;
   nova = malloc (sizeof (lista));
   if(nova==NULL) return -1; 
   nova->prox = ListaCabeca->prox;
   ListaCabeca->prox = nova;
   ListaCabeca->dado = y;   
   ListaCabeca = nova;
}

int desenfileira()
{
   lista *retirar;
   retirar = ListaCabeca->prox;  // o primeiro da fila
   int x = retirar->dado;
   ListaCabeca->prox = retirar->prox;
   free (retirar);
   return x; 
}


int fila_vazia()
{
    return ListaCabeca->prox == ListaCabeca;

}

int fila_cheia()
{
   return 0;
}

void imprimir_fila(){
     
printf("+");
     lista *impressao;
    for (impressao = ListaCabeca -> prox; impressao->prox != ListaCabeca->prox; impressao = impressao->prox){
        printf("-----+");
    }
    printf("\n");
    printf("|");
   
impressao =  ListaCabeca->prox;

    while(impressao->prox != ListaCabeca->prox){

        printf(" %03d |", impressao->dado);
        impressao = impressao->prox;
    }

    printf("\n");
    printf("+");

    for (impressao = ListaCabeca -> prox; impressao->prox != ListaCabeca->prox; impressao = impressao->prox){
        printf("-----+");
    }

    printf("\n");
}


void freeFila(){
    free(ListaCabeca);
}
