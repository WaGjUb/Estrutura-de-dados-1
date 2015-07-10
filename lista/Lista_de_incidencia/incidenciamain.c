#include "incidenciabib.h"

int main(){
	
	int **mat, i, j;
	Lista_incidencia* lista;

	lista = newLista(5);
	addAresta(lista, 0, 1);
	addAresta(lista, 0, 3);
	addAresta(lista, 0, 4);
	addAresta(lista, 1, 0);
	addAresta(lista, 1, 2);
	addAresta(lista, 1, 3);
	addAresta(lista, 1, 4);
	addAresta(lista, 2, 1);
	addAresta(lista, 3, 1);
	addAresta(lista, 4, 1);
	if (isAresta(lista, 4,0))
	{
		printf("é aresta\n");
	}
	else
	{
		printf("Não é aresta\n");
	}

	if (removeAresta(lista, 0, 4))
	{
		printf("removido\n");
	}
	else
	{
		printf("Não foi removido\n");
	}
	printListaIncidencia(lista);



	
	getMatriz(lista,&mat);

	/*imprime a matriz*/
//	if(getMatriz(lista, &mat))
	{
		for (i=0; i<lista->n; i++)
		{
			for (j=0; j<lista->n; j++)
			{	
				printf("%d ",mat[i][j]);	
			}
			printf("\n");
		}   
	}

	return(0);
}
