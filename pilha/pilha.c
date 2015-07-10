#include <stdio.h>
#include "TAD_pilha_estatica.h"

int main() {
	Stack *s;
	int i, removed, returned, e=5;

	s = createStack();
	initializeStack(s);
	for (i=0; i<10; i++)
	{
		if(push(s, 5+i+1) == true)
		{
		printf("O valor %d foi inserido!\n", 5+i+1);
		}
		else
		{
		printf("O valor %d não pôde ser inserido.\n", 5+i+1);
		}
	}

	for (i=0; i<7; i++)
	{
		if (pop(s, &removed)==true)
		{
			printf("Topo removido com sucesso, o valor era: %d\n", removed);
		}
		else
		{
			printf("Não foi possível remover o topo\n");
		}
	}

	if (top(s, &returned) == true)
	{
		printf("O valor do topo é: %d\n", returned);
	}
	else
	{
		printf("Não há nada no topo.\n");
	}
	
	printStack(s);

	if (containsStack(s, &e) == false)
	{
		printf("O valor 5 não está presente na pilha.\n");
	}
	else
	{
		printf("O valor 5 está presente na pilha.\n");
	}

	e++;
	if (containsStack(s, &e) == false)
	{
		printf("O valor 6 não está presente na pilha.\n");
	}
	else
	{
		printf("O valor 6 está presente na pilha.\n");
	}

	printf("Tamanho da pilha: %d\n",sizeStack(s));

	if (isEmptyStack(s) == true)
	{
			printf("A pilha está vazia.\n");
	}
	else
	{
		printf("A pilha não está vazia.\n");
	}
return(0);	
}
