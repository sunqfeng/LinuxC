/*************************************************************************
* File Name: optionfile.c
* Author: sqf
* mail: 18722358342@163.com
* Created Time: Wed 12 Oct 2016 03:50:06 PM EDT
*************************************************************************/

#include <sys/stat.h>
#include <sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/file.h>


typedef struct filestr
{
	int 	port;
	int	mulit_accept;
	char 	wel_msg[1000];
	char	bye_msg[1000];
}ACfilestr;

void remspc(char *objsrc ,char *tmp )
{
	char str[100];
	int i=0;
	memset(str,0x00,sizeof(char)*100);

	while ( *tmp!='\0' )
	{
		if (*tmp!=' ')
		{
			str[i]=*tmp;
			i++;
		}
		tmp++;
	}
	strcpy(objsrc,str);
}


void optionfile( ACfilestr  *acFilestr,int op_flag )
{
	char ch[100];

	FILE *fp=NULL;
	char key[100];
	char value[100];

	char objkey[100];
	char objvalue[100];

	memset(ch,0x00,sizeof(char)*100);
	memset(key,0x00,sizeof(char)*100);
	memset(value,0x00,sizeof(char)*100);

	if ( op_flag == 0 ) /*进行文件的读操作*/
	{
		if((fp = fopen("/home/sqf/sqftest/config.txt","r"))==NULL)
		{
			printf("open file error\n");
			return ;
		}
		else   /*给文件加锁(该文件被多个程序访问、修改)*/
		{
			
			while (1)  /*一直等待枷锁*/
			{
				int  i = flock(fileno(fp), LOCK_EX | LOCK_NB); // 加锁前判断文件是否已经被加锁了
				if ( i<0 )	
				{
					printf("the file is locked faile==[%d]\n",i);
				}
				else
				{
					printf("the file is locked success==[%d]\n",i);
					break;
				}
			}
			
			sleep(100);
			while (fgets(ch,100,fp))
			{
				int i = 0;
				int m=0;
				char *p = NULL;
				char *head = NULL;
				char *tail = NULL;

				head = ch;
				tail = ch;

				/*
				   printf("the result is:%s",ch);
				   */
				while (*tail != '\0')
				{
					if ( *tail == '=' )
					{
						strncpy(key,head,tail-head);
						head = tail+1;
					}
					tail++;
				}
				strncpy(value,head,tail-head-1 ); /*多减一位去掉换行符*/

				remspc(objkey,key);
				remspc(objvalue,value);

				/*
				   printf("the key is=[%s]\n",objkey );
				   printf("the value is=[%s]\n",objvalue );
				   */
				if (strcmp(objkey,"listen_port") == 0)
				{
					acFilestr->port = atoi(objvalue); /*取得目标值付给结构体变量*/
				}

				memset(ch,0x00,sizeof(char)*100 );
				memset(key,0x00,sizeof(char)*100 );
				memset(objkey,0x00,sizeof(char)*100 );
				memset(value,0x00,sizeof(char)*100 );
				memset(objvalue,0x00,sizeof(char)*100 );
			}
		}
		flock(fileno(fp), LOCK_UN); /*释放锁*/
	}

	fclose(fp);
	return ;
}


int main()
{
	ACfilestr acfile;

	memset(&acfile,0x00,sizeof( ACfilestr ));

	optionfile( &acfile,0 );
	printf("the port is==[%d]\n",acfile.port);

return 0;

}
