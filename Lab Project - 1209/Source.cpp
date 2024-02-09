#include "Complex.hpp"
#include "Pixel.hpp"
#include "Fractal.hpp"

Fractal testMoveConstructor(unsigned int r, unsigned int c, char t) {
	Fractal temp(r, c, t);
	return temp;
}

int main()
{
	Fractal m1(768U, 1024U, 'm'), j1(768U, 1024U, 'j'), m2, j2;
	saveToPPM(m1, "mandelbrot.ppm");
	saveToPPM(j1, "julia.ppm");

	m2 = Fractal(m1);
	j2 = testMoveConstructor(600U, 800U, 'j');

	saveToPPM(j2, "julia_2.ppm");
	return 0;

}