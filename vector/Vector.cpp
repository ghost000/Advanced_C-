//
// Created by neo on 17/10/17.
//
#include <iostream>
#include <algorithm>

template<typename T, size_t n = 10, T default_value = 0>
class VectorM {
public:

    using value_type = T;

    VectorM(): count(n) {
        std::fill(std::begin(tab),std::end(tab), default_value);
    }

    ~VectorM() {}

    const size_t size() const { return this->count; }

    value_type& operator[](const size_t i) { return tab[i]; };

    const value_type& operator[](const size_t i) const { return tab[i]; };

    value_type& operator=(const value_type& N){
        *this = &N;
        return *this;
    };


private:
    size_t count;
    value_type tab[n] {};
};

template <typename T, typename N>
inline bool operator==(const T & lhs, const N & rhs) {
    return (lhs.size() ==  rhs.size());
};

template <typename T, typename N>
typename T::value_type operator*(const T & lhs, const N & rhs){
    typename T::value_type result = 0;
    if( rhs.size() == lhs.size() ){
        for(auto i = 0; i < rhs.size(); i++){
            result += ( ( typename T::value_type ) ( lhs[i] * rhs[i] ) );
        }
    }
    return result;
};