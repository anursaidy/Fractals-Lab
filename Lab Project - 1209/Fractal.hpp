#ifndef FRACTAL_HPP_
#define FRACTAL_HPP_
#include "Pixel.hpp"
#include "Complex.hpp"

class Fractal {
private:
	unsigned int cols;
	Pixel** grid;
	unsigned int maxIter;
	unsigned int rows;
	char type;

	unsigned int determinePixelColor(Complex, Complex);
	void makeJuliaFractal();
	void makeMandelbrotFractal();
public:
	~Fractal();
	Fractal();
	Fractal(const Fractal&);
	Fractal(Fractal&&);
	Fractal(unsigned int, unsigned int, char);
	const Fractal& operator=(const Fractal&);
	Fractal& operator=(Fractal&&);

	friend void saveToPPM(const Fractal&, const char*);
};
Pixel convertToPixel(unsigned int);
#endif