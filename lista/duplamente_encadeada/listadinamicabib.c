#include "listadinamicabib.h"

List *createList()
{
		List* l;
		l = (List*) malloc(sizeof(List));
		initializeList(l);
		return (l);
}

void initializeList(List *l)
{

		l->size = 0;
		l->first = NULL;
		l->last = NULL;	
}

int addLastList(List *l, ItemType e)
{

		Node* aux; 
		aux = (Node*) malloc(sizeof(Node));
		aux->data = e;
		aux->next = NULL;

		if (l->size == 0)
		{
			aux->prev = NULL;
		 	l->first = aux;
			l->last = aux;
		}
		else
		{
			aux->prev = l->last;
			l->last->next = aux;
			l->last = aux;
		}
		l->size++;

		return(0);
}
int addList(List* l, ItemType e, int index) //-1 se o index digitado é menor que 0, 1 se digitar um valor maior que o tamanho do items e 0 se o dado foi inserido.
{


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


		Node* aux;
		aux = (Node*) malloc(sizeof(Node));
		int sizecp;

		sizecp = l->size; //indica quantos nós serão andados
		aux->data = e;
		
		if (index > (sizecp/2)) //escolhe o sentido que será andado
		{
			sizecp--;
			int i;
			Node* redutor;

			redutor = l->last;
			sizecp -= index;
	
			for (i=0; i<sizecp; i++) //anda com o ponteiro
			{
				redutor = redutor->prev;
			}
			aux->next = redutor;
			aux->prev = redutor->prev;
			redutor->prev->next = aux;
			redutor->prev = aux;
		}
		else
		{
			int i;
			Node* redutor;

			redutor = l->first;
			
			for(i=0; i<index; i++)
			{
				redutor = redutor->next;
			}
			aux->next = redutor;
			aux->prev = redutor->prev;
			if(redutor->prev != NULL) //se não for o primeiro elemento
			{
				redutor->prev->next = aux;
			}
			else
			{
				l->first = aux;
			}

			redutor->prev = aux;
		}
		
		l->size++;
		return(0);	
}

int removeList(List* l, int index, ItemType* e)
{

		if ((index > l->size) || (index < 0))
		{
				return(1);
		}

		int sizecp;

		sizecp = l->size; //indica quantos nós serão andados
		
		if (index > (sizecp/2)) //escolhe o sentido que será andado
		{
			sizecp--; //tira 1 do size, já que queremos referir a posição
			int i;
			Node* redutor;

			redutor = l->last;
			sizecp -= index;
	
			for (i=0; i<sizecp; i++) //anda com o ponteiro
			{
				redutor = redutor->prev;
			}
			redutor->prev->next = redutor->next;

			if (redutor->next == NULL) //verifica se é o ultimo elemento, se for eledireciona o last
			{
				l->last = redutor->prev;
			}
			else
			{
			redutor->next->prev = redutor->prev;
			}
			redutor->next = NULL;
			redutor->prev = NULL;
		*e = redutor->data;
		free(redutor);
		}
		else
		{
			int i;
			Node* redutor;

			redutor = l->first;
			
			for(i=0; i<index; i++)
			{
				redutor = redutor->next;
			}
			if (redutor->prev == NULL)
			{
				l->first = redutor->next;
			}
			else
			{
			redutor->prev->next = redutor->next;
			}
			redutor->next->prev = redutor->prev;

			redutor->next = NULL;
			redutor->prev = NULL;
		*e = redutor->data;
		free(redutor);
		}



		l->size--;
		return(0);
}

int removeElementList(List* l, ItemType* e) //retorna 1 se todos os elementos dados foram removidos e 0 se nenhum elemento foi encontrado
{

		bool verificador = false;
		Node* redutor;

		redutor = l->first;

		while (redutor != NULL)
		{
				if(redutor->data == *e)
				{
						Node* backup;

						if ((redutor->prev != NULL) && (redutor->next != NULL))// se for um nó do meio
						{
						redutor->prev->next = redutor->next;
						redutor->next->prev = redutor->prev;
						}

						if (redutor->prev == NULL)//se for o primeiro nó
						{
							l->first = redutor->next;
							redutor->next->prev = redutor->prev;
						}

						if (redutor->next == NULL)//se for o ultimo elemento
						{
							l->last = redutor->prev;
							redutor->prev->next = redutor->next;
						}
						
						backup = redutor->next;
						redutor->next = NULL;
						redutor->prev = NULL;
						free(redutor);
						redutor = backup;
						verificador	= true;
						l->size--;
				}
				else
				{
					redutor = redutor->next;
				}
		}
		return verificador == true ? 0 : 1;  
}//////NVSLZD//////

int getList(List* l, int index, ItemType* e)
{
		if((index >= l->size) || (index < 0))
		{
				return(1);
		}


		int sizecp;

		sizecp = l->size; //indica quantos nós serão andados
		
		if (index > (sizecp/2)) //escolhe o sentido que será andado
		{
			sizecp--;
			int i;
			Node* redutor;

			redutor = l->last;
			sizecp -= index;
	
			for (i=0; i<sizecp; i++) //anda com o ponteiro
			{
				redutor = redutor->prev;
			}
			*e = redutor->data;
		}
		else
		{
			int i;
			Node* redutor;

			redutor = l->first;
			
			for(i=0; i<index; i++)
			{
				redutor = redutor->next;
			}
			*e = redutor->data;
		}
		
		return(0);
}

int setList(List* l, int index, ItemType* e)
{
		if ((index < 0) || (index >= l->size))
		{
				return(1);
		}

		int sizecp;

		sizecp = l->size; //indica quantos nós serão andados
		
		if (index > (sizecp/2)) //escolhe o sentido que será andado
		{	
			sizecp--;
			int i;
			Node* redutor;

			redutor = l->last;
			sizecp -= index;
	
			for (i=0; i<sizecp; i++) //anda com o ponteiro
			{
				redutor = redutor->prev;
			}
			redutor->data = *e;
		}
		else
		{
			int i;
			Node* redutor;

			redutor = l->first;
			
			for(i=0; i<index; i++)
			{
				redutor = redutor->next;
			}
			redutor->data = *e;
		}

		return(0);
}

int indexOfList(List* l, ItemType* e)
{
		Node* redutor;
		int indice=0;

		redutor = l->first;

		while (redutor != NULL)
		{
			if (redutor->data == *e)
			{
				return(indice);
			}
			redutor = redutor->next;
			indice++;
		}

		return(-1);
}
int containsList(List* l, ItemType* e)
{
		Node* redutor;

		redutor = l->first;

		while (redutor != NULL)
		{
			if (redutor->data == *e)
			{
				return(0);
			}
			redutor = redutor->next;
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
		Node* redutor;
		int cont=0;

		redutor = l->first;

		while (redutor != NULL)
		{
			printf("posição %d: %d\n",cont++, redutor->data); //alterar, pois varia de cada tipo do itemtype
			redutor = redutor->next;
		}
}
