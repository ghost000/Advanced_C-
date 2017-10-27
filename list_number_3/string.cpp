#include <cstring>
#include <algorithm>
#include <iostream>

class A
{
    char* data;

public:

    	A(const std::string & p)
    	{
        	size_t size = p.size();
        	data = new char[size];
        	strncpy(data, p.c_str(), size);
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
	std::cout << a.get() << std::endl;
	A b(a);
	std::cout << b.get() << std::endl;
	A c(std::move(b));
	std::cout << c.get() << std::endl;
	const std::string ss{"lolo"};
	A d(ss);
	std::cout << d.get() << std::endl;
	return 0;
}
