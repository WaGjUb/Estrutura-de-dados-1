/*adicionar, remover  */
/*consultar */
/*exibir todo*/

#ifndef __Hashbib__
#define __Hashbib__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef enum 
{
	false = 0, true
} bool;

typedef struct{
	int RA;
	char nome[40];
	char curso[40];
} Aluno;

typedef struct node{
	Aluno data;
	struct node* next;
} Node;

typedef struct{
	Node **tabela;
	int tamvetor;
	int qtde_elementos;
	int capacidade;
} TabelaHash;

TabelaHash* Create(int capacidade);
bool inserir(TabelaHash* t, Aluno a);
Aluno* buscar(TabelaHash* t, Aluno a);
Aluno* remover(TabelaHash* t, Aluno a);
void print(TabelaHash *t);
int Hash(Aluno A, int tam_vetor);
int ArraySize(int cap);
#endif
