#ifndef LISTA_INCIDENCIA_VITORIO
#define LISTA_INCIDENCIA_VITORIO

#define Lista Lista_Incidencia

typedef struct node{
	int data;
	struct node* next;
}Node;

typedef struct{
	Node** vetor;
	int n;
}Lista_Incidencia;

typedef enum { false, true }bool;

//Cria uma lista de incidencia com N elementos
Lista* newListaIncidencia( int n );

//Cria uma nova aresta indicando a relacao entre dois
//elementos
bool addAresta( Lista* l, int origem, int destino );

//Retorna MENOR QUE ZERO se as duas listas nao contem o elemento a ser removido
//Retorna ZERO se uma das listas nao contem o elemento a ser removido
//Retorna UM se o elemento foi removido conforme o esperado
int removeAresta(Lista* l, int origem, int destino );

//Remove a relacao que sai da origem e vai para o destino
//Remove ORIGEM->DESTINO
bool removeArestaUniderecional(Lista* l, int origem, int destino );

//Verifica a existencia de uma aresta entre os elementos
bool isAresta(Lista* l, int origem, int destino );

//Verefica a existencia de uma aresta que sai da origem e vai apra o destino
//Verifica ORIGEM->DESTINO
bool isArestaUnidirecional( Lista* l, int origem, int destino );

//Imprime a Lista
void printListaIncidencia( Lista* l );

//Cria uma matriz que indica as relacoes entre os elementos
//Sera salvo em endMatriz o endereco da matriz criada
int getMatriz(Lista* l, int*** endMatriz );

//Cria um novo node
Node* newNode( int valor );
#endif
