// BMP reader and splitter (24-bit BMP files)
#ifndef BMP_H
#define BMP_H

#include <cstdint>
#include <cstdio>

#pragma pack(push, 1)
// File header: 14 bytes at offset 0
struct BMPHeader {
	char signature[2];       // "BM"
	uint32_t imgSize;        // size of the whole file in bytes
	uint16_t reserved1;
	uint16_t reserved2;
	uint32_t offset;         // where the pixel array starts
};

// DIB header (BITMAPINFOHEADER): 40 bytes at offset 14
struct BMPDIB {
	uint32_t DIBSize;        // 40
	int32_t width;
	int32_t height;
	uint16_t colorPlanes;    // always 1
	uint16_t colorDepth;     // bits per pixel
	uint32_t compression;    // 0 = none
	uint32_t pixelArraySize;
	int32_t horizontalResolution;
	int32_t verticalResolution;
	uint32_t colorCount;
	uint32_t importantColorCount;
};

struct ColorTable {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
	uint8_t reserved;
};
#pragma pack(pop)

static_assert(sizeof(BMPHeader) == 14, "BMP file header must be 14 bytes");
static_assert(sizeof(BMPDIB) == 40, "DIB header must be 40 bytes");

struct PixelArray {
	unsigned char* RAWData = nullptr;
	uint32_t paddingSize = 0;  // bytes added to each row so it is a multiple of 4
	uint32_t lineSize = 0;     // bytes per row, padding included
};

struct BMPFile {
	BMPHeader header{};
	BMPDIB dib{};
	ColorTable colorTable{};
	PixelArray pixelArray;
};

bool isBMP(FILE* f);
void readBMPHeader(FILE* f, BMPFile& bmp);
void readBMPDIB(FILE* f, BMPFile& bmp);
void readBMPColorTable(FILE* f, BMPFile& bmp);
void readBMPPixelArray(FILE* f, BMPFile& bmp);
void readBMP(FILE* f, BMPFile& bmp);
void writeBMP(char* fileName, BMPFile& bmp);
void parseArgv(int argc, char** argv, char* filename, int& h, int& w);
void printInfo(BMPFile& bmp);
void positionCalculate(BMPFile& bmp, int h, int w, int* subHeight, int* subWidth, int* posRow, int* posCol);
void generateFileName(char fileName[], char subName[], int i, int j);
void splitBMP(BMPFile& bmp, int h, int w, int* subHeight, int* subWidth, int* posRow, int* posCol, char fileName[]);
void freeMem(BMPFile& bmp);

#endif
