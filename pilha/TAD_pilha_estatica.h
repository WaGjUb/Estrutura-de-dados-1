/*! @file static_stack.h
 *
 * @brief Pilha com aloca��o est�tica de mem�ria.
 *
 * <p>Este arquivo tem como �nico e exclusivo objetivo auxiliar o ensino
 * dos conte�dos da disciplina de Algoritmos e Estrutura de Dados 1 do
 * curso de Ci�ncia da Computa��o da UTFPR - C�mpus Campo Mour�o.
 *
 * <p>Author: Rafael Liberato</p>
 *
 * <b>history</b>
 * <p>2013-06-04 initial version</p>
 */

#ifndef STATIC_STACK_H_INCLUDED
#define STATIC_STACK_H_INCLUDED

/** <code>ItemType</code>: Defini��o do tipo de dado a ser manipulado na Pilha Est�tica */
#define ItemType int
/** <code>STACK_LENGTH</code>: Tamanho padr�o do array utilizado na Pilha */
#define STACK_LENGTH 10

/**
 * Estrutura usada para representar e armazenar a PILHA est�tica.
 */
typedef struct{
        int top;            /**< Atributo que armazena a primeira posi��o vazia do array  */
        int length;         /**< Tamanho do array utilizado para armazenar os elementos da pilha */
        ItemType *items;    /**< Array para armazenamento dos elementos da lista */
}Stack;

typedef enum {false, true} Boolean;

/**
 * Cria a pilha EST�TICA e devolve seu endere�o.
 * @return o endere�o da pilha EST�TICA criada.
 */
Stack* createStack();

/**
 * Inicializa a pilha <code>s</code>.
 * @param s Ponteiro para a Pilha em que o elemento ser� inserido.
 */
void initializeStack(Stack* stack);

/**
 * Insere o elemento <code>e</code> no topo da pilha <code>s</code>.
 * @param s Ponteiro para a Pilha em que o elemento ser� inserido.
 * @param e Elemento a ser inserido na pilha.
 * @return <code>true</code> se a inser��o foi realizada com sucesso e <code>false</code> caso contr�rio
 */
Boolean push(Stack* stack, ItemType e);

/**
 * Remove o elemento do topo da pilha <code>s</code>. A fun��o devolve <code>true</code> se a remo��o
 * foi realizada com sucesso e armazena o elemento removido no endere�o contido no par�metro
 * <code>removed</code>. Caso contr�rio devolve <code>false</code>
 * @param stack         Ponteiro para a Pilha em que o elemento ser� removido.
 * @param *removed  Ponteiro para a regi�o da mem�ria utilizada para armazenar o elemento removido.
 * @return <code>true</code> se a remo��o foi realizada com sucesso e <code>false</code> caso contr�rio.
 */
Boolean pop(Stack* stack, ItemType* removed);

/**
 * Devolve o elemento do topo da pilha <code>s</code>.
 * O elemento � armazenado no endere�o contido no par�metro <code>returned</code> e a fun��o devolve
 * <code>true</code>. Caso contr�rio a fun��o devolve <code>false</code>.
 * @param stack         Ponteiro para a Pilha em que o elemento ser� procurado.
 * @param *returned     Ponteiro para a regi�o da mem�ria utilizada para armazenar o elemento da posi��o <code>index</code>.
 * @return <code>true</code> se a posi��o foi encontrada e o elemento foi armazenado no endere�o <code>returned</code>
 *         e <code>false</code> caso contr�rio.
 */
Boolean top(Stack* stack, ItemType* returned);

/**
 * Imprime na sa�da padr�o os elementos da pilha.
 * @param s         Ponteiro para a pilha.
 */
void printStack(Stack* stack);

/**
 * Verifica se o elemento <code>e</code> est� contido na pilha <code>s</code>.
 * @param s         Ponteiro para a Pilha em que o elemento ser� procurado.
 * @param e         Endere�o do Elemento a ser procurado.
 * @return <code>true</code> se o elemento est� contido ou <code>false</code> caso contr�rio.
 */
Boolean containsStack(Stack* stack, ItemType* e);

/**
 * Devolve o n�mero de elementos contidos na pilha <code>s</code>.
 * @param s         Ponteiro para a Pilha em que o elemento ser� substituido.
 * @return N�mero de elementos da lista.
 */
int sizeStack(Stack* stack);

/**
 * Verifica se a pilha <code>s</code> est� ou n�o vazia.
 * @param s         Ponteiro para a pilha em que o elemento ser� substituido.
 * @return <code>true</code> se a pilha <code>s</code> estiver vazia ou <code>false</code> caso contr�rio.
 */
Boolean isEmptyStack(Stack* stack);


#endif // STATIC_STACK_H_INCLUDED
