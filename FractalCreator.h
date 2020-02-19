/*
 * FractalCreator.h
 *
 *  Created on: 29 Jan 2020
 *      Author: Samuel Chinedu
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <iostream>
#include <string>
#include <memory>
#include <cmath>
#include <cstdint>
#include <vector>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "RGB.h"

class FractalCreator {
	int m_width, m_height;
	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	int m_total { };

	std::vector<int> m_ranges;
	std::vector<RGB> m_colors;
	std::vector<int> m_rangeTotals;

	bool m_bGotFirstRange{false};

public:
	FractalCreator(int width, int height);
	~FractalCreator();
	void run(std::string name);
	void addZoom(const Zoom &zoom);
	void addRange(double rangeEnd, const RGB &rgb);

private:
	void calculateIterations();
	void drawFractal();
	void writeBitmap(std::string name);
	void calculateRangeTotal();
	void totalIterations();
	int getRange(int iterations)const;
};

#endif /* FRACTALCREATOR_H_ */
