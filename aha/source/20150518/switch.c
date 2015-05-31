/*************************************************************************
	> File Name: switch.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri May 22 08:18:59 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int i;
	scanf("%d",&i);
	/* int local = 9; */
	/* printf("%p\n",&local); */
	switch(i){
		int local;
		case 1:printf("%lu:%p:%d\n",sizeof(local),&local,local);break;
		case 2:printf("%d\n",i+ local);break;
		default:break;
	}

	return 0;
}
