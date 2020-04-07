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

//Addition operators 4 versions for all combinations of const& and &&:
template <typename T>
Matrix<T> operator+(Matrix<T> const& A, Matrix<T> const& B){
    Matrix<T> result; result.data.resize(A.N);
    result.N = A.N;
    for(int i=0; i<A.N; i++){
        for(int j=0; j<A.N; j++)
            result.data[i*result.N+j]=A.data[i*A.N+j]+B.data[i*A.N+j];
    }
    return result;
}
template <typename T>
Matrix<T>&& operator+(Matrix<T> && A, Matrix<T> && B){
    Matrix<T> result; result.data.resize(A.N);
    result.N = A.N;
    for(int i=0; i<A.N; i++){
        for(int j=0; j<A.N; j++)
            result.data[i*result.N+j]=A.data[i*A.N+j]+B.data[i*A.N+j];
    }
    return result;
}
