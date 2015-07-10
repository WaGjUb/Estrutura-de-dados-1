#include "tokenbib.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	char s[] = "Qual é o significado 433,432423 @@@ da variável cont2 ? Representa os 10 elementos do vetor.";
	TokenReader *reader = newTokenReader(s);
	char* str = nextToken(reader);
//	printf("%s\n",str);
	fputs(str,stdout);
	printf("\n");
	free(str);
	str = nextToken(reader);
//	printf("%s \n", str);
	fputs(str,stdout);
	printf("\n");
	free(str);
	while(hasMoreTokens(reader))
	{
		str = nextToken(reader);
		//printf("%s \n", str);
		fputs(str,stdout);
		printf("\n");
		free (str);
	}	
	freeTokenReader(reader);
return(0);
}
