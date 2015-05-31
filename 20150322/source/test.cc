/*************************************************************************
	> File Name: test.cc
	> Author: Crayon Chaney
	> Mail:mmmmmcclxxvii@gmail.com
	> Created Time: Sun Mar 22 16:14:16 2015
 ************************************************************************/

#in/* clude<iostream>  */
// #include <string>

// using namespace std;

// template<class parm, class v>
// parm fcn(parm * array, v value);

/* class parm_class { */

	public:
		typedef  unsigned int  size_type;
		size_type *st_val ;
};

template <class parm, class v> //  
parm fcn(parm *array ,v value)
{
	/* array = new parm_class; */
	/* cout << "what the fuck ! " <<endl; */
	// typename parm :: size_type p = value;
	// array->st_val = &p;	
	// cout << p <<endl;
	// return *array;
} 

// int main()
{

	parm_class array;
	unsigned int v = 1;
	fcn(&array, v);
	cout << (array.st_val) << endl;
//	fcn<parm_class, unsigned int>(&array, v);
	return 0;
}
