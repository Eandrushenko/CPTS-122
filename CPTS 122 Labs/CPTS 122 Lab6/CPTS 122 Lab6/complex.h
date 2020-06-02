#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

class Complex
{
	public:
		Complex(double real = 0, double imaginary = 0);

		//Constructors
		Complex(Complex &copy);

		//Destructors
		~Complex();

		//Overloaded operaters
		Complex & operator=(Complex &rhs);

		//Setters
		void setReal(double newReal);
		void setImaginary(double newImaginary);

		//Getters
		double getReal();
		double getImaginary();

	private:
		double mReal;
		double mImaginary;
};

//Nonmember Overloaded Operators
istream & operator>>(istream &lhs, Complex &rhs);

ostream & operator<<(ostream &lhs, Complex &rhs);

Complex operator-(Complex &lhs, Complex &rhs);

Complex operator+(Complex &lhs, Complex &rhs);
