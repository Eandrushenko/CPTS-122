#include "complex.h"

Complex::Complex(double real, double imaginary)
{
	mReal = real;
	mImaginary = imaginary;
}

void Complex::setReal(double newReal)
{
	mReal = newReal;
}

void Complex::setImaginary(double newImaginary)
{
	mImaginary = newImaginary;
}

double Complex::getReal()
{
	return mReal;
}

double Complex::getImaginary()
{
	return mImaginary;
}

Complex::Complex(Complex &copy)
{
	setReal(copy.getReal());
	setImaginary(copy.getImaginary());
}

Complex & Complex::operator=(Complex &rhs)
{
	if (this != &rhs)
	{
		mReal = rhs.getReal();
		mImaginary = rhs.getImaginary();
	}

	return *this;
}

Complex operator+(Complex &lhs, Complex &rhs)
{
	Complex temp;
	temp.setReal(rhs.getReal() + lhs.getReal());
	temp.setImaginary(rhs.getImaginary() + lhs.getImaginary());
	return temp;
}

Complex operator-(Complex &lhs, Complex &rhs)
{
	Complex temp;
	temp.setReal(rhs.getReal() - lhs.getReal());
	temp.setImaginary(rhs.getImaginary() - lhs.getImaginary());
	return temp;
}

istream & operator>>(istream &lhs, Complex &rhs)
{
	char discard;
	int num;
	lhs >> num;
	rhs.setReal(num);
	lhs >> discard;
	lhs >> num;
	rhs.setImaginary(num);
	lhs >> discard;

	return lhs;
}

ostream & operator<<(ostream &lhs, Complex &rhs)
{
	lhs << rhs.getReal() << " + " << rhs.getImaginary() << "i";
	return lhs;
}

Complex::~Complex()
{

}