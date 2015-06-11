/*************************************************************************
	> File Name: enume_div.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun 10 08:40:30 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int book[10] = {
		0
	},
		bookbak[10] = {
			0
		};
	int n;
	scanf("%d",&n);

	int a,b,c,d,e;
	for(a = 0;a<=9; a++){
		//memset(book,0,sizeof(book));
		book[a] = 1;
		for(b = 0; b<=9;b++){
			if(book[b]){
				continue;
			}
			book[b] = 1;
			for(c = 0;c<=9;c++){
				if(book[c]){
					continue;
				}
				book[c] = 1;
				for(d = 0;d<=9;d++){
					if(book[d]){
						continue;
					}
					book[d] = 1;
					for(e = 0 ;e<=9;e++){
						if(book[e]){
							continue;
						}
						book[e] = 1;
						int divisor = a * 10000+b*1000+c*100+d*10+e;
						int dividend = divisor * n;
						while(dividend){
							if(book[dividend%10] || bookbak[dividend%10]){
								break;
							}
							bookbak[dividend%10] = 1;
							dividend /= 10;
						}
						if(!dividend){
							printf("%d / %d = %d\n",divisor*n,divisor,n);
						}
						book[e] = 0;
						memset(bookbak,0,sizeof(bookbak));	
					}
					book[d] = 0;
				}
				book[c] = 0;
			}
			book[b] = 0;
		}
		
		book[a] = 0;
	}
	return 0;
}
