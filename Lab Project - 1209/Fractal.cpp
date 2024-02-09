#include "Fractal.hpp"
#include <iostream>
using namespace std;

Fractal::~Fractal() {
	cout << "> Destructor called" << endl;
	for (unsigned int i = 0; i < rows; i++)
	{
		delete[] grid[i];
		grid[i] = nullptr;

	}
	delete[] grid;
	grid = nullptr;
}
unsigned int Fractal::determinePixelColor(Complex z, Complex c) {
	double lengthSquared;
	int iter = 0;

	while (iter < maxIter) {
		iter = iter + 1;
		z = z * z;
		z = z + c;

		lengthSquared = getMagnitudeSquared(z);
		if (lengthSquared > 4.0) {
			return iter;
		}
	}
	return maxIter;
}
Fractal::Fractal() : rows(0), cols(0), type(NULL), maxIter(0), grid(nullptr) {
	cout << "> Default constructor called..." << endl;
}

Fractal::Fractal(const Fractal& copy) {
	cout << "> Copy constructor called..." << endl;
	cols = copy.cols;
	rows = copy.rows;
	maxIter = copy.maxIter;
	type = copy.type;

	grid = new Pixel * [rows];

	for (int i = 0; i < rows; i++)
	{
		grid[i] = new Pixel[cols];
	}



	for (unsigned int i = 0; i < rows; i++) {
		for (unsigned int j = 0; j < cols; j++) {
			grid[i][j] = copy.grid[i][j];
		}
	}

}
Fractal::Fractal(Fractal&& temp) :rows(temp.rows), cols(temp.cols), type(temp.type), maxIter(temp.maxIter), grid(temp.grid) {
	cout << "> Move constructor called..." << endl;
	temp.rows = 0;
	temp.cols = 0;
	temp.maxIter = 0;
	temp.type = NULL;

	temp.grid = nullptr;
}
Fractal::Fractal(unsigned int r, unsigned int c, char t) : rows(r), cols(c), type(t), maxIter(512) {
	cout << "> 3-arg constructor called..." << endl;
	grid = new Pixel * [rows];
	for (unsigned int i = 0; i < rows; i++)
	{
		grid[i] = new Pixel[cols];
	}

	if (type == 'm') {
		makeMandelbrotFractal();
	}
	else if (type == 'j') {
		makeJuliaFractal();
	}
	else {
		cout << "Invalid type" << endl;
		exit(1);
	}


}
void Fractal::makeJuliaFractal() {
	cout << "> Now creating the Julia patterns..." << endl;
	Complex z, c;

	double step_height = 4.0 / double(rows);
	double step_width = 4.0 / double(cols);

	unsigned int color;

	for (unsigned int j = 0; j < rows; j++) {
		for (unsigned int k = 0; k < cols; k++) {

			z["real"] = ((double)j * step_height) - 2.0;
			z["imag"] = ((double)k * step_width) - 2.0;

			c["real"] = -0.8;
			c["imag"] = 0.156;

			color = determinePixelColor(z, c);
			grid[j][k] = convertToPixel(color);
		}
	}
}
void Fractal::makeMandelbrotFractal() {
	cout << "> Now creating the Mandelbrot patterns..." << endl;
	Complex z, c;

	double step_height = 4.0 / double(rows);
	double step_width = 4.0 / double(cols);

	unsigned int color;

	for (unsigned int j = 0; j < rows; j++) {
		for (unsigned int k = 0; k < cols; k++) {

			z["imag"] = 0.0;
			z["real"] = 0.0;

			c["real"] = ((double)j * step_height) - 2.0;
			c["imag"] = ((double)k * step_width) - 2.0;

			color = determinePixelColor(z, c);
			grid[j][k] = convertToPixel(color);
		}
	}
}
const Fractal& Fractal::operator=(const Fractal& copy) {
	cout << "> Assignment operator called..." << endl;
	if (this != &copy) {
		if (grid != nullptr) {
			for (unsigned int i = 0; i < rows; i++)
			{
				delete[] grid[i];
				grid[i] = nullptr;

			}
			delete[] grid;
			grid = nullptr;
		}
		grid = new Pixel * [rows];
		for (unsigned int i = 0; i < rows; i++)
		{
			grid[i] = new Pixel[cols];
		}

		cols = copy.cols;
		rows = copy.rows;
		maxIter = copy.maxIter;
		type = copy.type;
	}
	return *this;
}
Fractal& Fractal::operator=(Fractal&& right) {
	cout << "> Move assignment operator called..." << endl;
	if (this != &right) {
		swap(rows, right.rows);
		swap(cols, right.cols);
		swap(type, right.type);
		swap(maxIter, right.maxIter);
		swap(grid, right.grid);
	}
	return *this;
}
void saveToPPM(const Fractal& f, const char* fn) {
	cout << "> Saving Fractal object to ASCII file..." << endl;

	ofstream outfile(fn);

	outfile << "P3" << endl; //Magic Number

	outfile << "# Fractal" << endl;  //Comment

	outfile << f.cols << " " << f.rows << "\n" << 7 << endl;

	for (unsigned int i = 0; i < f.rows; i++)
	{
		for (unsigned int j = 0; j < f.cols; j++)
		{
			outfile << f.grid[i][j];
		}
	}

}

Pixel convertToPixel(unsigned int color) {
	unsigned int red, green, blue;
	red = (color / 64) % 8;
	green = (color / 8) % 8;
	blue = color % 8;

	return Pixel(red, green, blue);
}