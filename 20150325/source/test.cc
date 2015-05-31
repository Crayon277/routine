/*************************************************************************
	> File Name: test.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Mar 27 16:57:56 2015
 ************************************************************************/

#include<iostream>
using namespace std;

string& handle(string& sval){
	string *pstr = new string(sval);
	sval = "xuqiqi";
	cout << pstr << endl;
	return *pstr;
}

string& chuli(string& sval){
	cout << "=======" <<endl;
	string *pstr = &sval;
	sval = "xuqiqi";
	cout <<"========" <<endl;
	return *pstr;
}

int& handle(int& ival){
	int* pival = &ival;
	ival = 100;
	return *pival;
}

int main(){
	string sval("chenye");
	int ival = 77;
	int refer = handle(ival);
	cout << refer <<endl;
	cout << handle(ival) <<endl;
	cout << ival <<endl;
	cout << "-------" <<endl;
	cout << chuli(sval) <<endl;
	cout <<"--------" <<endl;
	cout << sval <<endl;
	return 0;

}
