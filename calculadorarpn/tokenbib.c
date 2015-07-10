#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenbib.h"
#include <ctype.h>
#include <locale.h>
TokenReader *newTokenReader(char *str)
{
	TokenReader *t;
	t = (TokenReader*) malloc(sizeof(TokenReader));
	t->str = (char*) malloc(sizeof(char)*(strlen(str)+1));
	strcpy(t->str, str);
	t->tam = strlen(t->str);
	t->pos = 0;	
	return(t);
}

void freeTokenReader(TokenReader *reader)
{
	free(reader->str);
	free(reader);
}

char* SubString(char* str, int quantidade)
{

	int i;
	char *novastr;	
	novastr = (char*) malloc(sizeof(char*)*quantidade+1);

	for (i=0; i<quantidade; i++)
	{
		novastr[i] = str[i];
	}
	novastr[i] = '\0';
	return(novastr);
}

char* nextToken(TokenReader *reader)
{


	int posfim=reader->pos, quantidade, posbkup;
	posbkup = reader->pos;

		if ((reader->pos == reader->tam) || (reader->str[posbkup] == '\0'))	
	{
		return(NULL);
	}
	

	if (isalnum(reader->str[posfim]))
	{
		while ((isalnum(reader->str[posfim])) || (reader->str[posfim] == ',') || (reader->str[posfim] == '.'))
		{
			posfim++;
		}
	}	
	else
	{
		posfim++;
	}

	quantidade = posfim - posbkup;
	reader->pos = posfim;

	return(SubString(&reader->str[posbkup], quantidade));
}

void setTokenString(TokenReader *reader, char* str)
{
	free(reader->str);
	reader->str = (char*) malloc(sizeof(char)*(strlen(str)+1));
	strcpy(reader->str, str);
}
int hasMoreTokens(TokenReader *reader)
{
	int indice;

	indice = reader->pos;
	
	while (isalnum(reader->str[indice]))
	{
		indice++;
	}
	if ((reader->pos == reader->tam ) || (reader->str[indice] == '\0'))
	{
		return(0);
	}
	else
	{
		return(1);
	}

}
