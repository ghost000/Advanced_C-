#include <string.h> 
#include <iostream>

//tutat z <T*,N*> po nazwie funkcji nie działało 
template<typename T, typename N>
auto add(T* const & a, N* const b) -> decltype(*a+*b){
	return *a+*b;
}

//template<> ponieważ specjalizacja nie działa musi być przeciążenie, <const char *> też mi nie dzialało 
std::string add1( const char* const & a, const char * const & b)
{
	std::string buff1 (a , strlen(a));
	std::string buff2 (b , strlen(b));
	return buff1 + buff2;
}

int main(int argc, char *argv[]){
	
	const char* a = "aaaaaaaa";
	const char* b = "bbbbbbb";
	int test1 = 100;
	int test2 = 1;
	int * test1_ptr = &test1;
	int * test2_ptr = &test2; 
	std::cout << add1(a,b) << std::endl;
	std::cout << add(test1_ptr, test2_ptr) << std::endl;
	return 0;
}
