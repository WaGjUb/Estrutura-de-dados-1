#include "queuebib.h"

int main(){
	
	Queue *fila;
	int i, val;
	
	fila = createQueue();
	initializeQueue(fila);
	
	for (i=0; i<10; i++)
	{
		if (enqueue(fila, i))
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

