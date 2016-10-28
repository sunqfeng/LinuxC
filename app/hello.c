/*************************************************************************
* File Name: hello.c
* Author: sqf
* mail: sunqf@lesaas.cn
* Created Time: Fri 09 Sep 2016 12:26:20 PM EDT
*************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "var.h"

static void sum(int m,int n)
{

	int tmp = 0;	
	tmp = m+n;
	printf("the tmp is:%d\n", tmp );

}

int hello()
{

	int i=0;
	if ( i == 0 )	
	{
		printf("i run func hello()\n");
		strcpy(RSPCODE,"lns603");
		printf("run end hello()\n");
		EXIT;
	}
	int k=1,j=3;
	sum(k,j);
	printf("i am func hello()\n");

return 0;
}
