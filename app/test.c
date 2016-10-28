#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  

typedef struct student
{
	int age;
	char name[100];
}ST;



int sqf1(void)  
{  
	ST sqf[10];
	int i = 0;

	memset(sqf,0x00,sizeof(ST));

	for (;i<10;i++)
	{
		sqf[i].age=1;
		strcpy(sqf[i].name,"sqf");
	}
	i = 0;

	for (;i<10;i++)
	{
		printf("the result is:[%d][%d]\n",i,sqf[i].age);
		printf("the result is:[%d][%s]\n",i,sqf[i].name);
	}

return 0;
}
