#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "fila_simples.h"

//Essa parte achamos na internet para simular um try and catch
//Link: https://web.archive.org/web/20091104065428/http://www.di.unipi.it/~nids/docs/longjump_try_trow_catch.html
// #define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
// #define CATCH } else {
// #define ETRY } }while(0)
// #define THROW longjmp(ex_buf__, 1)


void Enter2Cont(){
	char opcao;
	int achou = 0;
	while ((getchar()) != '\n'); 
	printf("Deseja continuar [S/N]? ");
	while((opcao = getchar()) && opcao != '\n'){
		if(opcao == 'S' || opcao == 's' && achou == 0) achou =1;
	}
	if (achou)
	{
		system("cls||clear");
	}
	else if(opcao != 'N' || opcao != 'n'){
		Enter2Cont();
	}
	else{
		printf("Saindo\n");
		exit(0);
	}

}


int main()
{
	if(fila_vazia()){
		cria_fila();
	}

	int opcao, N, numero, i;
	do
	{
		printf("MENU\n");
		printf("Escolha a opca desejada:\n");
		printf("1- Inserir n elementos na fila.\n2- Remover n elementos na fila.\n3- Imprimir a fila.\n4- Sair.\nOpção: ");
		scanf("%d", &opcao);
		system("clear");
		switch(opcao)
		{
			case 1:
			printf("Digite quantos elementos voce quer inserir: ");
			scanf("%d", &N);
			for(i = 0; i < N; i++)
			{
				if(fila_cheia()) {
					printf("Não foi possivel inserir %d numeros pois a fila encheu.\n",N-i);
					break;
				}
				printf("Inserido o %dº elemento:\n",i+1);
				scanf("%d", &numero);
				if(numero >= 0 && numero <= 999)
				{
					if(!fila_cheia()){
						system("clear");
						enfileira(numero);
					}
					
				}
				else
				{
					i--;
					printf("O numero %d nao foi inserido, pois nao e um numero valido", numero);
				}
			}
			Enter2Cont();
			break;

			case 2:
			printf("Digite quantos elementos voce quer remover: ");
			scanf("%d", &N);
			for(i = 0; i < N; i++)
			{
				if(fila_vazia()){
					printf("Não foi possivel remover %d numeros pois a fila está vazia.\n",N-i);
					break;
				}
				else{
					printf("Removido o numero: %d.\n",desenfileira());
				}
			}
			Enter2Cont();
			break;
			case 3:
				imprimir_fila();
				Enter2Cont();
			break;
		}
	}while(opcao != 4);


}
