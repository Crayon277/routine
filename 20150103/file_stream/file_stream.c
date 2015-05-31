#include<stdio.h>
#include<string.h>

int main(){
    char string [100];
    FILE * in = fopen("spooky.csv","r");
    FILE * file1 = fopen("UFO.csv","w");
    FILE * file2 = fopen("Elvis.csv","w");
    FILE * file3 = fopen("others.csv","w");
    while(fscanf(in,"%s[^\n]",string)==1){
        if(strstr(string,"UFO")){
            fprintf(file1,"%s\n",string);
        }else if(strstr(string,"Elvis")){
            fprintf(file2,"%s\n",string);
        }else{
            fprintf(file3,"%s\n",string);
        }
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;

}
