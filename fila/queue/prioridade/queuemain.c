#include "queuebib.h"
#include <time.h>
#include <stdlib.h>

int IntCmp(void* a, void* b)
{
	int *A=a, *B=b;
	if (*A < *B) return(-1);
	else if (*A > *B) return(1);
	else return (0);
}

int main(){
	
	Queue *fila;
	int i, val;
	
	fila = createQueue();
	initializeQueue(fila);
	
	srand(time(NULL));

	for (i=10; i>0; i--)
	{

		if (enqueue(fila, rand()%30), &IntCmp)
		{
			printf("O valor foi inserido\n");
		}
		else
		{
			printf("Não há mais espaço na fila\n");
		}
	
	}
	for (i=0; i<4; i++)
	{
		if (dequeue(fila, &val))
		{
			printf("--%d\n", val);
		}
		else
		{
			printf("Não há nada na fila\n");
		}
	}

	if (peek(fila, &val)) 
	{
		printf("peek: %d\n", val);
	}
	else
	{
		printf("Não há nada na fila\n");
	}
	
	printf("Tamanho da fila: %d\n", sizeQueue(fila));
	
	if (isEmptyQueue(fila))
	{
		printf("A fila está vazia\n");
	}
	else
	{
		printf("A fila não está vazia\n");
	}	 	
	
	printQueue(fila);
return(0);
}

