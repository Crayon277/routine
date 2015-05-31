/*************************************************************************
	> File Name: my_over.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 23 11:41:56 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class funy{
	public:
		funy(int i):ival(i){}
		//void show_sequence();
		void operator->(){
			while(ival != 0){
				cout << ival << " ";
				ival --;
			}
		}	
		//friend void operator -> (funy begin, funy end);
	private:
		int ival;
};


/*
void operator -> (funy begin,funy end){
		while(begin.ival != end.ival){
			cout << begin.ival << " " ;
			begin.ival --;
		}
}
*/

int main(){
	funy begin(10);
	funy end(0);
	begin.operator->();
	begin->;
	return 0;
}
