/*
 * Zoom.h
 *
 *  Created on: 29 Jan 2020
 *      Author: Samuel Chinedu
 */

#ifndef ZOOM_H_
#define ZOOM_H_

struct Zoom {
	int x{}, y{};
	double scale{0.0};

	Zoom(int x, int y, double scale):x(x), y(y), scale(scale){

	}
};

#endif /* ZOOM_H_ */
