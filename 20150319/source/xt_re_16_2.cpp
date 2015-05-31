/*************************************************************************
	> File Name: xt_re_16_2.cpp
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Mar 22 07:59:31 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

template<class T1, class T2>
T1& print(T1 &s, T2 val){
	s << val;
	return s;
}

int main(){
	float fval = 12.88;
	char ca = 'a';
	string oristr = "this is a test ",desstr;
	ofstream outFile("result.txt");
	ostringstream oss;
	
	print(cout,-3) <<endl;
	print(cout,fval) <<endl;
	print(cout,ca) << endl;
	print(cout,oristr) <<endl;

	print(outFile,-3) <<endl;
	print(outFile,fval) <<endl;
	print(outFile,ca) <<endl;
	print(outFile,oristr) <<endl;

	print(oss, -3) << endl;
	print(oss, fval) <<endl;
	print(oss, ca) <<endl;
	print(oss, oristr) <<endl;

	cout << oss.str() <<endl;

	return 0;

}
