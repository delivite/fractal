/*
 * FractalCreator.cpp
 *
 *  Created on: 29 Jan 2020
 *      Author: Samuel Chinedu
 */
#include <cassert>

#include "FractalCreator.h"

void FractalCreator::run(std::string name) {
	/*addZoom(Zoom(295, m_height - 202, 0.1));
	 addZoom(Zoom(312, m_height - 304, 0.1));*/
	calculateIterations();
	totalIterations();
	calculateRangeTotal();
	drawFractal();
	writeBitmap("file.bmp");
}

FractalCreator::FractalCreator(int width, int height) :
		m_width { width }, m_height { height }, m_histogram {
				(new int[Mandelbrot::MAX_ITERATIONS] { 0 }) }, m_fractal {
				(new int[m_width * m_height] { 0 }) }, m_bitmap { m_width,
				m_height }, m_zoomList { m_width, m_height } {
	// TODO Auto-generated constructor stub
	m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));	//4.0 / m_width
}

FractalCreator::~FractalCreator() {
	// TODO Auto-generated destructor stub
}

void FractalCreator::calculateIterations() {
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			//bitmap.setPixel(x , y , 255, 0, 0);

			std::pair<double, double> coords = m_zoomList.doZoom(x, y);

			int iterations = Mandelbrot::getIterations(coords.first,
					coords.second);

			m_fractal[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				m_histogram[iterations]++;
			}

		}

	}
}
void FractalCreator::drawFractal() {

/*	RGB startColor(0, 0, 0);
	RGB endColor(0, 0, 255);
	RGB diff = endColor - startColor;*/

	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {

			int iterations = m_fractal[y * m_width + x];

			int range = getRange(iterations);
			int rangeTotal = m_rangeTotals[range];
			int rangeStart = m_ranges[range];

			RGB &startColor = m_colors[range];
			RGB &endColor = m_colors[range + 1];

			RGB colorDiff = endColor - startColor;

			std::uint8_t red = 0;
			std::uint8_t green = 0;
			std::uint8_t blue = 0;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {

				int totalPixels { };
				for (int i = rangeStart; i <= iterations; i++) {
					totalPixels += m_histogram[i];
				}

				//green = std::pow(255, hue);

				red = startColor.r
						+ colorDiff.r * (double) totalPixels / rangeTotal;
				green = startColor.g
						+ colorDiff.g * (double) totalPixels / rangeTotal;
				blue = startColor.b
						+ colorDiff.b * (double) totalPixels / rangeTotal;

				/*red = std::pow(diff.r, hue);
				 green = std::pow(diff.g, hue);
				 blue = std::pow(diff.b, hue);*/
			}
			m_bitmap.setPixel(x, y, red, green, blue);

		}
	}

}
void FractalCreator::writeBitmap(std::string name) {
	m_bitmap.write(name);
}
void FractalCreator::addZoom(const Zoom &zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::totalIterations() {

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		m_total += m_histogram[i];
	}

	std::cout << "Overall Total2:" << m_total << std::endl;
}

void FractalCreator::addRange(double rangeEnd, const RGB &rgb) {
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);

	if (m_bGotFirstRange) {
		m_rangeTotals.push_back(0);
	}

	m_bGotFirstRange = true;

}

void FractalCreator::calculateRangeTotal() {

	int rangeIndex { 0 };

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		int pixels = m_histogram[i];

		if (i >= m_ranges[rangeIndex + 1]) {
			rangeIndex++;
		}

		m_rangeTotals[rangeIndex] += pixels;
	}
	int overallTotal { 0 };

	for (int value : m_rangeTotals) {
		std::cout << "Range total: " << value << std::endl;
		overallTotal += value;
	}

	std::cout << "Overall Total1:" << m_total << std::endl;
}

int FractalCreator::getRange(int iterations) const {
	int range { 0 };

	for (int i = 1; i < m_ranges.size(); i++) {
		range = i;

		if (m_ranges[i] > iterations) {
			break;
		}
	}

	range--;

	assert(range > -1);
	assert(range < m_ranges.size());

	return range;
}

