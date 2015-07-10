#include "queuebib.h"

Queue *createQueue ()
{
	Queue* q;
	q = (Queue*) calloc(1, sizeof(Queue));	
	return(q);
}

void initializeQueue(Queue *q)
{
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
}

int enqueue(Queue * q, ItemType e, int (pFuncao*)(void*,void*))
{
	Node* aux;
	int cont=0;
	aux = (Node*) malloc(sizeof(Node));
	aux->data = e;
	aux->next = NULL;
	Node* redutor,*redutorprev;

	//first
	if (q->size == 0)
	{
		q->first = aux;
		q->last = aux;
		q->size++;
		return(true);
	}

	redutor = q->first;
	
		while (redutor != NULL)
		{
			//if (aux->data <= redutor->data)
			if(pFuncao(&aux->data,&redutor->data)<=0)
			{
				if (redutor == q->first)
				{
					aux->next = q->first;
					q->first = aux;
					break;
				}
			
				else
				{
				aux->next = redutorprev->next;
				redutorprev->next = aux;
				break;
				}
			}
			redutorprev = redutor;
			redutor = redutor->next;
		}

		if (redutor == NULL)
		{
				if (redutorprev == q->first)
				{
			//		aux=->next = q->
				}
		 aux->next = q->last->next;
		 q->last->next = aux;
		 q->last = aux;
		}
	


	q->size++;
	return(true);
}

int dequeue(Queue* q, ItemType* e)
{
	if (q->first == NULL)
	{
		return(false);
	}

	Node *aux;

	aux = (Node*) malloc(sizeof(Node));
	*e = q->first->data;
	aux = q->first;
	q->first = q->first->next;
	free(aux);
	q->size--;
	return(true);
}

int peek(Queue* q, ItemType* e)
{
	if (q->first == NULL)
	{
		return(false);
	}
	else
	{
		*e = q->first->data;
		return(true);
	}
}

int contains(Queue* q, ItemType *e)
{
	//realizarei sem utilizar a variavel size;
	Node *backup;
	backup = q->first;
	
	while(backup != NULL)
	{
		if (backup->data == *e)
		{
			return(true);
		}	
		backup = backup->next;
	}
	
	return(false);
}

int sizeQueue(Queue* q)
{
	//esse aqui também
	int cont=0;
	Node *aux; 
	
	aux = q->first;
	
	while (aux != NULL)
	{
		cont++;
		aux = aux->next;
	}

	return(cont);
}

int isEmptyQueue(Queue* q)
{
	if(q->first == NULL)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

void printQueue(Queue* q)
{
	//+1 =D

	Node *aux;
	int i=1;
	
	aux = q->first;

	while (aux != NULL)
	{
		printf("%dº valor da fila: %d\n", i++, aux->data);
		aux = aux->next;
	}
}

