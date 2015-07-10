#ifndef __dinamica_bib__
#define __dinamica_bib__
#define ItemType int
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
	ItemType data;
	struct node* prev;
	struct node* next;
}Node;

typedef struct{
	int size;
	Node* first;
	Node* last;
}List;

typedef enum{
		false=0, true
}bool;

List *createList();
void initializeList(List *l);
int addLastList(List *l, ItemType e);
int addList(List* l, ItemType e, int index);
int removeList(List* l, int index, ItemType* e);
int removeElementList(List* l, ItemType* e);
int getList(List* l, int index, ItemType* e);
int setList(List* l, int index, ItemType* e);
int indexOfList(List* l, ItemType* e);
int containsList(List* l, ItemType* e);
int sizeList(List* l);
int isEmptyList(List* l);
void printList(List* l);

#endif
