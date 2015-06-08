/*************************************************************************
	> File Name: gamecard.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Jun  7 15:45:49 2015
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

queue<int> q;


int main(){
	int n;
	cin >> n;
	for(int i= 0;i < n;i++){
		q.push(i+1);
	}
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << endl;
	return 0;
}
