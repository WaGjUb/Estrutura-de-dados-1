/*! @file static_stack.h
 *
 * @brief Pilha com alocação estática de memória.
 *
 * <p>Este arquivo tem como único e exclusivo objetivo auxiliar o ensino
 * dos conteúdos da disciplina de Algoritmos e Estrutura de Dados 1 do
 * curso de Ciência da Computação da UTFPR - Câmpus Campo Mourão.
 *
 * <p>Author: Rafael Liberato</p>
 *
 * <b>history</b>
 * <p>2013-06-04 initial version</p>
 */

#ifndef STATIC_STACK_H_INCLUDED
#define STATIC_STACK_H_INCLUDED

/** <code>ItemType</code>: Definição do tipo de dado a ser manipulado na Pilha Estática */
#define ItemType int
/** <code>STACK_LENGTH</code>: Tamanho padrão do array utilizado na Pilha */
#define STACK_LENGTH 10

/**
 * Estrutura usada para representar e armazenar a PILHA estática.
 */
typedef struct{
        int top;            /**< Atributo que armazena a primeira posição vazia do array  */
        int length;         /**< Tamanho do array utilizado para armazenar os elementos da pilha */
        ItemType *items;    /**< Array para armazenamento dos elementos da lista */
}Stack;

typedef enum {false, true} Boolean;

/**
 * Cria a pilha ESTÁTICA e devolve seu endereço.
 * @return o endereço da pilha ESTÁTICA criada.
 */
Stack* createStack();

/**
 * Inicializa a pilha <code>s</code>.
 * @param s Ponteiro para a Pilha em que o elemento será inserido.
 */
void initializeStack(Stack* stack);

/**
 * Insere o elemento <code>e</code> no topo da pilha <code>s</code>.
 * @param s Ponteiro para a Pilha em que o elemento será inserido.
 * @param e Elemento a ser inserido na pilha.
 * @return <code>true</code> se a inserção foi realizada com sucesso e <code>false</code> caso contrário
 */
Boolean push(Stack* stack, ItemType e);

/**
 * Remove o elemento do topo da pilha <code>s</code>. A função devolve <code>true</code> se a remoção
 * foi realizada com sucesso e armazena o elemento removido no endereço contido no parâmetro
 * <code>removed</code>. Caso contrário devolve <code>false</code>
 * @param stack         Ponteiro para a Pilha em que o elemento será removido.
 * @param *removed  Ponteiro para a região da memória utilizada para armazenar o elemento removido.
 * @return <code>true</code> se a remoção foi realizada com sucesso e <code>false</code> caso contrário.
 */
Boolean pop(Stack* stack, ItemType* removed);

/**
 * Devolve o elemento do topo da pilha <code>s</code>.
 * O elemento é armazenado no endereço contido no parâmetro <code>returned</code> e a função devolve
 * <code>true</code>. Caso contrário a função devolve <code>false</code>.
 * @param stack         Ponteiro para a Pilha em que o elemento será procurado.
 * @param *returned     Ponteiro para a região da memória utilizada para armazenar o elemento da posição <code>index</code>.
 * @return <code>true</code> se a posição foi encontrada e o elemento foi armazenado no endereço <code>returned</code>
 *         e <code>false</code> caso contrário.
 */
Boolean top(Stack* stack, ItemType* returned);

/**
 * Imprime na saída padrão os elementos da pilha.
 * @param s         Ponteiro para a pilha.
 */
void printStack(Stack* stack);

/**
 * Verifica se o elemento <code>e</code> está contido na pilha <code>s</code>.
 * @param s         Ponteiro para a Pilha em que o elemento será procurado.
 * @param e         Endereço do Elemento a ser procurado.
 * @return <code>true</code> se o elemento está contido ou <code>false</code> caso contrário.
 */
Boolean containsStack(Stack* stack, ItemType* e);

/**
 * Devolve o número de elementos contidos na pilha <code>s</code>.
 * @param s         Ponteiro para a Pilha em que o elemento será substituido.
 * @return Número de elementos da lista.
 */
int sizeStack(Stack* stack);

/**
 * Verifica se a pilha <code>s</code> está ou não vazia.
 * @param s         Ponteiro para a pilha em que o elemento será substituido.
 * @return <code>true</code> se a pilha <code>s</code> estiver vazia ou <code>false</code> caso contrário.
 */
Boolean isEmptyStack(Stack* stack);


#endif // STATIC_STACK_H_INCLUDED
