/*************************************************************************
	> File Name: 10021.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jan 12 13:29:13 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int count=1;
	int n;
	char op1[1001],op2[1001],sum[1002];
	scanf("%d",&n);
	while(n--){
		memset(sum,0,sizeof(sum));
		int len1,len2,len3 = 0;
		int carry=0,bit,tmp;
		scanf("%s%s",op1,op2);
		len1 = strlen(op1);
		len2 = strlen(op2);
	
		while(len1>0 || len2>0){
			if(len1>0 && len2>0 ){
				tmp = op1[len1-1] + op2[len2-1]-'0'+carry;
			}else if(len1>0 && !len2 > 0){
				tmp = op1[len1-1] + carry;
			}else{
				tmp = op2[len2-1] + carry;
			}
			if(tmp>'9'){
				sum[len3++] = tmp - 10 ;
				carry = 1;
			}else{
				sum[len3++] = tmp;
				carry = 0;
			}
			len1--;
			len2--;
		}
		if(carry){
			sum[len3++] = 49;
		}
		printf("Case %d:\n",count++);
		printf("%s + %s = ",op1,op2);
		while(len3){
			printf("%c",sum[len3-1]);
			len3--;
		}
		if(n==0){
			printf("\n");
		}else{
				printf("\n\n");
		}
	}
}
