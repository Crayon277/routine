/*************************************************************************
	> File Name: vector.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Jun  1 20:11:20 2015
 ************************************************************************/
#include<vector>
#include<iostream>
using namespace std;

int main(){
	int i ,count = 0;
	vector<int> ivec;
	// for(vector<int>::size_type ix = 0 ; ix != 10; ++ix){
		// ivec.push_back(ix);
	// }
	//
	while(cin >> i){
		count++;
		ivec.push_back(i);
	}

	
	for(vector<int>::iterator iter = ivec.begin();iter != ivec.end(); iter += 2){
		if((iter+1) != ivec.end()){
			cout << *(iter) + *(iter+1) <<endl;
		}
		else{
			cout << "last one is isolate "<< *iter <<endl;
			break;
		}
	}
	cout << "===================" <<endl;
	cout <<"Version 2\n";
	
	for(vector<int>::iterator iter_head = ivec.begin(), iter_tail = ivec.end() - 1; iter_head <= iter_tail; iter_head ++, iter_tail--){
		if(iter_head < iter_tail){
			cout <<*iter_head << "+" <<*iter_tail <<"=" << *iter_head + *iter_tail <<endl;
		}
		else{
			cout << "It's odd sequence, last one not added is " << *iter_head <<endl;
		}
	}
	cout << "=======" <<endl;
	for(vector<int>::iterator iter = ivec.begin(); iter!= ivec.end();iter++){
		cout << *iter <<endl;
	}

	return 0;
}
