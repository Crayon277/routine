#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc , char * argv[]){
	if(argc < 2){
		perror("dirname should be given");
		exit(1);
	}

	if(mkdir(argv[1],0777)){
		perror("mkdir ");
		exit(1);
	}
	char buf_path[256];
	char buf[256];
	sprintf(buf_path,"./%s",argv[1]);
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
	mkdir("review",0777);


	return 0;
}
