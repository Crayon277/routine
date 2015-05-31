#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define SIZE 100000

void swap(int *a ,int *b){
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void arr_init(int *arr,int len){
    int iloop;

    for(iloop = 0;iloop < len;iloop ++){
        arr[iloop] = rand()%100;
    }
}
void bubble_sort(int * arr, int len){
    int index_i,index_j;
    int flag = 1;

    for(index_i = 0; index_i < len && flag; index_i ++){
        flag = 0;
        for(index_j = len-1;index_j >=index_i;index_j--){
            if(arr[index_j]<arr[index_j-1]){
                swap(&arr[index_j],&arr[index_j-1]);
                flag = 1;
            }
        } 
    }

}

void print_bubble(int *arr, int len){
    int iloop;
    
    for(iloop = 0; iloop < len;iloop ++){
        printf("%d ",arr[iloop]);
    }
    
}

int main(){
    int arr[SIZE];
    clock_t bg,end;
    
    arr_init(arr,SIZE);
  //  print_bubble(arr,SIZE);
    
    bg = clock();
    bubble_sort(arr,SIZE);
    end = clock();
    
//    print_bubble(arr,SIZE);
    
    printf("%.9fs",(double)(end - bg)/CLOCKS_PER_SEC);
}