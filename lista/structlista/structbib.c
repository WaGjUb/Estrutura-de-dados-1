#include <stdio.h>
#include "structbib.h"

        typedef struct  
        {   
                char** string;
                int quantidade;
                int capacidade;
        } lista_string;


lista_string* Criar(int cap){

	typedef struct 
	{
		char** string;
		int quantidade;
		int capacidade;
	} lista;

	lista* pl;

	pl = (lista*) malloc(sizeof(lista));
	pl->capacidade = cap;

	pl->string = (char**) malloc(cap*sizeof(char**));

	return(pl);
}
