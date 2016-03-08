/*************************************************************************
	> File Name: 1096_1.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jan 11 13:27:21 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	char ch;
	int sum=0,m,t,i;
	//sum = (int *)malloc(n*sizeof(int));
	/* for(i=0;i<n;i++){ */
		/* sum[i]=0; */
   /*  } */
	for(i=0;i<n;i++){
		scanf("%d",&m);
		while((ch=getchar())!='\n'){
			if(ch == ' ')
				continue;
			ungetc(ch,stdin);
			scanf("%d",&t);
			sum+=t;
		}
		printf("%d\n\n",sum);
	}
		//free(sum);	
	return 0;
}
