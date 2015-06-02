/*************************************************************************
	> File Name: open_lamp.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 09:35:01 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n, k,i,j,first = 1;
	scanf("%d %d",&n,&k);
	int *a = (int*)calloc(n+1,sizeof(int));
	memset(a,-1,sizeof(int)*(n+1)); // -1 means the light is off. 1,on;
	/* printf("%lu\n",sizeof(int*));	 */ // 指针类型的是8个字节 
	for(i = 1; i<=k ;i++){
		for(j = 1;j<=n;j++){
			if(j%i == 0){
				a[j] *= -1; 
			}
		}
	}
	/* for(j = 1; j<= n;j++){ */
		/* printf("%d ",a[j]); */
	/* } */
	for(j = 1; j<= n ; j++){
		if(a[j] == 1){
			if(first){
				first = 0;
			}else{
				printf(" ");
			}
			printf("%d",j);
		}
	}
	printf("\n");

	free(a);

	return 0;
}
