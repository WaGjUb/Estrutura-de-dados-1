#ifndef __queuebib__
#define __queuebib__
#define SIZE 10
#define ItemType int
#include <stdlib.h>
#include <stdio.h>

	typedef struct {
	int first, last, lenght;
	ItemType* items;
	}Queue;
	
	typedef enum {false=0, true} boolean;

Queue *createQueue (); // Criar a fila 
void initializeQueue(Queue *q); // Inicializa a fila 
int enqueue(Queue * q, ItemType e); // Inserir um elemento na fila; 
int dequeue(Queue* q, ItemType* e); // Remover um elemento da fila 
int peek(Queue* q, ItemType* e); // Recuperar informações do primeiro da fila 
int contains(Queue* q, ItemType *e); // Verificar se um elemento está na fila 
int sizeQueue(Queue* q); // Verificar quantos elementos existem na fila 
int isEmptyQueue(Queue* q); // Verificar se a fila está vazia 
void printQueue(Queue* q); // Ver todo o conteúdo da fila. 

#endif
