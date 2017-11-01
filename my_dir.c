#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

int main(int argc , char * argv[]){
	/* if(argc < 2){ */
		/* perror("dirname should be given"); */
		/* exit(1); */
	/* } */

	char PathName[256];
	time_t now;
	struct tm* tm_now;
	time(&now);
	tm_now = localtime(&now);
	
	sprintf(PathName,"%d-%02d-%d",tm_now->tm_year+1900,tm_now->tm_mon+1,tm_now->tm_mday);
	printf("Make directory %s\n",PathName);
	if(mkdir(PathName,0777)){
		perror("mkdir ");
		exit(1);
	}
	char buf_path[256];
	/* char buf[256]; */
	sprintf(buf_path,"./%s",PathName);
	chdir(buf_path);

//	printf("%s\n",buf_path);
/*
	if(getcwd(buf,sizeof(buf)) == NULL){
		perror("getcwd");
		exit(1);
	}

	printf("the current dir is :%s\n",buf);
*/
	mkdir("source",0777);
	mkdir("bin",0777);
	mkdir("include",0777);


	return 0;
}
