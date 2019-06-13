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

void enfileira(int y)
{
    fila_simples[u++] = y;
}

int desenfileira()
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
