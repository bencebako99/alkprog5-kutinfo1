#include <iostream>
#include "matrix.h"
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
    //Test indexing
    {
        Matrix<double> a = {2};
        a.data = {1,2,3,4};
        if(a(0, 0)!=1 || a(0, 1)!=2 || a(1,0) != 3 || a(1,1)!=4) { cout << "Error in indexing ()" << endl;}
        if(a[0]!=1 || a[1]!=2 || a[2] != 3 || a[3]!=4) { cout << "Error in indexing []" << endl;}
    }
    //Test addition operator (l+l)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.1, 2.2, 3.3, 4.4}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = A+B;
        if(R(0,0)!=2.2 || R(0, 1)!=4.4 || R(1,0)!=6.6 || R(1,1)!=8.8) {cout << "problem in addition l+l" << endl;}
    }
    //Test addition operator (r+r)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.1, 2.2, 3.3, 4.4}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = move(A)+move(B);
        if(R(0,0)!=2.2 || R(0, 1)!=4.4 || R(1,0)!=6.6 || R(1,1)!=8.8) {cout << "problem in addition r+r" << endl;}
    }
    //Test addition operator (r+l)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.1, 2.2, 3.3, 4.4}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = move(A)+B;
        if(R(0,0)!=2.2 || R(0, 1)!=4.4 || R(1,0)!=6.6 || R(1,1)!=8.8) {cout << "problem in addition r+l" << endl;}
    }
    //Test addition operator (l+r)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.1, 2.2, 3.3, 4.4}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = A+move(B);
        if(R(0,0)!=2.2 || R(0, 1)!=4.4 || R(1,0)!=6.6 || R(1,1)!=8.8) {cout << "problem in addition l+r" << endl;}
    }
 

    //Test - operator (l-l)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.2, 2.4, 3.6, 4.8}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = A-B;
        if(R(0,0)!=1.2-1.1 || R(0, 1)!=2.4-2.2 || R(1,0)!=3.6-3.3 || R(1,1)!=4.8-4.4) {cout << "problem in l-l" << endl;}
    }
    //Test - operator (r-r)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.2, 2.4, 3.6, 4.8}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = move(A)-move(B);
        if(R(0,0)!=1.2-1.1 || R(0, 1)!=2.4-2.2 || R(1,0)!=3.6-3.3 || R(1,1)!=4.8-4.4) {cout << "problem in r-r" << endl;}
    }
    //Test - operator (r-l)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.2, 2.4, 3.6, 4.8}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = move(A)-B;
        if(R(0,0)!=1.2-1.1 || R(0, 1)!=2.4-2.2 || R(1,0)!=3.6-3.3 || R(1,1)!=4.8-4.4) {cout << "problem in r-l" << endl;}
    }
    //Test - operator (l-r)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1.2, 2.4, 3.6, 4.8}; B.data = {1.1, 2.2, 3.3, 4.4};
        Matrix<double> R = A-move(B);
        if(R(0,0)!=1.2-1.1 || R(0, 1)!=2.4-2.2 || R(1,0)!=3.6-3.3 || R(1,1)!=4.8-4.4) {cout << "problem in l-r" << endl;}
    }


    //Test * operator (l*scal)
    {
        Matrix<double> A={2}; double scal = 2.0;
        A.data = {1, 2, 3, 4};
        Matrix<double> R = A*scal;
        if(R(0,0)!=2 || R(0, 1)!=4 || R(1,0)!=6 || R(1,1)!=8) {cout << "problem in l*scal" << endl;}
    }
    //Test * operator (scal*l)
    {
        Matrix<double> A={2}; double scal = 2.0;
        A.data = {1, 2, 3, 4};
        Matrix<double> R = scal*A;
        if(R(0,0)!=2 || R(0, 1)!=4 || R(1,0)!=6 || R(1,1)!=8) {cout << "problem in l*scal" << endl;}
    }
    //Test * operator (r*scal)
    {
        Matrix<double> A={2}; double scal = 2.0;
        A.data = {1, 2, 3, 4};
        Matrix<double> R = move(A)*scal;
        if(R(0,0)!=2 || R(0, 1)!=4 || R(1,0)!=6 || R(1,1)!=8) {cout << "problem in l*scal" << endl;}
    }
    //Test * operator (scal*r)
    {
        Matrix<double> A={2}; double scal = 2.0;
        A.data = {1, 2, 3, 4};
        Matrix<double> R = scal*move(A);
        if(R(0,0)!=2 || R(0, 1)!=4 || R(1,0)!=6 || R(1,1)!=8) {cout << "problem in l*scal" << endl;}
    }


    //Test / operator (l/scal)
    {
        Matrix<double> A={2}; double scal = 2.0;
        A.data = {1, 2, 3, 4};
        Matrix<double> R = A/scal;
        if(R(0,0)!=1/2.0 || R(0, 1)!=2/2.0 || R(1,0)!=3/2.0 || R(1,1)!=4/2.0) {cout << "problem in l/scal" << endl;}
    }
    //Test / operator (r/scal)
    {
        Matrix<double> A={2}; double scal = 2.0;
        A.data = {1, 2, 3, 4};
        Matrix<double> R = move(A)/scal;
        if(R(0,0)!=1/2.0 || R(0, 1)!=2/2.0 || R(1,0)!=3/2.0 || R(1,1)!=4/2.0) {cout << "problem in l/scal" << endl;}
    }


    //Test matrix multiplication (l*l)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1, 2, 3, 4}; B.data = {1, 2, 3, 4};
        Matrix<double> R = A*B;
        if(R(0,0)!=7 || R(0, 1)!=10 || R(1,0)!=15 || R(1,1)!=22) {cout << "problem in addition l*l" << endl;}
    }
    //Test matrix multiplication (r*r)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1, 2, 3, 4}; B.data = {1, 2, 3, 4};
        Matrix<double> R = move(A)*move(B);
        if(R(0,0)!=7 || R(0, 1)!=10 || R(1,0)!=15 || R(1,1)!=22) {cout << "problem in addition r*r" << endl;}
    }
    //Test matrix multiplication (r*l)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1, 2, 3, 4}; B.data = {1, 2, 3, 4};
        Matrix<double> R = move(A)*B;
        if(R(0,0)!=7 || R(0, 1)!=10 || R(1,0)!=15 || R(1,1)!=22) {cout << "problem in addition r*r" << endl;}
    }
    //Test matrix multiplication (l*r)
    {
        Matrix<double> A={2}; Matrix<double> B={2};
        A.data = {1, 2, 3, 4}; B.data = {1, 2, 3, 4};
        Matrix<double> R = A*move(B);
        if(R(0,0)!=7 || R(0, 1)!=10 || R(1,0)!=15 || R(1,1)!=22) {cout << "problem in addition r*r" << endl;}
    }
    // Test << and >> operators
    {
        std::ifstream ifile("data.txt");
        std::ofstream ofile("data2.txt");
        std::stringstream s1;
        Matrix<double> A, B;
        if (ifile){
            s1 << ifile.rdbuf();
        }
        s1 >> A;
        s1 >> B;
        std::stringstream s2;
        s2 << A << " + \n" << B << " = \n" << A+B;
        if (ofile){
            ofile << s2.rdbuf();
        }
    }
    return 0;
}