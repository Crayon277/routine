/*************************************************************************
	> File Name: max_arr.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sat Mar 21 09:40:45 2015
 ************************************************************************/

#include<iostream>
using namespace std;

class Arr{
	public:
		void set_value();
		void max_value();
		void show_value();
	private:
		int array[10];
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
	int index;

	for(index = 0 ;index != 10; index ++){
		cin >> array[index];
	}

}

void Arr::max_value(){
	int index = 0;
	max = index;
	while( (++index) != 10){
		if(array[index] > array[max]){
			max = index;
		}
		
	}
	cout << "max:" << endl << array[max] <<endl;
}

void Arr::show_value(){
	int index = 0;
	cout << "show : " <<endl;
	while(index != 10){
		cout << array[index] << " ";
		index++;
	}
	cout << endl;
}
