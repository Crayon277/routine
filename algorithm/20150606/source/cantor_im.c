/*************************************************************************
	> File Name: cantor_im.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Jun  6 14:57:53 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int main(){
	int size,n;
	scanf("%d %d",&size,&n);

	assert(n <= size*size);
	int i=1,s=0; //i represent diagonal
	while(1){
		if(i<=5){
			s+=i;
			if(s>=n){
				if(i&1){
					printf("%d/%d\n",1-n+s,n-s+i);
					break;
				}else{
					printf("%d/%d\n",n-s+i,1-n+s);
					break;
				}
			}

		}else{
			s+=2*size-i;
			if(s>=n){
				int start = n-s+size; // i-size+1+n-(s-2*size+i)-1;
				if(i&1){
					printf("%d/%d\n",i+1-start,start);
					break;
				}else{
					printf("%d/%d\n",start,i+1-start);
					break;
				}
			}
		}
		i++;
	}

	return 0;
}
