/*************************************************************************
	> File Name: shushiwenti.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Jun  2 19:36:04 2015
 ************************************************************************/

//#define DEBUG
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define Iniative 100
#define Increment 50
int main(){
	char set_in[10];
	int book[10] = {
		0
	};
	int set[10],n = 0,i,j,k,i_three = 0,i_two = 0;
	int size_three = Iniative,
		size_two = Iniative;
	int *set_three = (int*)calloc(Iniative,sizeof(int));
	int *set_two = (int*)calloc(Iniative,sizeof(int));
	scanf("%s",set_in);
	clock_t t1 = clock();
	while(set_in[n] != '\0'){
		set[n] = set_in[n] - '0';
		book[set[n]] = 1;
		n++;
	}
	#ifdef DEBUG
	//test
	//
	for(i = 0 ; i!= n ;i++){
		// if(i == set[i]) 
			printf("%d ",set[i]);
	}
	printf("\n");
	for(i = 0 ;i!=10;i++){
		printf("%d ",book[i]);
	}
	//
	getchar();
	getchar();
	//
	#endif

	//三位数的集合
	for(i = 0;i!=n ; i++){
		for(j = 0;j!=n;j++){
			for(k = 0 ; k!=n ;k++){
				if(i_three == Iniative){
					set_three = realloc(set_three,sizeof(int)*(size_three  + Increment));
					size_three += Increment;
				}
				set_three[i_three++] = set[i]*100 + set[j]*10+set[k]; 
			}
		}
	}
	#ifdef DEBUG
	for(i = 0; i!= i_three;i++){
		printf("%d ",set_three[i]);
	}
	printf("\n");
	getchar();
	getchar();
	#endif

	//两位数的集合
	for(i = 0; i!=n;i++){
		for(j = 0 ;j!=n;j++){
			if(i_two == Iniative){
				set_two = realloc(set_two,sizeof(int)*(size_two + Increment));
				size_two += Increment;
			}
			set_two[i_two++] = set[i]*10 + set[j];
		}
	}

	#ifdef DEBUG
	for(i = 0; i!= i_two ;i++){
		printf("%d ",set_two[i]);
	}
	printf("\n");
	getchar();
	getchar();

	#endif

	//每次从集合中取两个
	for(i = 0 ; i != i_three ; i++){
		for(j = 0;j!=i_two ;j ++){
			int mid_1,mid_2,final,flag = 0,mid_1_bak,mid_2_bak,final_bak;
			//测试中间过程是否也是属于集合的，是的话继续测试，否则下一组
			mid_1 = set_three[i] * (set_two[j]%10);
			mid_1_bak = mid_1;
			while(mid_1){
				if(book[mid_1%10] != 1){
					flag = 1;
					break;
				}
				mid_1 /= 10;
			}
			if(flag == 1){
				continue;
			}
			mid_2 = set_three[i] * (set_two[j]/10);
			mid_2_bak = mid_2;
			while(mid_2){
				if(book[mid_2%10] != 1){
					flag = 1;
					break;
				}
				mid_2 /= 10;
			}
			if(flag == 1){
				continue;
			}
			
			//测试最后结果是否也是属于集合的
			final = set_three[i] * set_two[j];
			final_bak = final;
			while(final){
				if(book[final%10]!=1){
					flag = 1;
					break;
				}
				final /= 10;
			}
			if(flag == 1){
				continue;
			}
			//打印格式
			printf("%5d\n",set_three[i]);
			printf("X%4d\n",set_two[j]);
			printf("-----\n");
			printf("%5d\n",mid_1_bak);
			// printf("%-5d\n",mid_2_bak); 
			printf("%4d\n",mid_2_bak);
			printf("-----\n");
			printf("%d\n",final_bak);
		}
	}
	clock_t t2 = clock();
	printf("Time used %.10lf\n",(double)(t2-t1)/CLOCKS_PER_SEC); //0.00011000000

	return 0;
}


/*
//solution of using char array
//能否想到用这种方法。
#include<stdio.h>
#include<string.h>
#include<time.h>
int main(){
	int i,ok,abc,de,x,y,z,count = 0;

	char s[20],buf[99];
	scanf("%s",s);
	clock_t t1 = clock();
	for(abc = 111;abc<999;abc++){
		for(de = 11;de <= 99; de++){
			x = abc*(de%10);y = abc*(de/10);z = abc*de;
			ok = 1;
			sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
			for(i = 0;i < strlen(buf);i++){
				if(strchr(s,buf[i]) == NULL){
					ok = 0;
					break;
				}
			}
			if(ok){
				count++;
				printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%d\n",abc,de,x,y,z);
			}
		}
	}
	clock_t t2 = clock();
	printf("The number of solutions = %d\n",count);
	printf("Time used %.10lf\n",(double)(t2-t1)/CLOCKS_PER_SEC);//0.0262060000
	return 0;
}
*/
