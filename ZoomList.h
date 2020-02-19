/*
 * ZoomList.h
 *
 *  Created on: 29 Jan 2020
 *      Author: Samuel Chinedu
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>

#include "Zoom.h"

class ZoomList {
	double m_xCenter{}, m_yCenter{}, m_scale{1.0};
	int m_width{}, m_height{};
	std::vector<Zoom> zooms;
public:
	ZoomList(int width, int height);
	void add(const Zoom &zoom);
	std::pair<double, double> doZoom(int x, int y);
};

#endif /* ZOOMLIST_H_ */
