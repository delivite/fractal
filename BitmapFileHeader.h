/*
 * BitmapFileHeader.h
 *
 *  Created on: 23 Jan 2020
 *      Author: Samuel Chinedu
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

#pragma pack(2)

struct BitmapFileHeader{
	char header[2]{'B', 'M'};
	std::int32_t fileSize;
	std::int32_t reserved{0};
	std::int32_t dataOffset;
};


#endif /* BITMAPFILEHEADER_H_ */
