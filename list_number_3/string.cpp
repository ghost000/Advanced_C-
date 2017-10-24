#include <cstring>
#include <algorithm>
#include <iostream>

class A
{
    char* data;

public:

    	A(const char* p)
    	{
        	size_t size = strlen(p) + 1;
        	data = new char[size];
        	memcpy(data, p, size);
    	}
	~A()
    	{
        	delete[] data;
    	}

    	A(const A& that)
    	{
        	size_t size = strlen(that.data) + 1;
        	data = new char[size];
        	memcpy(data, that.data, size);
    	}
	A(A&& that)
    	{
        	data = that.data;
        	that.data = nullptr;
    	}
	

	char* get(){ return data; }
};

int main(int argc, char *argv[]){

	A a {"test"};
	char* ch = a.get();
	for( int i = 0; i <= strlen(ch); i++)
		std::cout << ch[i] << std::endl;
	A b(a);
	//std::cout << b.data << std::endl;
	A c(std::move(b));
	//std::cout << c.data << std::endl;
	return 0;
}
