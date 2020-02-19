/*
 * main.cpp
 *
 *  Created on: 23 Jan 2020
 *      Author: Samuel Chinedu
 */
#include <iostream>

#include "FractalCreator.h"
#include "Zoom.h"

int main() {

	int height = 600;

	FractalCreator fractalcreator{800, height};

	fractalcreator.addRange(0.0, RGB{0, 0, 0});
	fractalcreator.addRange(0.3, RGB{255, 0, 0});
	fractalcreator.addRange(0.5, RGB{255, 255, 0});
	fractalcreator.addRange(1.0, RGB{255, 255, 255});

	//fractalcreator.addZoom(Zoom{295, height - 202, 0.1});
	//fractalcreator.addZoom(Zoom{312, height - 304, 0.1});
	fractalcreator.run("file.bmp");

	std::cout << "Finished";

	return 0;
}

