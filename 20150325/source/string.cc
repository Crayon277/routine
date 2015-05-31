/*************************************************************************
	> File Name: string.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Fri Mar 27 19:58:00 2015
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
	string str("chenye");
	
	cout << "length" << str.length() <<endl;;
	cout << "size "  << str.size() << endl;
	cout << "max_size" <<str.max_size()<<endl;
	// cout << "capacity" <<str.capacity <<endl;
	// cout << "if empty" <<str.empty() <<endl;
	// char c = str.at(2);
	cout << "at " << str.at(2) <<endl;
	// cout << "append " << str.append(" love 77") << endl;
	str.clear();		
	if(str.empty()){
		str.append(" love 77");
		string::iterator isvec = str.begin();
		for(;isvec != str.end(); isvec++){
			cout << *isvec << endl;
		}
		// str.clear();
		// cout << "clear" << str <<endl;
	}
	

	
	return 0;
}
