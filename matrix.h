#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <initializer_list>
#include <cmath>
#include <ostream>


template <typename T>

struct Matrix
{
    int N;
    std::vector<T> data;

    //Subscription operator
    T& operator()(int i, int j) {return data[(i*N)+j]; }
    T const& operator() (int i, int j) const {return data[(i*N)+j]; }
    //Function call operator
    T& operator[](int i) {return data[i];}
    T const& operator[] (int i) const {return data[i]; }
};