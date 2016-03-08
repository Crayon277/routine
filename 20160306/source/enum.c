/*************************************************************************
	> File Name: enum.c
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar  7 09:58:24 2016
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

enum season{
	spring, summer=100,fall=96,winter
};

typedef enum{
	Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday
}Weekday;

int main(){
	printf("%d\n",spring);
	printf("%d,%c\n",summer,summer);
	printf("%d\n",fall+winter);
	enum season myseason = winter;
	if(winter == myseason){
		printf("myseason is winter\n");
	}

	int x = 100;
	if(x==winter){
		printf("x is equal to summer ");
	}

	int today = Monday;
	Weekday tomorrow;
	if(today == Monday){
		tomorrow = Tuesday;
	}else{
		tomorrow = (Weekday)(today+1);
	}
	printf("tomorrow is %d th",tomorrow+1);

	return 0;

}
