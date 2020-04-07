#include <iostream>
#include "matrix.h"
using namespace std;

int main(){
    //Test indexing
    {
        Matrix<double> a = {2};
        a.data = {1,2,3,4};
        if(a(0, 0)!=1 || a(0, 1)!=2 || a(1,0) != 3 || a(1,1)!=4) { cout << "Error in indexing ()" << endl;}
        if(a[0]!=1 || a[1]!=2 || a[2] != 3 || a[3]!=4) { cout << "Error in indexing []" << endl;}
    }
    //Test addition operator
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1, 2, 3, 4}; B.data = {1, 2, 3, 4};
        Matrix<double> R = A+B;
        if(R(0,0)!=2 || R(0, 1)!=4 || R(1,0)!=6 || R(1,1)!=8) {cout << "problem in addition" << endl;}
    }
}