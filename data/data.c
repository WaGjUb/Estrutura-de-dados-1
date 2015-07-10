#include <stdio.h>
#include <stdlib.h>
#include "databib.h"

Date* createDate(int d, int m, int y){

	Date* date;
	date = (Date*) malloc(sizeof(Date));	
	date->d = d;
	date->m = m;
	date->y = y;	
	return(date);
}

int getDate(Date *date, char* str){
	if((date->d < 1) || (date->d > 31) || (date->m < 1) || (date->m > 12) || (date->y < 1000))
	{
		return(0);
	}
	else
	{
		sprintf(str, "%02d/%02d/%d", date->d, date->m, date->y);
	}
	return(1);	
}

int getAmericanDate(Date *date, char* str)
{
	if((date->d < 1) || (date->d > 31) || (date->m < 1) || (date->m > 12) || (date->y < 1000))
	{
		return(0);
	}
	else
	{
		sprintf(str, "%02d/%02d/%d", date->m, date->d, date->y);
	}
	return(1);	
}

int setDate(Date *date, int d, int m, int y)
{
	if((d < 1) || (d > 31) || (m < 1) || (m > 12) || (y < 1000))
	{
		return(0);
	}
	else
	{
		date->y = y;
		date->d = d;
		date->m = m;
		return(1);
	}
	
}

int getDay(Date *date)
{
return(date->d);
}

int getMonth(Date *date)
{
return(date->m);
}

int getWritingMonth(Date *date)
{
	if((date->m > 12) || (date->m <1))
	{
		return(0);
	}
char mes[15][20] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

	printf("mês: %s\n", mes[(date->m)-1]);
	return(1);
}

int getYear(Date *date)
{
	if((date->y <1000))
	{
		return(0);
	}
	
	return(date->y);
}

int checkDate(Date *date)
{
	if((date->d < 1) || (date->d > 31) || (date->m < 1) || (date->m > 12) || (date->y < 1000))
	{
		return(0);
	}
	else
	{
	return(1);
	}
}
