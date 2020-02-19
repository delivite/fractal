/*
 * RGB.h
 *
 *  Created on: 30 Jan 2020
 *      Author: Samuel Chinedu
 */

#ifndef RGB_H_
#define RGB_H_

struct RGB {

	double r, g, b;
	RGB(double r, double g, double b);


};

RGB operator-(const RGB &first, const RGB &second);

#endif /* RGB_H_ */
