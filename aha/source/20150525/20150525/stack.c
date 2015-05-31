#include<stdio.h>
#include<stdlib.h>

static int count = 0;

static void hello(void){
    count ++;  
    fprintf(stderr,"hello! %d\n",count);
}

static void foo(void){
    void *buf[1];
    static int i;

    for(i = 0 ; i <= 100 + 2; i++){ // put enough data to overwrite the return address on stack
        buf[i] = hello;
    }
}

static void bye(void) {
    printf("Bye, bye...\n");
    exit(EXIT_SUCCESS);
}

int main(void){
    void *buf[1000];
    int i;

    for (i = 0; i < 1000; ++i) {
        buf[i] = &bye;
    }
    foo();
    return 0;
}
