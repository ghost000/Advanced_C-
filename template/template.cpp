#include <iostream>

template<typename T, typename N>
auto add(const T &a, const N &b) -> decltype(a+b){
	return a+b;
}

template<typename T, typename N, typename Op>
auto add2(const T &a, const N &b, const Op &o) -> decltype(o(a,b)){
	return o(a,b);
}

template<typename T, typename N>
class add_functor{
public:
	add_functor() = default;
	add_functor(const T &a, const N &b): a(a), b(b) {}
	auto operator()(T a, N b) const -> decltype( a+b ){
		return a+b;	
	}

private:
	T a;
	N b;
};

int main(int argc, char * argv[]){
	
	std::cout << add(1,2.3) << std::endl;
	std::cout << add(std::string("test"), std::string(" string")) << std::endl;
	std::cout << add2(1,2.333,add<double,double>) << std::endl;
	std::cout << add2(1,2.333, [&] (auto a, auto b) -> decltype(a+b) { 
				return a + b;
			}) << std::endl;
	add_functor<double, double> functor;
	std::cout << add2(1,2.333,functor) << std::endl;

	return 0;
}
