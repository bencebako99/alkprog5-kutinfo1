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
}