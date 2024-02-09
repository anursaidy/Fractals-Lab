#include "Pixel.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//DEFAULT CONSTRUCTOR
Pixel::Pixel() :red(0), green(0), blue(0) {}

//THREE-PARAMETER CONSTRUCTOR
Pixel::Pixel(unsigned int r, unsigned int g, unsigned int b) : red(r), green(g), blue(b) {}

//COPY CONSTRUCTOR
Pixel::Pixel(const Pixel& p) {
	red = p.red;
	green = p.green;
	blue = p.blue;
}

//DESTRUCTOR
Pixel::~Pixel() {}

//OVERLOADED OPERATOR[]
const unsigned int& Pixel:: operator[](const char* index) const{
	if (strcmp(index, "red") == 0)
		return red;
	else if (strcmp(index, "green") == 0) {
		return green;
	}
	else if (strcmp(index, "blue") == 0) {
		return blue;
	}
	else {
		cout << "Invalid Index";
		exit(1);
	}
}

//OVERLOADED INSERTION OPERATOR
ofstream& operator<<(ofstream& outFile, const Pixel& p) {
	outFile << p.red << " " << p.green << " " << p.blue << " ";
	return outFile;
}