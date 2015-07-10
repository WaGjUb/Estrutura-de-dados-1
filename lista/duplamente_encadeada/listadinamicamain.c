#include "listadinamicabib.h"

int main(){


		List* l;
		l = createList();
		int selec;

		system("clear");
		do
		{		
				printf("|||||||||||||||||||||||||||||||||||||||||||||\n");
				printf("|||                                       |||\n");
				printf("|||Selecione uma opção:                   |||\n");
				printf("|||0 - Sair                               |||\n");
				printf("|||1- Inserir no final                    |||\n");
				printf("|||2- Inserir por posição                 |||\n");
				printf("|||3- Remover por posição                 |||\n");
				printf("|||4- Remover por elemento                |||\n");
				printf("|||5- Obter elemento por posição          |||\n");
				printf("|||6- Alterar valor por posição           |||\n");
				printf("|||7- Obter indíce do elemento            |||\n");
				printf("|||8- Verificar se elemento está na lista |||\n");
				printf("|||9- Ver tamanho da lista                |||\n");
				printf("|||10- Verificar se lista está vazia      |||\n");
				printf("|||11- Imprimir lista                     |||\n");
				printf("|||                                       |||\n");
				printf("|||||||||||||||||||||||||||||||||||||||||||||\n");
				printf("opção: ");
				scanf("%d", &selec);
				
				system("clear");
				switch (selec)
				{
					 ItemType elemento;
					 
					 	case 0:
							{
								printf("tchau!\n");
								return(0);
							}
						case 1: 
						{
								printf("Digite o elemento: ");
								scanf("%d", &elemento);
								if (addLastList(l, elemento))
								{
										printf("O elemento não foi inserido.\nA lista está cheia.\n");
								}	
								else
								{
										printf("O elemento foi inserido.\n");
								}
								break;
						}

						case 2:

						{
								int pos, verif;
								printf("Digite o elemento e a posição: ");
								scanf("%d %d", &elemento, &pos);
								verif = addList(l, elemento, pos);
								if (verif == 0)
								{
										printf("O valor foi inserido.\n");
								}
								else
								{
										if (verif == 3)
										{
												printf("A lista está cheia.\n");
										}
										else
										{
												printf("O index digitado não é válido.\n");
										}
								}
								break;
						}

						case 3:
						{
								int pos;
								printf("Digite a posição: ");
								scanf("%d", &pos);
								if (removeList(l, pos, &elemento))
								{
										printf("Index inválido.\n");
								}
								else
								{
										printf("Valor removido.\n");
								}
								break;
						}
						case 4:
						{
								printf("Digite o valor: ");
								scanf("%d", &elemento);
								if (removeElementList(l, &elemento))
								{
										printf("O valor não foi encontrado\n");
								}						
								else
								{
										printf("O valor digitado foi removido\n");
								}
								break;
						}

						case 5:
						{
								int pos;
								printf("Digite a posição: ");
								scanf("%d", &pos);

								if (getList(l, pos, &elemento))
								{
										printf("A posição digitada não é válida\n");	
								}				
								else
								{
										printf("Valor: %d\n", elemento);
								}
								break;
						}

						case 6:
						{

								int pos;
								printf("Digite a posição e o novo elemento: ");
								scanf("%d %d", &pos, &elemento);

								if (setList(l, pos, &elemento))
								{
										printf("A posição digitada não existe\n");
								}	
								else
								{
										printf("O valor foi alterado.\nValor anterior: %d\n", elemento);
								}
								break;	 
						}

						case 7:
						{
								printf("Digite o valor: ");
								scanf("%d", &elemento);
								int pos;
								pos = indexOfList(l, &elemento);
								if (pos == -1)
								{
										printf("Elemento não encontrado\n");
								}
								else
								{
										printf("Posição: %d\n", pos);
								}
								break;
						}

						case 8:
						{
								printf("Digite o elemento: ");
								scanf("%d", &elemento);

								if (containsList(l, &elemento))
								{
										printf("O elemento não está na lista.\n");
								}
								else
								{
										printf("O elemento está na lista.\n");
								}
								break;
						}

						case 9:
						{
								printf("Tamanho da lista: %d\n", sizeList(l));
								break;
						}

						case 10:
						{
								if (isEmptyList(l)==0)
								{
										printf("A lista está vazia.\n");
								}
								else
								{
										printf("A lista não está vazia.\n");
								}
								break;
						}

						case 11:
						{

								printList(l);

								break;
						}

						default:
						{	
							printf("Opção digitada inválida!\n");
						}
				}
				printf("\n\n");
		} while (selec != 0);


		/*List *createList();*/
		/*void initializeList(List *l);*/
		/*int addLastList(List *l, ItemType e);*/
		/*int addList(List* l, ItemType e, int index);*/
		/*int removeList(List* l, int index, ItemType *e);*/
		/*int removeElementList(List* l, ItemType* e);*/
		/*int getList(List* l, int index, ItemType* e);*/
		/*int setList(List* l, int index, ItemType* e);*/
		/*int indexOfList(List* l, ItemType* e);*/
		/*int containsList(List* l, ItemType *e);*/
		/*int sizeList(List* l);*/
		/*int isEmptyList(List* l);*/
		/*void printList(List* l);*/

		return(0);
}
