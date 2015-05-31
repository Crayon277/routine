#include<stdio.h>

int main(){
    int i=1;
    char word[10];
    while(scanf("%s[^ ]",word) == 1){
       if(i++%2 == 0){
            fprintf(stdout,"%s\n",word);
         }else{
             fprintf(stderr,"%s\n",word);
         }
    }
    return 0;
}
