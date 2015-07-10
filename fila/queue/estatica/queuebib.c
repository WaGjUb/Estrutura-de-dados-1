
#include "queuebib.h"

Queue *createQueue() {
	Queue* q;
	q = (Queue*) malloc(sizeof(Queue));
	q->lenght = SIZE;
	q->items = (ItemType*) calloc(q->lenght, sizeof(ItemType));	
	return(q);
}
 
void initializeQueue(Queue *q) {
	q->first = 0;
	q->last = 0;
}

int enqueue(Queue * q, ItemType e){

	if ((q->last+1 == q->first) || ((q->last == q->lenght) && (q->first == 0)))
	{
		return(false);
	}
	else 
	{
		
		q->items[q->last] = e;
		q->last++;

		if (q->last > q->lenght)
		{
			q->last=0;
		}
		return(true);
	}
}

int dequeue(Queue* q, ItemType* e){

	if (q->last == q->first)
	{
		return(false);
	}
	else
	{
		*e = q->items[q->first];
		q->first++;
		return(true);
	}
}

int peek(Queue* q, ItemType* e){
	
	if (q->last == q->first)
	{
		return(false);
	}
	else
	{
		*e = q->items[q->first];
		return(true);
	}
}

int contains(Queue* q, ItemType *e){
	
	int i = 0, iback, quantidade;

	if (q->last > q->first)
	{
		quantidade = (q->first - q->last);
	}
	else
	{
		quantidade = (q->last - q->first);
	}
	
	for (i=0; i<quantidade; i++)
	{
		iback = iback+q->first;

		if (iback == q->lenght)
		{
			iback -= q->lenght;
		}
		
		if (q->items[iback] == *e)
		{
		return(true);
		}
	}
	return(false);
} 

int sizeQueue(Queue* q){
	
	int quantidade = q->last - q->first;
	
	return((quantidade<0) ? (quantidade*-1) : quantidade);
}

int isEmptyQueue(Queue* q){
	if (q->first == q->last)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
void printQueue(Queue* q){
	int i = 0, iback, quantidade;

	if (q->last > q->first)
	{
		quantidade = (q->first - q->last);
	}
	else
	{
		quantidade = (q->last - q->first);
	}
	
	for (i=0; i<quantidade; i++)
	{
		iback = iback+q->first;

		if (iback == q->lenght)
		{
			iback -= q->lenght;
		}
		printf("%d\n",q->items[iback]); 	
	}

}
