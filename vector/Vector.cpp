//
// Created by neo on 17/10/17.
//
#include <iostream>
#include <algorithm>


template<typename T, size_t n, T default_value = 0>
class VectorM {
public:

    using value_type = T;

    VectorM(): count(n) {
        std::fill(std::begin(tab),std::end(tab), default_value);
    }

    ~VectorM() {}

    size_t size() { return count; }

    value_type& operator[](size_t i) { return tab[i]; };

    //const value_type& operator[](const size_t i) { return tab[i]; };

    value_type& operator=(const value_type& N){
        *this = &N;
        return *this;
    };


private:
    size_t count;
    value_type tab[n] {};
};