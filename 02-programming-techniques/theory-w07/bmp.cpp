#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "bmp.h"

using namespace std;

bool isBMP(FILE* f) {
	if (f == NULL)
		return false;
	char sign[2];
	fseek(f, 0, SEEK_SET);
	fread(sign, sizeof(sign), 1, f);
	return sign[0] == 'B' && sign[1] == 'M';
}

void readBMPHeader(FILE* f, BMPFile& bmp) {
	if (f == NULL)
		return;
	fseek(f, 0, SEEK_SET);
	fread(&bmp.header, 14, 1, f);
}

void readBMPDIB(FILE* f, BMPFile& bmp) {
	if (f == NULL)
		return;
	fseek(f, 14, SEEK_SET);
	fread(&bmp.dib, 40, 1, f);
}

void readBMPColorTable(FILE* f, BMPFile& bmp) {
	if (f == NULL)
		return;
	fseek(f, 54, SEEK_SET);
	fread(&bmp.colorTable, sizeof(ColorTable), 1, f);
}

void readBMPPixelArray(FILE* f, BMPFile& bmp) {
	if (f == NULL)
		return;
	uint32_t width = bmp.dib.width * (bmp.dib.colorDepth / 8);
	bmp.pixelArray.paddingSize = (4 - (width % 4)) % 4;
	bmp.pixelArray.lineSize = width + bmp.pixelArray.paddingSize;
	bmp.dib.pixelArraySize = bmp.pixelArray.lineSize * bmp.dib.height;
	bmp.pixelArray.RAWData = new unsigned char[bmp.dib.pixelArraySize];
	fseek(f, bmp.header.offset, SEEK_SET);
	fread(bmp.pixelArray.RAWData, bmp.dib.pixelArraySize, 1, f);
}

void readBMP(FILE* f, BMPFile& bmp) {
	if (f != NULL) {
		readBMPHeader(f, bmp);
		readBMPDIB(f, bmp);
		readBMPPixelArray(f, bmp);
	}
}

void writeBMP(char* fileName, BMPFile& bmp) {
	FILE* f = fopen(fileName, "wb");
	if (f != NULL) {
		fwrite(&bmp.header, 14, 1, f);
		fwrite(&bmp.dib, 40, 1, f);
		fseek(f, bmp.header.offset, SEEK_SET);
		fwrite(bmp.pixelArray.RAWData, bmp.dib.pixelArraySize, 1, f);
		fclose(f);
		cout << "Write successfully!   " << fileName << endl;
	}
	else
		cout << "Error when write file!" << fileName << endl;
}

void parseArgv(int argc, char** argv, char* filename, int &h, int &w){
	// <program> <fileBMP> [-h <soPhanCatDoc>] [-w <soPhanCatNgang>]
	h = 1; w = 1;
	strcpy(filename, argv[1]);

	// only -h or -w
	if (argc == 4) {
		if (argv[2][0] == '-' && argv[2][1] == 'h')
			h = atoi(argv[3]);
		else if (argv[2][0] == '-' && argv[2][1] == 'w')
			w = atoi(argv[3]);
	}
	// both -h and -w
	else if (argc == 6) {
		if (argv[2][0] == '-' && argv[2][1] == 'h' && argv[4][0] == '-' && argv[4][1] == 'w') {
			h = atoi(argv[3]);
			w = atoi(argv[5]);
		}
		else if (argv[2][0] == '-' && argv[2][1] == 'w' && argv[4][0] == '-' && argv[4][1] == 'h') {
			w = atoi(argv[3]);
			h = atoi(argv[5]);
		}
	}
}

