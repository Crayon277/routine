/*************************************************************************
	> File Name: find_word.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Jun  5 20:30:55 2015
 ************************************************************************/
/* #define DEBUG */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp_word(const void *_a,const void *_b){
	char *a = (char *)_a;
	char *b = (char *)_b;

	return strcmp(a,b);
}

int cmp_alpha(const void *_a,const void *_b){
	char *a = (char *)_a;
	char *b = (char *)_b;
	return *a - *b;
	if((*a)>(*b)){
		return 1;
	}else if((*a) == (*b)){
		return 0;
	}else{
		return -1;
	}
}

int main(){
	char origin[2000][10],sort[2000][10];
	int i = 0,n;
	//read several word intp origin arr,
	FILE *fp = fopen("find_word.txt","r");
	while(fscanf(fp,"%s",origin[i])){

		if(origin[i][0] == '*'){
			break;
		}
		i++;
	}

	//sort word with origin arr
	
	qsort(origin,i,sizeof(char[10]),cmp_word);	

	//sort alpha with origin arr per word
	for(n = 0 ;n<i;n++){
		strcpy(sort[n],origin[n]);
		qsort(sort[n],strlen(sort[n]),sizeof(char),cmp_alpha);
	}
	#ifdef DEBUG
	for( n = 0; n< i; n++){
		printf("%s %s\n",origin[n],sort[n]);
	}
	#endif
	//read to-be compare
	char s[10];
	while(fscanf(fp,"%s",s) != EOF){
		int j,k;
		int flag = 1;
		int ok = 0;
		//sort alpha of per word
		qsort(s,strlen(s),sizeof(char),cmp_alpha);
		//print the corresponding one.
		for(j = 0 ; j< i;j++){ // 太麻烦了，直接用strcmp函数一步到位！！！
			//ok = 1;
			flag = 1;
			if(strlen(s) == strlen(sort[j])){
				for(k = 0 ;k<strlen(s);k++){
					if(s[k] != sort[j][k]){
						//ok = 0;
						flag = 0;
						break;
					}
					
				}
			}else{
				flag = 0;
			}
			if(flag){ //测试用例中，course , score 的字符排序，ceorsu, ceors， 前面都是一样的！！
				//这样就说明，resco的匹配会把course也打印出来。所以再加个strlen判断
				ok = 1;
				printf("%s ",origin[j]);
			}
		}
		if(!ok){
			printf(":(\n");
		}else{
			printf("\n");
		}

	}
	//
	//
	fclose(fp);
	return 0;
}
