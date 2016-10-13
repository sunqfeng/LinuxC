#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LenTable ( tab ) ( sizeof(tab) / sizeof(tab[0]) )

void desum()
{
	static int sum=10;
	return ;
}

void sum1( int *psum )
{
	*psum=*psum+1;
	return ;
}

void sum2( int *psum )
{
	*psum=*psum+1;
	return ;

}

int main()
{ 
	int i=0;

	int a=3;
	a+=a-=a*a;
	printf("the a is:%d\n", a );

	return 0;
}
