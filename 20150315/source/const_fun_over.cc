/*************************************************************************
	> File Name: const_fun_over.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Tue Mar 17 10:03:35 2015
 ************************************************************************/

#include<iostream>
using namespace std;


class asd {
	enum {
		size1 = 100,
		size2 = 200
	};
	public:
		asd():size(100){};
		asd(const int& s):size(100){}
		void func() const{
			cout << "const func is called" << endl;
		}
		void func(){
			cout << "non-const func is called" <<endl;
		}
	private:
		
		const int size;
		int arr1[size1];

};

void usercode(asd& fred, const asd& cfred){
	fred.func();
	cfred.func();
}

const int test_ret(){
	const int a = 1;
	return a;
}


int main(){
	asd fred;
	int a ;
	const asd cfred(2);
	const asd* c = new asd();
	asd * d = c;
	usercode(fred,cfred);
	a = test_ret();
	cout << a <<endl;
	cout << "a = 3" << (a=3)<<endl;

	return 0;
}
