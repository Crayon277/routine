#include<iostream>


typedef class Screen{
	typedef std::string::size_type index;
	
	public:
		Screen():contents(NULL),current(0){}
		Screen(const std::string& cont, index& in):contents(cont),current(in){}
		void getinfo(){
			std::cout << contents << std::endl << current << std::endl;
		}	

		std::string get_contents() const{
			return contents;
		}
	
		index get_current() const{
			return current;
		}

		inline void get_per_info();

		void set_info(const std::string & cont, index in){
			contents = cont;
			current = in;
		}



	private:
		std::string contents;
		index current;	   
	
}myScreen;


int main(){
//	Screen::index a = 2;
	//Screen test("string",a);
	
	myScreen *test = new myScreen;
	(*test).getinfo();
	std::cout << test->get_contents() << " + " << test->get_current() <<std::endl;
	test->get_per_info();

	return 0;	
}



inline void Screen::get_per_info(){
	for(Screen::index i = 0 ; i != contents.size(); i++){
		if(Screen::current <= i){
			std::cout << contents[i]<<std::endl;
		}
	}
}
