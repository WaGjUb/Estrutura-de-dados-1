#include "listaestaticabib.h"

List *createList()
{
		List* l;
		l = (List*) malloc(sizeof(List));
		initializeList(l);
		return (l);
}

void initializeList(List *l)
{
		ItemType* array;

		array = (ItemType*) malloc(sizeof(ItemType)*tamanho); //cria array de ItemType

		l->size = 0;
		l->length = tamanho;
		l->items = array;	
}

int addLastList(List *l, ItemType e)
{
		if (l->size == l->length)
		{
				return(1);
		}


		l->items[l->size] = e;

		l->size++;
		return(0);
}
int addList(List* l, ItemType e, int index) //retorna 3 se o items está cheio,-1 se o index digitado é menor que 0, 1 se digitar um valor maior que o tamanho do items e 0 se o dado foi inserido.
{

		/*verifica se o items está cheio*/
		if (l->length == l->size)
		{
				return(3);
		}

		/*verifica se o index é valido*/
		if (index < 0)
		{
				return(-1);
		}
		else
		{
				if (index >= l->size)
				{
						return(1);
				}
		}
		/*verificado*/

		int pos=((l->size)-index); //indica quantas posições iremos andar

		memmove(&(l->items[index+1]), &(l->items[index]), sizeof(ItemType)*pos); //desloca o items a partir do index, uma posição para a direita
		l->items[index] = e;
		l->size++;
		return(0);	
}

int removeList(List* l, int index, ItemType* e)
{

		if ((index > l->size) || (index < 0))
		{
				return(1);
		}

		int pos;
		pos = (l->size-1)-index;
		*e = l->items[index];
		memmove(&(l->items[index]), &(l->items[index+1]), sizeof(ItemType)*pos);
		l->size--;
		return(0);
}

int removeElementList(List* l, ItemType* e) //retorna 1 se todos os elementos dados foram removidos e 0 se nenhum elemento foi encontrado
{

		bool verificador = false;
		int i;
		for (i=0; i<l->size; i++)
		{
				if(l->items[i] == *e)
				{
						int pos;
						pos = (l->size-1)-i;
						memmove(&(l->items[i]), &(l->items[i+1]), sizeof(ItemType)*pos);
						verificador	= true;
						l->size--;
						i--;
				}
		}
		return verificador == true ? 0 : 1;  
}

int getList(List* l, int index, ItemType* e)
{
		if((index >= l->size) || (index < 0))
		{
				return(1);
		}

		*e = l->items[index];
		return(0);
}

int setList(List* l, int index, ItemType* e)
{
		if ((index < 0) || (index >= l->size))
		{
				return(1);
		}

		l->items[index] = *e;
		return(0);
}

int indexOfList(List* l, ItemType* e)
{
		int i;
		for (i=0; i<l->size; i++)
		{
				if (l->items[i] == *e)
				{
						return(i);
				}
		}

		return(-1);
}
int containsList(List* l, ItemType* e)
{
		int i;
		for (i=0; i<l->size; i++)
		{
				if (l->items[i] == *e)
				{
						return(0);
				}
		}
		return(1);
}

int sizeList(List* l)
{
		return(l->size);
}

int isEmptyList(List* l)
{
		return ((l->size == 0) ? 0 : 1);
}

void printList(List* l)
{
		int i;
		for (i=0; i<l->size; i++)
		{
				printf("Posição %d: %d\n",i, l->items[i]); //alterar, pois varia de cada tipo do ItemType
		}
}
