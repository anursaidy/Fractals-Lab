#include <math.h>
#include "Complex.hpp"
#include <iostream>
using namespace std;

//Destrcutor
Complex::~Complex() {};


//No arg constructor
Complex::Complex() :imag(0.0), real(0.0) {};


//Copy Constrcutor
Complex::Complex(const Complex& copy){
	imag = copy.imag;
	real = copy.real;
};
//Two arg constructor
Complex::Complex(double r, double i) : real(r), imag(i) {};


// Overloading [] operator, returning the corresponding part of the object. 
double& Complex:: operator [] (const char* index) {
	if (strcmp(index, "real") == 0)
		return real;
	else if (strcmp(index, "imag") == 0) {
		return imag;
	}
	else {
		cout << "Invalid Index";
		exit(1);
	}
};

const Complex operator* (const Complex& A, const Complex& B)
{
	double r, i;

	r = (A.real * B.real) - (A.imag * B.imag);
	i= (A.real * B.imag) + (A.imag * B.real);
	return Complex(r, i);
}

//Friend overloading operator + / Just adding real part and imag part
const Complex operator+ (const Complex& A, const Complex& B)
{
	double real, imag;
	real = A.real + B.real;
	imag = A.imag + B.imag;

	return Complex(real, imag);
}


double getMagnitudeSquared(const Complex& A)
{	
	return ((A.real * A.real) + (A.imag * A.imag));
}
