/*************************************************************************
	> File Name: vmtest.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon May 25 19:54:07 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int hoge;
	char buf[256];
	char n;
	printf("&hoge...%p\n",&hoge);

	printf("Input\r initial value.\n");
	/* fgets(buf,sizeof(buf),stdin); */
	/* sscanf(buf,"%d",&hoge); */
	/* scanf("%c",&n);	 */
	/* printf("%x\n",n);	 */
	scanf("%d",&hoge);
	/* while(scanf("%d",&hoge) != 1){ */
		/* printf("error\n"); */
		/* getchar(); */
	/* } */
	for(;;){
		fflush(stdin);
		printf("hoge .. %d\n",hoge);

		getchar();
		hoge++;
		
	}

	return 0;
}
