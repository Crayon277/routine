/*************************************************************************
	> File Name: newday.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jan 11 15:08:57 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[]){
	if(argc <2 ){
		perror("dirname should be given");
		exit(1);
	}
	char dirname[15];
	
	struct tm *today;
	time_t tloc;
	time(&tloc);
	today = gmtime(&tloc);
	chdir(argv[1]);
	sprintf(dirname,"%d-%02d-%d",today->tm_mday,today->tm_mon+1,today->tm_year+1900);
	//上面原来写着%d/%d/%d，报错的原因，是因为/系统会看成一级目录，所以报错不存在
	printf("%s\n",dirname);
	if(mkdir(dirname,0777)){
		perror("making dirname\n");
		exit(1);
	}
	return 0;
}
