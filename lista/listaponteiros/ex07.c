#include <stdio.h>

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




int main(){

	int* a;			//i
	int* b;			//i
 				//i
	int a2, b2;		//i
				//i
	a2 = 2;			//i
	b2 = 3;			//i
				//i
	a = &a2;		//i
	b = &b2;		//i


	char* c;			//s
	char* d;			//s
					//s
	char str1[15] = {"a"};	//s
	char str2[15] = {"A"};	//s
					//s
	c = str1;			//s
	d = str2;			//s

	
	double* e;
	double*	f;

	double e2, f2;
	
	e2 = 2.15;
	f2 = 3.26;
	
	e = &e2;
	f = &f2;

	printf("retornado int: %i\n", compara_int((void*)a,(void*)b));
	printf("retornado char: %i\n", compara_string((void*)c, (void*)d));
	printf("retornado double: %i\n", compara_double((void*)e, (void*)f));
	
	return(0);
}
