#ifndef __LISTA__
#define __LISTA__

	Typedef struct node
	{
		Itemtype data;	
		struct node* Next;
		struct node* Prev;
	}Node;

	typedef struct
	{
		Node* first;
		Node* last;	
		int size; 
	} List;

	CreateList
	InserirPos
	Append
	RemovePos
	RemoveVal
	SearchVal
	SearchPos
	

#endif
