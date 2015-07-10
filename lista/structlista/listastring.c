#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAP 5

typedef enum {TRUE = 1,
	FALSE = 0} boolean;

typedef struct {
	char** string;
	int quantidade;
	int capacidade;		
} lista_string;

/////////////////////////////////////////////////////////////
lista_string* Criar(int cap){

	lista_string* pl;

	pl = (lista_string*) malloc(sizeof(lista_string));
	pl->capacidade = cap;
	pl->quantidade = 0; //inicializando

	pl->string = (char**) malloc(cap*sizeof(char**));

	return(pl);
}
////////////////////////////////////////////////////////////
boolean Inserir_fim (lista_string* l, char* p)
{
	if (l->quantidade < l->capacidade)
	{
		int  strtam, pos, i;

		strtam = (strlen(p))+1; // tamanho da string + o \0
		pos = (l->quantidade); //posição que a string entra

		l->string[pos] = (char*) malloc(sizeof(char)*strtam);

		for (i=0; i<strlen(p); i++)
		{
			l->string[pos][i] = p[i];		
		}
		l->string[pos][i] = '\0';
		l->quantidade++;
		return(TRUE);
	}	
	else
	{
		return(FALSE);
	}
}
////////////////////////////////////////////////////////////
boolean Inserir_indice (lista_string* l, char* c, int pos)
{
	int rpt, i, tamanho;

	char** backup; 

	if (pos > l->quantidade)
	{
		return(FALSE);
	}

	rpt = (l->quantidade - pos); //quantidade de elementos que vão ser deslocados
	backup = (char**) malloc(sizeof(char*)*rpt+1);


	tamanho = strlen(c)+1;
	backup[0] = (char*) malloc(sizeof(char)*tamanho);
	strcpy(backup[0], c);



	for (i=0; i<rpt; i++) //criando um backup e dando um free na lista antiga

	{


		tamanho = strlen(l->string[pos])+1;
		backup[i+1] = (char*) malloc(sizeof(char)*tamanho);
		strcpy(backup[i+1], l->string[pos+i]);
		free(l->string[pos+i]);

	}

	tamanho = strlen(backup[0])+1;
	l->string[pos] = (char*) malloc(sizeof(char)*tamanho);
	strcpy(l->string[pos],backup[0]);

	for (i=1; i<=rpt; i++) //realocando o espaço e colocando as string no lugar certo
	{
		tamanho = strlen(backup[i])+1;
		l->string[pos+i] = (char*) malloc(sizeof(char)*tamanho);
		strcpy(l->string[pos+i], backup[i]);
	}
	l->quantidade++;

	return(TRUE);
}	
////////////////////////////////////////////////////////////
char* remover_posicao(lista_string* l, int pos)
{
	int rpt,i;

	char* aux;

	if((pos > l->quantidade) || (l->quantidade == 0))
	{
		printf("Erro, posição escolhida é maior que a quantidade.\n");
		return("ERRO");
	}
	free(l->string[pos]);
	l->quantidade--;
	rpt = l->quantidade - pos;


	for(i=1; i<=rpt; i++)
	{	
		aux = (char*) malloc((sizeof(char)*strlen(l->string[pos+i]))+1); //seta o tamanho de aux como o valor da prox string
		strcpy(aux, l->string[pos+i]); //copia para o aux 
		free(l->string[pos+i]); 
		l->string[pos+(i-1)] = (char*) malloc((sizeof(char)*strlen(aux))+1); //seta o novo tamanho da posição anterior
		strcpy(l->string[pos+(i-1)], aux);
		free(aux);
	}

	return("REMOVIDO");	
}
////////////////////////////////////////////////////////////
int remover_string(lista_string* l, char* s)
{
	int i, retorno=0;
	
	for (i=0; i<=l->quantidade; i++)
	{
		if (strcmp(s, l->string[i]) == 0)
		{
			remover_posicao(l, i);
			retorno=1;
		}
	}	
	return(retorno);
}
////////////////////////////////////////////////////////////
char* buscar_posicao(lista_string* l, int pos)
{

	if ((pos > l->quantidade) || (l->quantidade==0))	
	{
		return(NULL);
	}
	
	return(l->string[pos]);
}
////////////////////////////////////////////////////////////
int buscar_string(lista_string* l, char* s)
{
	int i;

	for (i=0; i<=l->quantidade; i++)
	{
		if (strcmp(l->string[i], s) == 0)
		{
			return(i);
		}
	}
	return(-10);
}

////////////////////////////////////////////////////////////
void Imprimir(lista_string* l)
{
	int qtd,i;

	qtd = l->quantidade;
	for (i=0; i<qtd; i++)
	{
		fputs(l->string[i], stdout);
		printf("\n");
	}	
}

int main() {

	char string[20] = "Daniel";

	lista_string* lista;

	lista = Criar(CAP); //cria a lista 

	Inserir_fim(lista, string);
	Inserir_fim(lista, string);
	Inserir_fim(lista, string);

	Inserir_indice(lista, "joao", 1);

	Imprimir(lista);

	remover_posicao(lista, 0);
printf("\n");
	Imprimir(lista);

	remover_string(lista, "Daniel");
printf("\n");	
	Imprimir(lista);

	if (buscar_posicao(lista,0) == NULL)
	{
		printf("Erro master, a posição digitada não existe\n");
	}
	else
	{
		printf("String buscada %s\n", buscar_posicao(lista,0));
	}

	if (buscar_string(lista, "joao") == -10)
	{
		printf("A palavra digitada não existe na lista\n");
	}
	else
	{
		printf("A palavra digitada se encontra na posição: %i", buscar_string(lista,"joao"));
	}
	return(0);
}
