#include "hashbib.h"

int main()
{

 system("clear");

 int selec, tamanho;
 TabelaHash* t;

 printf("Digite a capacidade da tabela: ");
 scanf("%d", &tamanho);
 t = Create(tamanho);
 system("clear");

 do 
 {
  printf("|||||||||||||||||||||||||||||||||||||||||||||\n");
  printf("|||               TABELA HASH             |||\n");
  printf("|||Selecione uma opção:                   |||\n");
  printf("|||0- Sair                                |||\n");
  printf("|||1- Inserir                             |||\n");
  printf("|||2- Buscar                              |||\n");
  printf("|||3- Remover                             |||\n");
  printf("|||4- Imprimir                            |||\n");
  printf("|||||||||||||||||||||||||||||||||||||||||||||\n");
  printf("opção: ");
  scanf("%d", &selec);

  system("clear");

  switch (selec)
  {

   case 0:
	{
	 printf("tchau!\n");
	 return(0);
	}

   case 1: 
	{
	 Aluno a;

	 printf("Digite o RA: ");
	 scanf("%d", &a.RA);
	 setbuf(stdin,NULL);

	 printf("Digite o Nome: ");
	 scanf("%[^\n]", a.nome);
	 setbuf(stdin,NULL);

	 printf("Digite o curso: ");
	 scanf("%[^\n]", a.curso);
	 setbuf(stdin,NULL);

	 if(inserir(t, a))
	 {
	  printf("Aluno inserido.\n");
	 }
	 else
	 {
	  printf("Aluno não inserido, capacidade máxima atingida.\n");
	 }

	 break;
	}

   case 2: 
	{
	 Aluno a, *pointer;

	 printf("Digite o RA: ");
	 scanf("%d", &a.RA);
	 setbuf(stdin,NULL);

	 printf("Digite o Nome: ");
	 scanf("%[^\n]", a.nome);
	 setbuf(stdin,NULL);

	 printf("Digite o curso: ");
	 scanf("%[^\n]", a.curso);
	 setbuf(stdin,NULL);

	 pointer = buscar(t,a);

	 if(pointer==NULL)
	 {
	  printf("O aluno não está na tabela.\n");
	 }
	 else
	 {
	  printf("O aluno está na tabela.\n");
	  free(pointer);
	 }

	 break;
	}

   case 3: 
	{
	 Aluno a, *pointer;

	 printf("Digite o RA: ");
	 scanf("%d", &a.RA);
	 setbuf(stdin,NULL);

	 printf("Digite o Nome: ");
	 scanf("%[^\n]", a.nome);
	 setbuf(stdin,NULL);

	 printf("Digite o curso: ");
	 scanf("%[^\n]", a.curso);
	 setbuf(stdin,NULL);

	 pointer = remover(t,a);

	 if(pointer == NULL)
	 {
	  printf("O aluno não existe na tabela.\n");
	 }
	 else
	 {
	  printf("O aluno foi removido.\n");
	 }

	 break;
	}

   case 4:
	  {
	   print(t);
	   break;
	  }

default:
	  {
	   printf("Opção inválida\n");
	   break;
	  }
  }

 }while (selec!=0);

 return(0);	
}
/*TabelaHash* Create(int capacidade);*/
/*bool inserir(TabelaHash* t, Aluno a);*/
/*Aluno* buscar(TabelaHash* t, Aluno a);*/
/*Aluno* remover(TabelaHash* t, int fsfsd);*/
/*void print(TabelaHash *t);*/
/*int Hash(Aluno A, int tam_vetor);*/
/*int ArraySize(int cap);*/
