#include <stdio.h>
#include "bibponteiros.h"

int main(){
	
	
	
	printf("\nEX 01\nn=%i valor=%d\n", 2,3);
	criaVet(2, 3);
	printf("\nEX 02\nn=%i\n", 10);
	criaVetAl(10);
	printf("\nEX 03\nlinha=%i coluna=%i valor=%i", 4, 3, 10);
	criaMat(4, 3,10);	
	printf("\nEX 04\nString: daniel\n");
	strCopy("daniel");
	printf("\n\nEX 05\nString: daniel\ninicio: 2\nfim: 5");
	sub1("daniel", 2, 5);

	return(0);
}
