#include<iostream>

class person{
	private:
		mutable std::string name;
		std::string addr;
	public:
		person():name(NULL),addr(NULL){}

		std::string get_name() const {return name;}
		std::string get_addr() const {return addr;}
		
		 void const set_info()  {
			std::cout << "set info" << std::endl;
			std::cin >> person::name >> person::addr;
			//fun set_info is const type, that is , we can't change the class member;
		}

		void set_name(const std::string& na) const{
			name = na;
		}

};


int main(){
	//constant variable
	//
	
	int ival = 1;
	const int a = 2;
	std::cout << "a : " <<a << std::endl;
	const int* pi2 = &a;
	int * pii = (int *)pi2;
	*pii = 4;
	std::cout <<"after: "<< a <<std::endl;

	//a = 2; a must initialized when it's declared.
	//a = 3;  error ! a is read_only 
	int & irefer = ival;
	// int & irefer_2 = a ; //error ! const int a can be only referenced by const int & ;
	const int & irefer_3 = a; //this is ok;
	

	const int* po = new int(10);
	int* const pi = new int(20);

	const int* pn = new int const(30);
	int* const pt = new int(40);

	const int* p1 = &ival;
	const int* p2 = &a;
	int * p3 = &ival;
	//int * p4 = &a;// a is const int type , that is , can only be pointed by const int* . 
	int * const p5 = &ival;
	//int * const p6 = &a;//error, coz it is p6 that set as const , but the pointer is normal
	//so we can use this pointer to change the object pointed , which is illegal !!!

	//*p1 = 2;	
	*p5 = 1;

	
	person man;

	const person woman;

	man.set_info();
	//woman.set_name("xuqiqi");


	return 0;	
}
