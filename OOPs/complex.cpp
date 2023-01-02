#include<iostream>
#include<math.h>
using namespace std;

class cmplx{
	float real, imag;
public:
	cmplx(){
		real = 0;
		imag = 0;
	}

	cmplx(float tempx, float tempy){
		real = tempx;
		imag = tempy;
	}

	cmplx operator + (cmplx);
	cmplx operator - (cmplx);
	cmplx operator * (cmplx);
	cmplx operator / (cmplx);

	void getdaya(){
		cout << "Enter real and imaginary part of complex number"<< endl;
		cin >> real >> imag;
	}

	void putdata(){
		cout << real << " " << imag << endl;
	}

	friend istream & operator >> (istream &, cmplx &);
	friend ostream & operator << (ostream &, cmplx &);
};

// Overloading addition operator
// return_type class_name scope_resolution operator(calling_object passed_object)
cmplx cmplx::operator + (cmplx temp1){
	cmplx temp2;
	temp2.real = real + temp1.real;
	temp2.imag = imag + temp1.imag;
	return temp2;
}

// Overloading substraction operator
cmplx cmplx::operator - (cmplx temp1){
	cmplx temp2;
	temp2.real = real - temp1.real;
	temp2.imag = imag - temp1.imag;
}

// Overloading multiplication operator
cmplx cmplx :: operator * (cmplx temp1){
	cmplx temp2;
	temp2.real = (real * temp1.real) + (imag * temp1.imag);
	temp2.imag = (real * temp1.imag) + (imag * temp1.real);
	return temp2;
}

// Overloading Division operator
cmplx cmplx::operator / (cmplx temp1){
	cmplx temp2;
	temp2.real = ((real * temp1.real) + (imag * temp1.imag))/((pow(temp1.real,2) + pow(temp1.imag,2)));
	temp2.imag = ((imag * temp1.real) - (real * temp1.imag))/((pow(temp1.real,2) + pow(temp1.imag,2)));
	return temp2;
}

// Overloading insertion Operator
istream & operator >>(istream & mycin, cmplx & t){
	cout << "Enter real and imaginary part of complex number: "<< endl;
	mycin >> t.real >> t.imag;
	return mycin;
}

// Overloading extraction operator
ostream & operator << (ostream & mycout, cmplx & t){
	mycout << t.real << " " << t.imag;
	return mycout;
}

// Main Function
int main(){
	int n;
	cmplx c3;
	cmplx c1;
	cmplx c2;
	cin >> c1;
	cin >> c2;
	do{
		cout << "Press 1 for addition" << endl;
		cout << "Press 2 for subtraction" << endl;
		cout << "Press 3 for multiplication" << endl;
		cout << "Press 4 for division" << endl;
		cin >> n;
		switch(n){
			case 1:
				c3 = c1 + c2;
				break;
			case 2:
				c3 = c1 - c2;
				break;
			case 3:
				c3 = c1 * c2;
				break;
			case 4:
				c3 = c1/c2;
				break;
			default:
				break;

		}
		cout << c3 << endl;
	}while(0 < n and n < 5);
	return 0;
}











