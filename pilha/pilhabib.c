#include <stdlib.h>
#include <stdio.h>
#include "TAD_pilha_estatica.h"

Stack* createStack()
{
	Stack* s;
	s = (Stack*) malloc(sizeof(Stack));
	s->top = 0;
	s->length = STACK_LENGTH;
	s->items = (ItemType*) malloc(sizeof(ItemType)*s->length);
	return(s);
}

void initializeStack(Stack *stack)
{
	int i;

	stack->top = 0;
	stack->length = STACK_LENGTH;

	for (i=0; i<(stack->length); i++)
	{
		stack->items[i] = 0;
	}
}

Boolean push(Stack* stack, ItemType e)
{
	if (stack->length == stack->top)
	{
		return(false);
	}
	else
	{
		stack->items[stack->top] = e;
		stack->top++;
		return(true);
	}
}

Boolean pop(Stack* stack , ItemType* removed)
{
	if (stack->top == 0)
	{
		return(false);
	}
	else
	{
		*removed = stack->items[stack->top-1];
		stack->items[stack->top-1] = 0;
		stack->top--;
		return(true);
	}
}

Boolean top(Stack* stack, ItemType* returned)
{
	if (stack->top == 0)
	{
		return(false);
	}
	else
	{	
		*returned = stack->items[stack->top-1];
		return(true);
	}	
}

void printStack(Stack* stack)
{

	int i;
	if (stack->top != 0)
	{
		printf("Valores da pilha: ");
		for (i=0; i<(stack->top); i++)
		{
			printf("%d", stack->items[i]);
			if (i != stack->top-1)
			{
				printf(", ");
			}
		}
		printf("\n");
	}
}

Boolean	containsStack(Stack* stack, ItemType *e)
{
	int i, valida=0;

	for (i=0; i<(stack->top); i++)
	{
		if (*e == stack->items[i])
		{
			valida++;
		}
	}
	if (valida == 0)
	{
		return(false);
	}
	else 
	{
		return(true);
 	}
}

int sizeStack(Stack* stack)
{
	return(stack->top);
}

Boolean isEmptyStack(Stack* stack)
{
	if (stack->top == 0)
	{
		return(true);
	}	
	else
	{
		return(false);
	}
}
