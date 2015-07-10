#include <stdio.h>
#include "databib.h"

int main(){

	Date *d;
	char br[11], usa[11];	
	d = createDate(27,01,1995);
	
	if (getDate(d, br) == 1)
	{
		printf("Data no formato brasileiro: %s\n", br);
	}
	else
	{
		printf("Não foi possível recuperar a da data no formato brasileiro.\n");
	}

	if (getAmericanDate(d, usa) == 1)
	{
		printf("Data no formato americano: %s\n", usa);
	}
	else
	{
		printf("Não foi possível recuperar a da data no formato americano.\n");
	}

	if (setDate(d,30,12,1990) == 1)
	{
		printf("A data foi alterada.\n");
	}
	else
	{
		printf("A data não foi alterada.\n");
	}

	if (setDate(d,30,13,1990) == 1)
	{
		printf("A data foi alterada.\n");
	}
	else
	{
		printf("A data não foi alterada.\n");
	}
	
	printf("Dia: %02d\n", getDay(d));
	
	printf("Mês: %02d\n", getMonth(d));
		
	printf("Ano: %04d\n", getYear(d));

	if (getWritingMonth(d) == 0)
	{
	printf("Não foi possivel imprimir o mês por extenso.\n");
	}
	
	if (checkDate(d) == 0)
	{
		printf("Data inválida\n");
	}
	else
	{
		printf("Data válida\n");	
	}
return(0);
}
