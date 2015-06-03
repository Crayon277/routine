/*************************************************************************
	> File Name: stat.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Wed Jun  3 21:18:31 2015
 ************************************************************************/
//#define MISSION_1
#define MISSION_2

#include<stdio.h>
#include<stdlib.h>
#define size 100
#ifdef MISSION_1
int main(){
	int a[size] = {
		0
	};
	//int max[size];
	int i,score,max = 0;
	int how_many;
	scanf("%d",&how_many);

	for(i = 0 ; i < how_many;i++){
		scanf("%d",&score);
		a[score] ++;
		if(a[score] > max){
			max = a[score];
		}
	}

	for(i = 0;i < size;i++){
		if(a[i] == max){
			printf("%d\n",i);
		}
	}
	return 0;

}

#endif


#ifdef MISSION_2

int main(){
	double score[size];
	int map[size] = {
		0
	};
	int i,j,max = 0;
	double sc;
	int how_many;
	scanf("%d",&how_many);  

	for(i = 0; i<how_many;i++){
		int flag = 0;
		scanf("%lf",&sc);
		for(j = 0;j<i;j++){
			if(score[j] == sc){
				flag = 1;
				break;
			}
		}
		if(flag){
			map[j]++;
			if(map[j] > max){
				max = map[j];
			}
		}else{
			score[i] = sc;
			map[i] ++;
			if(map[i] > max ){
				max = map[i];
			}
		}
	}
	for(i = 0; i<how_many;i++){
		if(map[i] == max){
			printf("%.2lf\n",score[i]);
		}
	}
	return 0;
}

#endif
