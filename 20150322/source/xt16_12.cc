/*************************************************************************
	> File Name: xt16_12.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Mar 22 14:58:04 2015
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<typename Type>
typename Type::value_type find_fre(Type first, Type last){
	std::size_t amount = 0;
	Type start = first;

	while(start != last){
		amount ++ ;
		start ++;
	}

	typedef std::vector<typename Type::value_type> VecType;

	VecType vec(amount);

	VecType::iterator newFirst = vec.begin();
	VecType::iterator newLast = vec.end();

	std::uninitialized_copy(first, last, newFirst);
	
	std::sort(newFirst, newLast);
	
	std::size_t maxOccu = 0,occu = 0;
	VecType::iterator preIter = newFirst;
	VecType::iterator maxOccuElemit = newFirst;

	while(newFirst != newLast){
		if(*newFirst != *preIter){
			if(occu > maxOccu){
				maxOccu = occu;
				maxOccuElemit = preIter;
			}
			occu = 0;
		}
		++occu;
		preIter = newFirst;
		++newFirst;
	}
	if(occu > maxOccu){
		maxOccu = occu;
		maxOccuElemit = preIter;
	}

	return *maxOccuElemit;
}
