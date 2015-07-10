#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "bibponteiros.h"
/*--------------EX 01--------------*/
int* criaVet(int pos, int val){

	int* tmp;
	int i;
	tmp = (int*) malloc(sizeof(int)*pos);

	for(i=0; i<pos; i++)
	{
		tmp[i] = val;
	}
	
	for (i=0; i<pos; i++)
	{
		printf("Vetor[%d] = %d\n", i, tmp[i]);
	}

	return(tmp);
}

/*--------------EX 02--------------*/
int* criaVetAl(int n){

	int i;
	int* tmp;
	tmp = (int*) malloc(sizeof(int)*n);

	srand(time(NULL));

	for (i=0; i<n; i++)
	{
		tmp[i] = rand()%((3*n)+1);
	}

	for(i=0; i<n; i++)
	{
		printf("Vetor[%d] = %d\n",i, tmp[i]);
	}
	
	return(tmp);
}

/*--------------EX 03--------------*/
int** criaMat(int lin, int col, int val){

	int** tmp;
	int i,j;

	tmp = (int**) malloc(lin*sizeof(int**));

	for (i=0; i<lin; i++)
	{
		tmp[i] = (int*) malloc(col*sizeof(int*));
		for (j=0; j<col; j++)
		{
			tmp[i][j] = val;
		}
	}


	for (i=0; i<lin; i++)
	{
		for (j=0; j<col; j++)
		{
			printf("%i ",tmp[i][j]);
		}
	printf("\n");
	}
	return(tmp);
}

/*------------EX 04-------------*/
char* strCopy(char* s){

	char* tmp;
	int i=0,j;

	while (s[i]!='\0')
	{
		i++;
	}

	tmp = (char*) malloc((sizeof(char)*i)+1);

	for (j=0; i>=j; j++)
	{
		tmp[j] = s[j];
	}

	printf("Copia: %s", tmp);
	return(tmp);

}

/*-------------EX 05------------*/
char* sub1(char* s, int inicio, int fim){

	typedef enum {true = 1,	false = 0} bool;

	bool valid;
	char* tmp;

	if ((inicio > fim) || (inicio < 0) || (fim > strlen(s)))
	{
		valid = false;
	}

	else
	{
		char* tmp;
		int j, pos=0;

		valid = true;
		tmp = (char*)  malloc(sizeof(char*)*((fim-inicio)+10));

		for(j=inicio; j<=fim; j++)
		{
			*(tmp+pos) = s[j];
			pos++;
	printf("%c", tmp[pos-1]);
		}
	*(tmp+pos) = '\0';
	}



	if (valid == true)
	{
		setbuf(stdout,NULL);
		printf("\nSubstring: %c", tmp[2]);
		return(tmp);
	}
	else
	{
		return(NULL);
	}
}

/*------------EX 06--------------*/
char* sub2(char* s, int indice){

	char* tmp;
	int stamanho, i, j=0;

	stamanho = strlen(s);

	if (indice < 0)
	{
		indice += stamanho;
	}

	tmp = (char*) malloc((stamanho-indice)*sizeof(char*));

	for (i=indice; i<=stamanho; i++)
	{
		tmp[j] = s[i];
		j++;
	} 


	return(tmp);
}

/*--------------EX 07--------------*/
int compara_int(void* a, void* b)
{
	int val;

	if( (*(int*) a) > (*(int*) b) )
	{
		val = 1;
	} 

	else
	{
		if ( (*(int*) a) < (*(int*) b) )
		{
			val = -1;
		}
	
		else
		{
			val = 0;
		}
	}

	return(val);
}

int compara_double(void* a, void* b)
{
	int val;

	if( (*(double*) a) > (*(double*) b) )
	{
		val = 1;
	} 

	else
	{
		if ( (*(double*) a) < (*(double*) b) )
		{
			val = -1;
		}
	
		else
		{
			val = 0;
		}
	}

	return(val);
}

int compara_string(void* a, void* b)
{
	int val;

	if(strcmp((char*)a,(char*)b)>0)
	{
		val = 1;
	} 

	else
	{
		if (strcmp((char*)a,(char*)b)<0)
		{
			val = -1;
		}
	
		else
		{
			val = 0;
		}
	}

	return(val);
}

/*------------EX 08------------*/
int* intercala1(int* v1, int tamV1, int* v2, int tamV2)
{
	int* tmp;
	int i, j=0, k=0;

	tmp = (int*) malloc(sizeof(int*)*(tamV2+tamV1));

	for (i=0; i<(tamV1+tamV2); i++)
	{
		if (v1[j] > v2[k])
		{
			tmp[i] = v1[j];
			j++;
		}
		else
		{
			tmp[i] = v1[k];
			k++;
		}
	}
	return(tmp);
}

void intercala2(int* vetor, int delimitador, int tamVetor)
{





		
}

/*-------------EX 09--------------*/
void imprime_string(char* s)
{
	
	if (s[0] != '\0')
	{
		printf("%c", s[0]);
		imprime_string(s+1);
	}
	
}

/*-------------EX 10--------------*/
int comprimento_string(char* s)
{
	int val=0;
		
	if (s[0] != '\0')
	{
		val += comprimento_string(s+1);
	}
	
return(val);
}

/*-----------EX 11-------------*/
void copia_string(char* destino, char* origem)
{
	
	int i=0;

	if (*(origem+i) != '\0')
	{
		*(destino+i) = *(origem+i);
		copia_string((destino+i+1), (origem+i+1));
	}
	else
	{
		*(destino+i) = *(origem+i);
	}
}

/*-------------EX 12-------------*/
/*na letra "a" a variável valor não vai estar protegida depois que a função "quadrado" terminar sua execução por isso podemos dizer que é um modo incorreto e não seguro de realizar o exercicio.
  a letra "b" é o modo correto pois o ponteiro foi alocado dinamicamente e por isso está protegido tornando a execução do algoritmo segura. */
