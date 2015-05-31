/*************************************************************************
	> File Name: arr_ob.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 11:36:48 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class ob{
	public:
		ob(int a = 10, int b = 11, int c = 12):key(a),word(b),bin(c){}

		void display(){
			cout << key << " " << word << " " <<bin <<endl;
		}
	private:
		int key;
		int word;
		int bin;
};

int main(){
	ob test[3] = {20,21,22};
	
	test[0].display();
	test[1].display();
	test[2].display();
}

