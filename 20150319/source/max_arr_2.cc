/*************************************************************************
	> File Name: max_arr_2.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 09:53:22 2015
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class Arr{
	public:
		void show_value();
		void set_value();
		void max_value();

	private:
		vector<int> ival;
		//vector<int>::size_type index;
		int max;
};

int main(){
	Arr arr;
	arr.set_value();
	arr.show_value();
	arr.max_value();

	return 0;
}

void Arr::set_value(){
	int iva;
	vector<int>::size_type index=0;
	int flag = 1;
	cout << "max without init : " << max <<endl;
	while(cin >> iva) {
		if(flag){
			max = iva;
			flag = 0;
		}
		ival[index++] = iva;
		if(iva > max){
			max = iva;
		}
	}
}

void Arr::show_value(){
	cout << "show : " <<endl; 
	for(vector<int>::size_type index = 0 ;index != ival.size(); index ++){
		cout << ival[index] << " " ;
	}
	cout <<  endl;
	
}

void Arr::max_value(){
	cout << "max :" <<endl << max <<endl;
}

