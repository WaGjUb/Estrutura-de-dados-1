#include "pilhadinamica.h"
#include <stdlib.h>
#include <stdio.h>
void initializeStack(Stack * stack)
{
	stack->size = 0;
	stack->top = NULL;	
}

Stack* createStack()
{
	Stack* s;
	s = (Stack*) malloc(sizeof(Stack));
	initializeStack(s);
	return(s);
}

int push(Stack* stack, ItemType e)
{
 Node *aux;	
	aux = (Node*) malloc(sizeof(Node));	
	aux->data = e;
	aux->next = stack->top;
	stack->top = aux;
	stack->size++;
	return(0);
}

int /*O papa é*/pop(Stack* stack, ItemType* e)
{
	if (stack->top == NULL)
	{
		return(1);
	}
	else{
		Node *aux;
		aux = stack->top;
		stack->top = aux->next;
		aux->next = NULL;
		*e =  aux->data;
		free(aux);
		stack->size--;
		return(0);
	}
}

int peek(Stack* stack, ItemType* e)
{
	if (stack->top == NULL)
	{
		return(1);
	}
	else
	{
		*e = stack->top->data;
		return(0);
	}
}

int contains(Stack* stack, ItemType *e)
{
	Node *aux;
	aux = stack->top;
	if (stack->top == NULL)
	{
		return(1);
	}
	else
	{
		while(aux != NULL)
		{
			if (aux->data == *e)
			{
				aux = NULL;
				free(aux);
				return(0);
			}
			else
			{
				aux = aux->next;
			}
		}
	}
	aux = NULL;
	free(aux);
	return(1);
}
int sizeStack(Stack*stack)
{
	Node *aux;
	aux = stack->top;
	int tamanho=0;

	while (aux!=NULL)
	{
		tamanho++;
		aux = aux->next;
	}
	return(tamanho);
}

int isEmptyStack(Stack* stack)
{
	if (stack->top == NULL)
	{
		return(0);
	}
	else
	{
		return(1);
	}
}
void printStack(Stack* stack)
{
	Node *aux;
	aux=stack->top;
	
	while (aux != NULL)
	{
		printf("%d\n", aux->data);
		aux = aux->next;
	}
}

