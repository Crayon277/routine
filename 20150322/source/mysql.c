/*************************************************************************
	> File Name: mysql.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Mar 22 17:07:20 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <my_global.h>
#include <mysql.h>
int main(int argc, char **argv)
{

	 printf("MySQL client version: %s\n", mysql_get_client_info());
	  exit(0);
}
