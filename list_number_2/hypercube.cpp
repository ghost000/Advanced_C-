#include <iostream>

template<int Length, int Dimension>
class HyperCube{
	public:
		enum{ VALUE = Length * HyperCube< Length, Dimension - 1 >::VALUE };
};

template<int Length>
class HyperCube< Length, 1 >{
	public: 
		enum{ VALUE = Length };
};


int main(int argv, char * argc[]){

	std::cout << HyperCube<10,5>::VALUE << std::endl;
	return 0;
}
