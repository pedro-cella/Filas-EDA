#include <stdio.h>
#include <stdlib.h>
#include "fila_redimensionamento.h"

static int *fila;
static int N, p, u;

void cria_fila()
{
    N = 10;
    fila = malloc(N * sizeof(int));
    p = 0;
    u = 0;
}

int redimensiona() {

    int i, j;
    printf("Redimensionamento realizado !\n");
    fila = realloc( fila, 2 * N * sizeof(int) );
    if ( fila == NULL ){
        return -1;
    }

    if ( u != N-1 ) {
      if ( u-1 < N-p ) {
        for ( i = N, j = 0; j < u; i++, j++ ) {
	  fila[i] = fila[j];
        }
        u = N+u;
      }
      else{
        for ( i = p, j = N+p; i < N; i++, j++ ) {
	  fila[j] = fila[i];
        }
        p = N+p;
      }
    }
    N *= 2;
    return 1;
}

int enfileira(int c)
{
    int ret = 1;
    if(fila_cheia())
      ret = redimensiona();

    if(ret) {
      fila[u++] = c;
      if ( u == N ) u = 0;
    }
    return ret;
}

int desenfileira()
{
    int c;
    if(!fila_vazia())
    {
        c = fila[p++];
        if(p == N) p = 0;
        return c;
    }
}

int fila_vazia()
{
    return p == u;
}

int fila_cheia()
{
    return (u + 1) % N == p;
}

int tam_fila(){
    int total = u-p;
    if(p>u){
        total = N - total;
    }
    return 0;
}

void imprimir_fila(){

    char Pc, Uc;
    int Pi, Ui;
    if(p<=u){
        Pc = 'p';
        Pi = p;
        Uc = 'u';
        Ui = u;
    }
    else{
        Pc = 'u';
        Pi = u;
        Uc = 'p';
        Ui = p;
    }


     printf("+");
    for(int i = 0;i < N;i++)
        printf("-----+");
    printf("\n");

    printf("|");
    for(int i = 0;i < N;i++){
        int valor = fila[i];
        if(valor>1000){
            valor = 000;
        }
        printf(" %03d |", valor);
    }

    printf("\n");

    printf("+");
    for(int i = 0;i < N;i++)
        printf("-----+");
    printf("\n");



    for(int i = 0;i <= Ui;i++){
        if(i == Pi){
            printf("   %c",Pc);
            for(int i = Pi; i <= N; i++){
                if(i == Ui){
                    printf("%c",Uc);
                }
                else{
                    printf("      ");
                }
            }
            break;
        }
        else{
            printf("      ");
        }
    }

    printf("\n");
}
