#include <stdio.h>

int main(){
    int i;
    int msg[5];

    printf("Input 25 characters \n");
    for(i = 0;i<5;i++){
        msg[i] = getchar();
        if(msg[i] == '\n'){
            //如果这样是不是不能输入\n符号？
            //TODO:如果手动输入\n的话，是不是分开的？一个是\，一个是n
            i--;
            printf("end index:%d\n",i);
            break;
        }
    }
    fflush(stdin);
    char c = getchar();
    putchar(c);
    putchar('\n');
    printf("----putchar-\n");
    for(;i>=0;i--){
        putchar(msg[i]);
    }
    putchar('\n');
    printf("----puts-\n");
    puts(msg);
    putchar('\n');
    return 0;
}