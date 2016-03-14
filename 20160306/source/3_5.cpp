/*************************************************************************
	> File Name: 3_5.cpp
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Mar  8 14:45:06 2016
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	int candidate[6]={
		0//have to initiate to zero.
	};
	int vote;
	while(cin>>vote){
		if(vote>=1&&vote<=5){
			candidate[vote]++;
		}else{
			candidate[0]++;
		}
	}
	for(int i=1;i<6;i++){
		cout<<"candidate "<<i<<"'s vote:"<<candidate[i]<<endl;
	}
	cout<<"abstention vote:"<<candidate[0]<<endl;
	return 0;
}
