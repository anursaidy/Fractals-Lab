#ifndef PIXEL_HPP
#define PIXEL_HPP
#include <iostream>
#include <fstream>

using namespace std;

class Pixel {
private:
	unsigned int blue;
	unsigned int green;
	unsigned int red;
public:
	~Pixel();
	const unsigned int& operator[](const char*);
	Pixel();
	Pixel(const Pixel&);
	Pixel(unsigned int, unsigned int, unsigned int);
	friend ofstream& operator<<(ofstream&, const Pixel&); 
};

#endif