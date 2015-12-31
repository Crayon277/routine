/*************************************************************************
	> File Name: insert_sort_binarysearch.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Dec 15 21:51:53 2015
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define len 10

int binary_search(int *arr,int low,int high,int key){
	int mid;
	while(low<=high){
		mid=low+(high-low)/2;
		
		if(arr[mid]>key){
			high = mid-1;
		}else{
			low=mid+1;
		}
	}
	if(arr[mid]>key){
		return mid;
	}else{
		return mid+1;
	}
}

void insert_sort(int *arr){
	int i;
	for(i=1;i<len;i++){
		int insert_position = binary_search(arr,0,i-1,arr[i]);
		int j;
		int tmp=arr[i];
		for(j=i;j>insert_position;j--){
			arr[j]=arr[j-1];
		}
		arr[j] = tmp;
	}
}
//===========================================
void insertSort(int *arr){
	int i,j,low,high,mid;
	for(i=1;i<len;i++){
		int tmp=arr[i];
		low=0;high=i-1;
		while(low<=high){//最后一躺low=high时，key肯定是大于等于前面所有的
			mid=(low+high)/2;
			if(arr[mid]>tmp){//如果最后一躺小那么就插入在这个位置
				high = mid-1;//最后一躺high小于了low
			}else{//如果最后一躺大于或等于，那表明插入在这后面
				low=mid+1;//low向前进，low>high
			}
		}//最后low指向要插入的位置
		for(j=i;j>low;j--){
			arr[j]=arr[j-1];
		}
		arr[low] = tmp;//插入在low位置
	}
}
//==========================================
int main(){
	int a[len];
	int index;
	srand(time(NULL));
	for(index=0;index<len;index++){
		a[index] = rand()%20;
		printf("%d ",a[index]);
	}
	printf("\n");
//	insert_sort(a);
	insertSort(a);
	for(index = 0; index<len;index++){
		index!=len-1?printf("%d ",a[index]):printf("%d\n",a[index]);
	}
	return 0;
}
