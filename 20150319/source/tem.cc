/*************************************************************************
	> File Name: tem.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 20:43:05 2015
 ************************************************************************/

#include<iostream>
using namespace std;

template<class numtype>
class Compare{
	public:
		Compare(numtype a, numtype b){
			x = a;
			y = b;
		}
		numtype max();
		/*
		numtype max(){
			return (x > y)? x: y;
		}
		*/
		numtype min();
	private:
		numtype x;
		numtype y;
};

template<class numtype>
numtype Compare<numtype>::max(){
	return (x > y)? x:y;
}
template<class numtype>
numtype Compare<numtype>::min(){
	return (x < y)? x:y;
}

int main(){
	Compare<int> cmpl(3,7);
	cout << cmpl.max() << "is the maximun of two integer numbers." <<endl;
	cout << cmpl.min() << "is the minimun of two integer numbers." <<endl;

	Compare<float> cmp2(45.78,93.6);
	cout << cmp2.max() << "is the maximun of two float numbers." <<endl;
	cout << cmp2.min() <<"is the minimun of two float numbers." <<endl;

	Compare<char> cmp3('a','A');
	cout <<cmp3.max() << "is the maximun of two characters." <<endl;
	cout <<cmp3.min() << "is the minimun of tow characters." <<endl;
	return 0;
}
