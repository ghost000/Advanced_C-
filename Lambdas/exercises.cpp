#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void exc_1() {
    std::cout << [](int x, int y) { return x < y; }(33, 44);
}

void exc_2() {
    std::vector<int> v {10, 22, 33, 1, 0};
    std::sort(v.begin(), v.end(), [](int x, int y){ return x < y; });
    for (auto item : v) {
        std::cout << item << std::endl;
    }
}

void exc_3() {
    
    std::vector<std::string> v {"Test", "string", "aBcd"};
    std::sort(v.begin(), v.end(), [](std::string x, std::string y) { return x.size() < y.size(); });
    for (auto item : v) {
        std::cout << item << std::endl;
    }


}

void exc_4() {
    std::vector<std::string> vec {"Test", "string", "aBcd"};
    std::vector<bool> booleans {};
    std::sort(vec.begin(), vec.end(), [&booleans](std::string x, std::string y) {
        auto result = x.size() < y.size();
        booleans.push_back(result);
        return result;
    });
    for (auto item : vec) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    for (auto item : booleans) {
        std::cout << item << " ";
    }
}

int main(int argv, char * argc[]){
	
	exc_1();
	exc_2();
	exc_3();
	exc_4();	
	return 0;
}