void printInfo(BMPFile& bmp) {
	cout << "GENERAL INFORMATION:" << endl;
	cout << "Signature:          " << bmp.header.signature[0] << bmp.header.signature[1] << endl;
	cout << "Header Size:        " << 14 << endl;
	cout << "DIB Size:           " << bmp.dib.DIBSize << endl;
	cout << "Pixel Array Offset: " << bmp.header.offset << endl;
	cout << "Pixel Array Size:   " << bmp.dib.pixelArraySize << endl;
	cout << "Total Image Size:   " << bmp.header.imgSize << endl;	
	cout << "Image Width:        " << bmp.dib.width << endl;
	cout << "Image Height:       " << bmp.dib.height << endl;	
	cout << "Color Depth:        " << bmp.dib.colorDepth << " bit" << endl;
	cout << "Compression:        " << bmp.dib.compression << endl;
	cout << "\n";
}

void positionCalculate(BMPFile& bmp, int h, int w, int* subHeight, int* subWidth, int* posRow, int* posCol) {
	int height = bmp.dib.height;
	int width = bmp.dib.width;
	for (int i = 0; i < h; ++i)
		subHeight[i] = height/h + ((i + 1) <= (height % h));
	for (int i = 0; i < w; ++i)
		subWidth[i] = width/w + ((i + 1) <= (width % w));
	posRow[0] = 0;
	posCol[0] = 0;
	for (int i = 1; i < h; ++i)
		posRow[i] = posRow[i - 1] + subHeight[i - 1];
	for (int i = 1; i < w; ++i)
		posCol[i] = posCol[i - 1] + 3*subWidth[i - 1]; // posCol tinh gap 3 lan width
}

void generateFileName(char fileName[], char subName[], int i, int j) {
	strcpy(subName, fileName);
	// Remove file extension
	for (int k = (int)strlen(subName) - 1; k >= 0; --k)
		if (subName[k] == '.') {
			subName[k] = '\0';
			break;
	}

	char extension[100];
	sprintf(extension,"_%d_%d.bmp", i+1, j+1);			
	// Make full subName
	strcat(subName, extension);
}

void splitBMP(BMPFile& bmp, int h, int w, int* subHeight, int* subWidth, int* posRow, int* posCol, char fileName[]) {
	for(int i = 0 ; i <h ; ++i)
		for (int j = 0; j < w; ++j) {
			BMPFile curImg;
			// Khoi tao cac thong so cho Header va DIB
			curImg.header = bmp.header;
			curImg.dib = bmp.dib;
			curImg.colorTable = bmp.colorTable;

			// Cap nhat thong so Header va DIB
			// imgSize cap nhat sau
			curImg.dib.width = subWidth[j];
			curImg.dib.height = subHeight[i];
			curImg.dib.pixelArraySize = curImg.dib.width * curImg.dib.height * 3;

			// Cap nhat thong so Pixel Array
			int curWidth = curImg.dib.width * 3;
			int curHeight = curImg.dib.height;

			curImg.pixelArray.paddingSize = (4 - (curWidth % 4)) % 4;
			curImg.pixelArray.lineSize = curWidth + curImg.pixelArray.paddingSize;
			curImg.dib.pixelArraySize = curImg.pixelArray.lineSize * curImg.dib.height;
			curImg.header.imgSize = curImg.header.offset + curImg.dib.pixelArraySize; // Cap nhat imgSize
			curImg.pixelArray.RAWData = new unsigned char[curImg.dib.pixelArraySize]{};
			
			for(int k = 0; k < curHeight; ++k)
				for (int L = 0; L < curWidth; ++L) {
					int idxCur = k * (int)curImg.pixelArray.lineSize + L; 
					int idxSrc = (posRow[i] + k) * bmp.pixelArray.lineSize + posCol[j] + L ;
					curImg.pixelArray.RAWData[idxCur] = bmp.pixelArray.RAWData[idxSrc];
				}
			// Phat sinh ten file va ghi file
			char subName[100];
			// File name danh so tu duoi len
			generateFileName(fileName, subName, h - 1 - i, j);
			// Ghi file bmp boi ten file phat sinh
			writeBMP(subName, curImg);
			delete[] curImg.pixelArray.RAWData;
		}
}

void freeMem(BMPFile& bmp) {
	delete[]bmp.pixelArray.RAWData;
	// 
}
