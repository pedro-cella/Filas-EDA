#include <stdio.h>
#include <stdlib.h>
#include "fila_redimensionamento.h"

int main()
{
  int elem, ret;
  
  if(fila_vazia()) {
    cria_fila();
  }
    
  int opcao, N, numero, i;
  do {
    printf("MENU\n");
    printf("Escolha a opca desejada:\n");
    printf("1- Inserir n elementos na fila.\n2- Remover n elementos na fila.\n3- Imprimir a fila.\n4- Sair.\nOpção: ");
    scanf("%d", &opcao);
    // system("clear");
    switch(opcao)
      {
      case 1:
	printf("Digite quantos elementos voce quer inserir: ");
	scanf("%d", &N);
	ret = 1;
	for(i = 0; i < N && ret; i++)
	  {
	    /* if(fila_cheia())//\**ERRO**  */
	    /* { */
	    /*     //printf("Não foi possivel inserir %d numeros pois a fila encheu.\n",N-i); */
	    /* 	redimensiona();//<-------ERRO! */
	    /* 	break; */
	    /* } */
	    printf("Inserido o %dº elemento:\n",i+1);
	    scanf("%d", &numero);
	    if(numero >= 0 && numero <= 999)
	      {
		ret = enfileira( numero );
		if ( ret == -1 ) {
		  printf( "Erro de alocacao\n" );
		}
		else {
		  if ( ret == 0 ) {
		    printf( "Fila cheia\n" );
		  }
		}
	      }
	    else
	      {
		i--;
		printf("O numero %d nao foi inserido, pois nao e um numero valido\n", numero);
	      }
	  }
	break;

      case 2:
	printf("Digite quantos elementos voce quer remover: ");
	scanf("%d", &N);
	for(i = 0; i < N && ret; i++)
	  {
	    ret = desenfileira( &elem );
	    if(ret == 0) {
	      printf("Não foi possivel remover %d numeros pois a fila está vazia.\n",N-i);
	      break;
	    }
	    else {
		printf("Removido o numero: %d.\n",elem);
	    }
	  }
	break;
		
      case 3:
	imprimir_fila();
	break;
      }

  }while(opcao != 4);
}
