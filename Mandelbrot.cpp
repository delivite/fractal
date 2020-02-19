/*
 * Mandelbrot.cpp
 *
 *  Created on: 27 Jan 2020
 *      Author: Samuel Chinedu
 */
#include <complex>
#include "Mandelbrot.h"

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}

int Mandelbrot::getIterations(double x, double y){

	std::complex<double> z = 0;
	std::complex<double>c(x,y);

	int iterations{};

	while (iterations<MAX_ITERATIONS){
		z = z * z + c;

		if(std::abs(z)>2){
			break;
		}

		iterations++;
	}
	return iterations;
}

