/*************************************************************************
	> File Name: xt16_9.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Mar 22 14:10:22 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename Init, typename T>
Init findElem(Init first, Init last, const T& val){
	while(first != last){
		if(*first == val){
			return first;
		}
		++first;
	}
	return last;
}

int main(){
	int ia[] = {
		1,2,3,4,5,6,7
	};
	string sa[] = {
		"this" , "is" , "mary" , "test" , "example"
	};

	vector<int> ivec(ia,ia+7);
	vector<string> svec(sa,sa+5);

	vector<int>::iterator iit;
	if((iit = findElem(ivec.begin(),ivec.end(),6)) != ivec.end()){
		cout << "6 is find in ivec , located in " << *iit <<endl;
	}else{
		cout << "no 6 element" <<endl;
	}

	vector<string>::iterator sit;
	if((sit = findElem(svec.begin(),svec.end(),"she")) != svec.end()){
		cout << "string 'she' is located in " << *sit <<endl;
	}else{
		cout << "NO string 'she' " <<endl;
	}

	return 0;
}
