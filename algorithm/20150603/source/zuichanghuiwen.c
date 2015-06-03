/*************************************************************************
	> File Name: zuichanghuiwen.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 08:38:46 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
int main(){
	char origin[100];
	int i,j,m,n,start,end,max;
	/* scanf("%s",origin); */
	fgets(origin,sizeof(origin),stdin);	

	//compare
	clock_t t1 = clock();
	max = 0;
	for(i = 0 ;i<strlen(origin) ;i++){
		if(!isalpha(origin[i])){
			continue;
		}
		for(j = i;j<strlen(origin);j++){
			int flag = 0;
			int count = 0;
			int first,flag_first = 1,
				last, flag_last = 1;
			m = i;n = j;
			while( m <= n){
				if(!isalpha(origin[m])){
					m++;
					
					continue;
				}
				if(!isalpha(origin[n])){
					n--;
					continue;
				}
				if(toupper(origin[m]) == toupper(origin[n])){
					if(flag_first){
						first = m;
						flag_first = 0;
					}
					if(flag_last){
						last = n;
						flag_last = 0;
					}
					if(m!=n){
						count += 2;
					}
					if(m ==n){
						count ++;
					}

					m++;
					n--;
				}else{
					flag = 1;
					break;
				}
			}
			if(!flag && max < count){
				//start = i;//有一个bug，当%$abccba,输出应该是abccba，但是连%$也一起输出了，因为start是等于i，而i这个可能不是字符
				//end = j;
				start = first;
				end = last;
				max = count;
			}
			/* if(first != j){ */
				/* j = first;//first记录的是第一个下一个字符的位置，是字符的就不用比较了 */
			/* } */
			//上面的不行，因为死循环了，m是i，first又是第一个字符的m,而i不动的话，j一直回到i附近，而i要动必须j要动。
		}
	}

	for(i = start; i<=end;i++){
		printf("%c",origin[i]);
	}
	printf("\nmax: %d\n",max);
	clock_t t2 = clock();
	printf("Time use %.7lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);
	return 0;
}
