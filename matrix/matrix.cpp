#include "../std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>

using namespace Numeric_lib;

void my_sqrt(int n){

	if(n >= 0)
		cout << "sqrt(" << n << ") = " << sqrt(n) << endl;
	else	cout << "no square root" << endl;
}

int main(){

	char ch;
	cout << "char: " << sizeof(ch) << endl;

	short s;
	cout << "short: " << sizeof(s) << endl;

	int i;
	cout << "int: " <<sizeof(i) << endl;

	long l;
	cout << "long: " <<sizeof(l) << endl;

	float f;
	cout << "float: " <<sizeof(f) << endl;

	double d1;
	cout << "double: " <<sizeof(d1) << endl;

	int* i2;
	cout << "int*: " <<sizeof(i2) << endl;

	double* d2;
	cout << "double*: " <<sizeof(d2) << endl;

	Matrix<int, 1> a(10);
	cout << "Matrix<int, 1> a(10): " << sizeof(a) << endl;
	cout << "Matrix<int, 1> a(10) size: " << size(a) << endl;

	Matrix<int, 1> b(100);
	cout << "Matrix<int, 1> b(100): " << sizeof(b) << endl;
	cout << "Matrix<int, 1> b(100) size: " << size(b) << endl;

	Matrix<double, 1> c(10);
	cout << "Matrix<double, 1> c(10): " << sizeof(c) << endl;
	cout << "Matrix<double, 1> c(10) size: " << size(c) << endl;

	Matrix<int, 2> d(10, 10);
	cout << "Matrix<int, 2> d(10, 10): " << sizeof(d) << endl;
	cout << "Matrix<int, 2> d(10, 10) size: " << size(d) << endl;

	Matrix<int, 3> e(10, 10, 10);
	cout << "Matrix<int, 3> e(10, 10, 10): " << sizeof(e) << endl;
	cout << "Matrix<int, 3> e(10, 10, 10) size: " << size(e) << endl;

	int x;
	cout << "Enter numbers for sqrt(), to stop enter a negativ number:" << endl;
	while(x >= 0){
		cin >> x;
		my_sqrt(x);
	}

	//5
	Matrix<double> md(10);
    cout << "Enter 10 floating-point values:\n";
    for (int i = 0; i < 10; ++i)
    	cin >> md[i];
    cout << md << endl;

    //6
    cout << "Enter the dimensions for the table: ";
    int n, m;
    cin >> n >> m;
    cout << endl;

    Matrix<double,2> mult_table(m,n);

    for (int i = 0; i < mult_table.dim1(); ++i) {
        for (int j = 0; j < mult_table.dim2(); ++j)
            cout << setw(4) << mult_table(i,j);
        cout << endl;
    }

    //7
    Matrix<complex<double>> mcd(10);
    cout << "Enter 10 complex numbers: ";
    for(int i = 0; i < mcd.size(); ++i){
    	cin >> mcd[i];
    }

    complex<double> sum;
     for (int i = 0; i < mcd.size(); ++i)
        sum += mcd[i];
    cout << "Sum of the complex numbers: " << sum << endl;

    //8
    Matrix<int,2> matrix(2, 3);
    cout << "Enter 6 int:\n";
    for (int i = 0; i < matrix.dim1(); ++i)
        for (int j = 0; j < matrix.dim2(); ++j) 
        {
            cin >> matrix(i,j);
        }
    cout << endl;

    for (int i = 0; i < matrix.dim1(); ++i){
        for (int j = 0; j < matrix.dim2(); ++j) 
        {
            cout << setw(4) << matrix(i,j);
        }
        cout << endl;
    }
    cout << endl;

	return 0;
}