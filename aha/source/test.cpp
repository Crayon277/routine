#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	//cout << " hello world " <<endl;
	int *p1 = (int *)std::calloc(4,sizeof(int));
	int *p2 = (int *)std::calloc(1,sizeof(int[4]));
	int *p3 = (int *)std::calloc(4,sizeof *p3);
	std::cout << sizeof(int[4]) << std::endl;

	if(p2){
		for(int n = 0;n<4;++n){
			std::cout <<"p2[" <<n<<"] == " <<p2[n] << '\n';
		}
	}
	std::cout << "Hello world"[1] << std::endl;
	std::free(p1);
	std::free(p2);
	std::free(p3);


	return 0;
}