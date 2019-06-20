#include <stdio.h>
#include "fila_simples.h"
#define N 10

static int fila_simples[N];
static int p, u;

void cria_fila()
{
    p = 0;
    u = 0;
}

int enfileira(int y)
{
    if(fila_cheia()) return 0;
    else fila_simples[u++] = y;
    return 1;
}

int desenfileira(int *c)
{
    return fila_simples[p++];
}

int fila_vazia()
{
    if(p == u)
    {
        cria_fila();
    }
    return p == u;
}

int fila_cheia()
{
    return u == N;
}

void imprimir_fila(){
    printf("+");
    for(int i = 0;i < N;i++)
        printf("-----+");
    printf("\n");

    printf("|");
    for(int i = 0;i < N;i++)
    {
        printf(" %03d |", fila_simples[i]);
    }

    printf("\n");

    printf("+");
    for(int i = 0;i < N;i++)
        printf("-----+");
    printf("\n");

    for(int i = 0;i <= u;i++)
    {
        if(i == p)
    {
            printf("   p");
            for(int i = p; i <= N; i++)
        {
                if(i == u)
        {
                    printf("u");
                }
                    else
            {
                        printf("      ");
                    }
            }
            break;
        }
        else
    {
            printf("      ");
        }
    }

    printf("\n");
}

void freeFila(){
    
}

