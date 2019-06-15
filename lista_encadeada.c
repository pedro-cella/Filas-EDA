#include <stdio.h>
#include <stdlib.h>

void imprime(lista *le);
void imprime_recursivo(lista *le);
void imprime_contrario(lista *le);
lista *busca(int x, lista *le);
lista* busca_recursiva(int x, lista a *le);
void insere(int x, lista *p);
void insere(int x, lista *p);
void remove(lista *p);
int insere_posicao(int x, int pos);
int busca_e_insere(lista *le, int x, int y);

struct elem
{
	int dado;
	struct elem *prox;
}

typedef struct elem lista;


void imprime(lista *le)
{
	lista *p;
	
	for(p = le; p != NULL; p = p -> prox)
	{
		printf("%d", p -> dado);
	}
}

void imprime_recursivo(lista *le)
{
	if(le == NULL)
	{
		return;
	}
		else
		{
			printf("%d", le -> dado);
			imprime_recursivo(le -> prox);
			
			//Imprimir a lista ao contrário
			//imprime_recursivo(le -> prox);
			//printf("%d", le -> dado);
		}
}

void imprime_contrario(lista *le)
{
	if(le != NULL)
	{
		imprime_contrario(le -> prox);
		printf("%d ", le -> dado);
	}
}

lista *busca(int x, lista *le)
{
	lista *p;
	for(p = le; p != NULL && p -> dado != x; p = p -> prox);
	return p; 
}

lista* busca_recursiva(int x, lista a *le)
{
	if(le == NULL)
	{
		return NULL;
	}
		else
		{
			if(le -> dado == x)
			{
				return le;
			}
				else
				{
					return busca(x, le -> prox);
				}
		}
}

int insere(int x, lista *p)
{
	lista *novo;
	novo = malloc(sizeof(lista));
	if(novo == NULL)
	{
		return 0;
	}
	novo -> dado = x;
	novo -> prox = p -> prox;
	p -> prox = novo;
	
	return 1;
}

void remove(lista *p)
{
	lista *lixo = p -> prox;
	if(lixo != NULL)
	{
		p -> prox = lixo -> prox;
		free(lixo);
		return 1;
	}
	return 0;
}

int insere_posicao(lista *le, int x, int pos)
{
	lista *p = le;
	for(int i = 0; i < pos && p != NULL; i++)
	{
		p = p -> prox;
	}
	
	if(p != NULL)
	{
		return insere(x, p);
	}
		else
		{
			return 0;	
		}
}

int busca_e_insere(lista *le, int x, int y)
{
	lista *p = busca(y, le);
	if(p != NULL)
	{
		return insere(x, p);
	}
		else
		{
			return 0;
		}
}


