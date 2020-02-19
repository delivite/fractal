/*
 * RGB.cpp
 *
 *  Created on: 30 Jan 2020
 *      Author: Samuel Chinedu
 */

#include "RGB.h"

RGB::RGB(double r, double g, double b) :
		r{r}, g{g}, b{b} {
	// TODO Auto-generated constructor stub

}

RGB operator-(const RGB &first, const RGB &second) {

	return RGB(first.r - second.r, first.g - second.g, first.b - second.b);
}

