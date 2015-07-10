#ifndef __INCIDENCIA__
#define __INCIDENCIA__
#include <stdio.h>
#include <stdlib.h>
typedef enum boolean{
	false = 0,
	true = 1}
	bool;

	typedef struct node{
			int data;
			struct node * next;
	}Node;

	typedef struct{
		Node** vetor;
		int n;
	}Lista_incidencia;

Lista_incidencia* newLista(int n);
int addAresta(Lista_incidencia* l, int origem, int destino);
bool removeAresta(Lista_incidencia* l, int origem, int destino);
bool isAresta(Lista_incidencia* l, int origem, int destino);
void printListaIncidencia(Lista_incidencia* l);	
int getMatriz(Lista_incidencia* l, int*** endMatriz);
Node* newNode(int valor);

#endif
