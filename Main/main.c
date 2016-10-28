/*************************************************************************
* File Name: main.c
* Author: sqf
* mail: sunqf@lesaas.cn
* Created Time: Fri 09 Sep 2016 07:28:07 AM EDT
*************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mysql.h>
#include "test.h"
#include "var.h"
#include "init.h"


int main( )
{

	int i = 1;
	char acsql[100];
//	MYSQL *mysql_conn = NULL;
	MYSQL mysql_conn;

	memset(&mysql_conn,0x00,sizeof(MYSQL));

	memset(acsql,0x00,sizeof( acsql ));

	if ( i == 4 )		
	{
		printf("1.555555\n");
		strcpy(RSPCODE,"main01");
		EXIT;
	}


	printf("2222\n");
	printf("begin conn the mysql\n");

	i = mysqlcon( &mysql_conn );  /*连接数据库*/
	if ( i!=0 )
	{
		printf("mysqlcon return the mysql_conn is NULL\n");
	}
	showsql( &mysql_conn ); /*查询数据*/
	mysql_close( &mysql_conn );	//释放连接

 return 0;

}
