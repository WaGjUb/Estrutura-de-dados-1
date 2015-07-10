#include "incidenciabib.h"

Lista_incidencia* newLista(int n)
{
		int i;
		Node **pno; //ponteiro de ponteiro de nó
		Lista_incidencia* l;
		l = (Lista_incidencia*) malloc(sizeof(Lista_incidencia));
		while(n < 0)
		{
				printf("Digite um ""n"" válido: ");
				scanf("%d", &n);
		}
		l->n = n;
		pno = (Node**) malloc(sizeof(Node*)*n);

		l->vetor = pno;

		/*inicializando o vetor;*/
		for (i=0; i<n; i++)
		{
				l->vetor[i] = NULL;
		}
		return(l);
}

int addAresta(Lista_incidencia* l, int origem, int destino)
{
		/*verifica se os valores passados como parametros são válidos*/
		if ((origem > l->n) || (origem < 0) || (destino > l->n) || (destino < 0) || (origem==destino))
		{
				return(false);
		}
		
		/*verifica se já existe a conexão, se já ele retorna -1*/
		if (isAresta(l, origem, destino))
		{
				return(-1);
		}
		
		/*faz a conexão da origem com destino*/
		Node* aux;
		aux = (Node*) malloc(sizeof(Node));
		aux->data = destino;
		aux->next = l->vetor[origem];		
		l->vetor[origem] = aux;

		/*faz a conexão do destino com a origem*/
		Node* aux2;
		aux2 = (Node*) malloc(sizeof(Node));
		aux2->data = origem;
		aux2->next = l->vetor[destino];
		l->vetor[destino] = aux2;
		return(true);
}

bool removeAresta(Lista_incidencia* l, int origem, int destino)
{
		/*verifica se os valores digitados são válidos*/
		if ((origem >= l->n) || (origem < 0) || (destino >= l->n) || (destino < 0) || (origem==destino))
		{
				return(false);
		}
		
		/*verifica se há conexão origem - destino e destino origem*/
		if (/*(isAresta(l, origem, destino)) &&*/ (isAresta(l, destino, origem)))
		{
				
				Node *redutor=NULL, *redutorprev=NULL;  
				redutor = l->vetor[origem];

				/*redutor aponta para o nó que deve ser removido */
				/*redutorprev aponta para o enelemento anterior*/
				while (redutor->data != destino)
				{
					redutorprev = redutor;
					redutor = redutor->next;
				}
				
				/*verifica se o nó escolhido é o primeiro do vetor*/
				if (redutorprev != NULL)
				{
						redutorprev->next = redutor->next;
						redutor->next = NULL;
						free(redutor);
				}
				else
				{
						l->vetor[origem] = redutor->next;
						redutor->next = NULL;
						free(redutor);
				}

				/*removida a conexão origem destino*/


				redutorprev = NULL;
				redutor = l->vetor[destino]; 

				/*redutor aponta para o nó que deve ser removido */
				/*redutorprev aponta para o enelemento anterior*/
				while (redutor->data != origem)
				{
					redutorprev = redutor;
					redutor = redutor->next;
				}
				
				/*verifica se o nó escolhido é o primeiro do vetor*/
				if (redutorprev != NULL)
				{
						redutorprev->next = redutor->next;
						redutor->next = NULL;
						free(redutor);
				}
				else
				{
						l->vetor[destino] = redutor->next;
						redutor->next = NULL;
						free(redutor);
				}
				

				/*removida a conexão destino - origem*/

		return(true); //um passo para o sucesso!
		}
		else
		{
		return(false); // se não tinha comunicação retorna falso
		}	

}

bool isAresta(Lista_incidencia* l, int origem, int destino)
{

		Node* redutor;

		redutor = l->vetor[origem];
		while (redutor != NULL)
		{
				if (redutor->data == destino)
				{
						return(true);
				}
				redutor = redutor->next;
		}		
		return(false);
}

void printListaIncidencia(Lista_incidencia* l) 
{
		int i;
		Node* redutor;

		
		for (i=0; i<l->n; i++)
		{
				redutor = l->vetor[i];
				printf("Nó %d: \n",i);
						while (redutor != NULL)
						{
								printf("%d\n", redutor->data);
								redutor = redutor->next;
						}
		}
}

int getMatriz(Lista_incidencia* l, int*** endMatriz)
{
		int i, j;
		int **mat;

		/*cria o vetor de ponteiros*/
		mat = (int**) malloc(sizeof(int*)*l->n);


		/*cria as posições verticais*/
		for (i=0; i<(l->n); i++)
		{
			mat[i] = (int*) malloc(sizeof(int)*l->n);
		}

	 /*preenche a matriz*/
		for (i=0; i<(l->n); i++)  
		{
				for (j=0; j<(l->n); j++)
				{
						if (isAresta(l, i, j))
						{
								mat[i][j] = 1;
						}
						else
						{
								mat[i][j] = 0;
						}
				}
		}
 
		*endMatriz = mat;
		return(1);
}


Node* newNode(int valor)
{
	Node* new;
  new = (Node*) malloc(sizeof(int));
	new->data = valor;
	new->next = NULL;
	return(new);
}
