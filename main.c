#include <stdio.h>
#include <stdlib.h>
#include "fila_simples.h"

int main()
{
    int opcao, N, numero;
    do
    {
        printf("MENU\n");
        printf("Escolha a opca desejada:\n");
        printf("1- Inserir n elementos na fila.\n2- Remover n elementos na fila.\n3- Imprimir a fila.\n4- Sair.");
        scanf("%d", &opcao);
        system("clear");

	switch(opcao)
	{
            case 1:
		    printf("Digite quantos elementos voce quer inserir: ");
		    scanf("%d\n", &N);
		    for(i = 0; i < N; i++)
		    {
	                scanf("%d", &numero);
                        if(numero >= 0 && numero <= 999)
			{

			}
			    else
			    {
                                printf("O numero %d nao foi inserido, pois nao e um numero valido", numero);
			    }
		    }
                    break;

            case 2:
		    printf("Digite quantos elementos voce deseja remover: ");
		    scanf("%d\n", &N);
		    break;
	    case 3:
		    break;
	}
    }while(opcao != 4);


}
