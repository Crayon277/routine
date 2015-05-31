#include<stdio.h>
#include<stdlib.h>

static int count = 0;

void hello(void){
	count ++;

	fprintf(stderr,"hello! %d\n",count);
}

void func(void){
	void *buf[10];
	static int i;

	for(i = 0 ; i < 100 ; i++){
		buf[i] = hello;
	}
}

int main(void){
	int buf[1000];
	func();
	return 0;
}
