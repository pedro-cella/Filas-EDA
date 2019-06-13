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

int enfileira(int c)
{
    int ret = 1;
    if(u == N-1) ret = redimensionamento();
    if(ret) fila[u++] = c;
    return ret;
}

int desenfileira(int *c)
{
    if(!fila_vazia())
    {
        *c = fila[p++];
	if(p == N) p = 0;
	return 1;
    }
    return 0;
}

int fila_vazia()
{
    return p == u;
}

int fila_cheia()
{
    return (u + 1) % N == p;
}
