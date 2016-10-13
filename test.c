#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  

void hello(char *s)
{
	printf("the A is:[%s]\n",s);

	if ( *s != '\0' )
	{
		hello(s+1);
		printf("the B is:[%s]\n",s);
	}
}

int main(void)  
{  

	hello("u kcuf");

return 0;
}
