/*************************************************************************
	> File Name: cir.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Thu Mar 19 22:26:51 2015
 ************************************************************************/

#include<iostream>
using namespace std;

const float PI = 3.1416;
float fCir_L(float);
float fCir_S(float);

int main(){
	float r,l,s;

	cout << "R = ";
	cin >> r;

	l = fCir_L(r);
	s = fCir_S(r);

	cout << "l = " << l <<endl;
	cout << "s = " << s <<endl;
}

float fCir_L(float r){
	return 2*PI*r;
}
// consider negetive !!

float fCir_S(float r){
	return PI*r*r;
}


