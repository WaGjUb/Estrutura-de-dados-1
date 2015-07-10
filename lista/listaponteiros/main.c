#include <stdio.h>
#include "bibponteiros.h"

int main(){

	int sel;

	printf("Selecione o exercício desejado: ");
	scanf("%d", &sel);

	switch (sel)
	{

		case 1:
			{
				int pos, val;
				printf("Digite o tamanho de posições e o valor de inicialização do vetor: ");
				scanf("%d %d", &pos, &val);
				criaVet(pos, val); //chamando a func
				break;
			}

		case 2:
			{
				int n;
				printf("Digite o valor de n: ");
				scanf("%d", &n);
				criaVetAl(n); //chamando a func
			}

		case 3:
			{
				int lin,col,val;
				printf("Digite o número de linhas, colunas e o valor de inicialização: ");
				scanf("%d %d %d", &lin, &col, &val);
				criaMat(lin,col,val); //chamando a func
			}

		case 4:
			{ 
				char vet[21];
				printf("Digite uma string para ser copiada: ");
				scanf("%[^\n]", vet);
				strCopy(vet); //chamando a func
			}

	}

	return(0);
}
