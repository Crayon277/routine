/*************************************************************************
	> File Name: test_vir.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Mar 29 17:14:38 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class point{
	public:
	point(){

	}
	virtual ~point(){
		cout << "point quit " <<endl;
	}

};

class circle:public point{
	public:
	circle(){

	}
	~circle(){
		cout << "circle quit" <<endl;
	}
};

int main(){
	point *c = new circle;
	delete c;
	return 0;
}
