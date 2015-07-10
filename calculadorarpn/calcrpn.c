#include "tokenbib.h"
#include "pilhadinamica.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

double* Calc(int linhas, int* colunas, FILE *fp)
{
	int i;
	double valstack, v1,v2, *resultados;
	char* expressao, *str;
	TokenReader *tk;
	Stack *s;

	//onde os resultados de cada linha ficarão armazenados
	resultados = (double*) malloc(sizeof(double)*linhas);

	for (i=0; i<linhas; i++)
	{
		expressao = (char*) malloc(sizeof(char)*(colunas[i]+1));
		fscanf(fp, "%[^\n]\n", expressao);
		//		expressao[colunas[i]+1] = '\0';
//		printf("---%s", expressao);
		//cria token
		tk = newTokenReader(expressao);	
		//cria stack
		s = createStack();
		initializeStack(s);
		while(hasMoreTokens(tk))
		{
			str = nextToken(tk);
			if (isdigit(str[0]))
			{
				valstack = atof(str);
				push(s, valstack);	
			}	
			else
			{
				switch (str[0])
				{
					case '+':
						pop(s, &v2);
						pop(s, &v1);	
						valstack = v1 + v2;
						push(s, valstack);	
						break;
					case '-':
						pop(s, &v2);
						pop(s, &v1);	
						valstack = v1 - v2;
						push(s, valstack);	
						break;
					case '*':


						pop(s, &v2);
						pop(s, &v1);	
						valstack = v1 * v2;
						push(s, valstack);	
						break;

					case '/':
						pop(s, &v2);
						pop(s, &v1);	
						valstack = (double) v1 / v2;
						push(s, valstack);	
			
			break;
				}
			}
			free(str);	
		}
			
		peek(s, &resultados[i]);
		free(expressao);
		freeTokenReader(tk); 
		free(s);
	}
	return(resultados);
}

int main(int argc, char* argv[]){

	FILE *fp, *fop;

	fp = fopen(argv[1], "r");
	fop = fopen("saida.txt", "w");
	int i, linhas=0;
	double *resultados;
	char c;


	do {
		c = fgetc(fp);
		if ((c == '\n'))
		{
			linhas++;
		}
	} while(c != EOF);

	rewind(fp);

	int colunas[linhas];

	//inicializa o vetor colunas	
	for (i=0; i<linhas; i++)
	{
		colunas[i] = 0;
	}

	//verifica o número de colunas por linha
	for (i=0; i<linhas; i++)
	{
		do
		{
			c = fgetc(fp);
			if (c!='\n')
			{
				colunas[i]++;
			}

		} while (c != '\n');	

	}


/*	printf("linhas %d, ", linhas);
	for (i=0; i<linhas; i++)
	{
		printf("\ncoluna%d:%d", i, colunas[i]);
	}*/
	rewind(fp);

	
	resultados = Calc(linhas, colunas, fp); 
	// imprime no arquivo
	for (i=0; i<linhas; i++)
	{
		fprintf(fop, "%lf\n", resultados[i]);
	}
	free(resultados);
	fclose(fop);
	fclose(fp);

	return(0);
}
