#ifndef __stack_dinamica__
#define __stack_dinamica__
#define ItemType int

typedef struct node{
	ItemType data;
	struct node* next;
}Node;

typedef struct {
	Node *top;
	int size;	
}Stack;

Stack* createStack();
int push(Stack* stack, ItemType e);
void initializeStack(Stack * stack);
int pop(Stack* stack, ItemType* e);
int peek(Stack* stack, ItemType* e);
int contains(Stack* stack, ItemType *e);
int sizeStack(Stack*stack);
int isEmptyStack(Stack* stack);
void printStack(Stack* stack);

#endif
