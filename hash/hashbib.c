#include "hashbib.h"
#define TAM 10  //um valor de 5-10 por posição

int ArraySize(int cap)
{

		int k, i;  /*decide o limite de iterações feitas para verificar se é primo*/ 
		bool primo;

		cap /= TAM;

		if (!(cap % 2)) /*se multiplo de 2*/ 
		{
				cap--;
		}

		while (cap != 1)
		{
				primo = true;
				k = sqrt(cap);

				for (i=3; i<=k; i+=2)	 /*verifica se é primo*/ 
				{
						if ((cap % i) == 0)
						{
								primo = false;
						}
				}

				if (primo == true)
				{
						return(cap);
				}
				cap -= 2;
		}
		return(cap);
}

TabelaHash* Create(int capacidade)
{
		while (capacidade < TAM)
		{
				printf("Capacidade digitada é menor que o tamanho minimo de %d.\nDigite uma capacidade maior ou igual ao tamanho minimo: : ", TAM);
				scanf("%d", &capacidade);
		}

		TabelaHash* t;
		Node** array;
		int tamanho, i;

		tamanho = ArraySize(capacidade);
	
		t = (TabelaHash*) malloc(sizeof(TabelaHash)); 
		array = (Node**) malloc(sizeof(Node*)*tamanho);

		//inicializa o vetor
		for (i=0; i<tamanho; i++)
		{
			array[i] = NULL;
		}
		
		t->tabela = array;
		t->tamvetor = tamanho;
		t->capacidade = capacidade;
		t->qtde_elementos = 0;
		
		return(t);			
}

int Hash(Aluno a, int tam_vetor)
{

	int hash;
	long long int aux;
	
	aux = a.RA;
	aux /= 5;
	aux = pow(aux, 3) - 482456821;
	aux = pow(aux,2);
	aux = (aux % (tam_vetor * 12))/7;
	hash =  aux % (tam_vetor*2);

	aux = strlen(a.nome);

	aux = (a.nome[0]) + (a.nome[aux/3]) + (a.nome[aux-1])*3;
	hash += aux;

	aux = strlen(a.curso)+(hash*2);
	hash += aux;

	hash = hash % tam_vetor;

	/*Elimina a posição inexistente*/
	if (hash == tam_vetor)
	{
		hash--;
	}

	return(hash);
}

bool inserir(TabelaHash* t, Aluno a)
{
	if (t->capacidade == 0)
	{
		return(false);
	}
	
	int pos;
	Node* aux;
	
	aux = (Node*) malloc(sizeof(Node)); //cria um nó 
	aux->data = a; //insere aluno no nó
	
	pos = Hash(a, t->tamvetor); //calcula o hash
	
	aux->next = t->tabela[pos];
	t->tabela[pos] = aux;

	t->capacidade--;
	t->qtde_elementos++;
	return(true);
}

Aluno* buscar(TabelaHash* t, Aluno a)
{
	Node  *redutor;
 	int pos;

	pos = Hash(a, t->tamvetor);

	redutor = t->tabela[pos];
   while (redutor != NULL)
   {
		/*se acrescentar algum campo em aluno adapte este if*/
		if ((redutor->data.RA == a.RA) && (strcmp(redutor->data.nome, a.nome) == 0) && (strcmp(redutor->data.curso, a.curso) == 0)) 
		{
			Aluno* aux;
			aux = (Aluno*) malloc(sizeof(Aluno));
			aux->RA = redutor->data.RA;
			strcpy(aux->nome, redutor->data.nome);
			strcpy(aux->curso, redutor->data.curso);

			return(aux);
		}
		redutor = redutor->next;
   }	   
	
   return(NULL);
}

Aluno* remover(TabelaHash* t, Aluno a)
{
	Node  *redutor, *redutorprev=NULL;
	Aluno* aux = NULL;
 	int pos;
	bool verif=false;

	pos = Hash(a, t->tamvetor);
	redutor = t->tabela[pos];

	while (redutor != NULL)
   	{
		/*se acrescentar algum campo em aluno adapte este if*/
		if ((redutor->data.RA == a.RA) && (strcmp(redutor->data.nome, a.nome) == 0) && (strcmp(redutor->data.curso, a.curso) == 0)) 
		{
				/*esse if será executado apenas se não foi removido nenhuma outra vez*/
				if(aux == NULL)
				{
			aux = (Aluno*) malloc(sizeof(Aluno));
			aux->RA = redutor->data.RA;
			strcpy(aux->nome, redutor->data.nome);
			strcpy(aux->curso, redutor->data.curso);
				}

			if (redutorprev == NULL)
			{
				t->tabela[pos] = redutor->next;
			}
			else
			{
				redutorprev->next = redutor->next;
			}

			Node* redutoraux; //se for removido este aux irá guiar o redutor para remover os próximos, independetemente do if;
			
			redutoraux = redutor->next;
			redutor->next = NULL;
			free(redutor);
			redutor = redutoraux;

			t->qtde_elementos--;
			verif = true;
		}

		if (verif == false)
		{
		redutorprev = redutor;
		redutor = redutor->next;
		}
		else
		{
			verif = false;
		}
   }

	return(aux);
}

void print(TabelaHash *t)
{
		int i;

		for (i=0; i<t->tamvetor; i++)
		{
			printf("Posição: %d\n", i);
			
			Node* redutor;
			redutor = t->tabela[i];

			while(redutor != NULL)
			{
				printf("RA: %d\n", redutor->data.RA);
				printf("Aluno: %s\n", redutor->data.nome);
				printf("Curso: %s\n\n", redutor->data.curso);
				redutor = redutor->next;
			}
		}
}

