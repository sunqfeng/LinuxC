
#ifndef _VAR_INC
#define _VAR_INC
extern char RSPCODE[6];
#endif


#define EXIT  \
if ( strcmp(RSPCODE,"000000")) \
{ \
	printf("the tran success main()\n"); \
	return 0; \
} \
else \
{ \
	printf("the tran error main()\n"); \
	return -1; \
}\

