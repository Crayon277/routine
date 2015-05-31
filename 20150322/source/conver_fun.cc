/*************************************************************************
	> File Name: conver_fun.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Mon Mar 23 19:55:50 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Complex{
	public:
		Complex();
		Complex(double r, double i){
			real = r;
			imag = i;
		}
		Complex(double r){
			real = r;
			imag = 0;   
		}
		operator double(){
			return real;
		}

	private:
		double real;
		double imag;
};


int main(){
	Complex c(52.3, 23);
	double d = 23.8;
	cout << d+c <<endl;
	return 0;	
}
