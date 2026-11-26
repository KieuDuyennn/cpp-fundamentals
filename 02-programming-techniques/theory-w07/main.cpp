#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdint.h>
#include "bmp.h"

using namespace std;

int main(int argc, char** argv) {
	int h = 1, w = 1;	
	char fileName[100]{};
	int subHeight[100],subWidth[100],posRow[100],posCol[100];
	if (argc != 4 && argc != 6) {
		cout << "The parameters are not valid!" << endl;
		cout << "TUTORIAL:" << endl << "BMP_split.exe <file name> -h <param h> -w <param w>" << endl;
		return 1;
	}

	parseArgv(argc, argv, fileName, h, w);
	if (h < 1 || h > 100 || w < 1 || w > 100) {
		cout << "h and w must be between 1 and 100" << endl;
		return 1;
	}
	cout << "ARGUMENTS PARSE:" << endl;
	cout << "Filename = " <<  fileName << endl;
	cout << "h = " << h << "   w = " << w << "\n\n";

	FILE* f = fopen(fileName, "rb");
	if (f == NULL) {
		cout << "File not found!" << fileName << endl;
		return 1;
	}

	if (!isBMP(f)) {
		cout << "Not a BMP file: " << fileName << endl;
		fclose(f);
		return 1;
	}

	BMPFile bmp;
	readBMP(f, bmp);
	fclose(f);
	if (bmp.dib.colorDepth != 24 || bmp.dib.compression != 0) {
		cout << "Only uncompressed 24-bit BMP files are supported" << endl;
		freeMem(bmp);
		return 1;
	}
	if (h > bmp.dib.height || w > bmp.dib.width) {
		cout << "Cannot split the image into more parts than it has pixels" << endl;
		freeMem(bmp);
		return 1;
	}
	printInfo(bmp);	
	positionCalculate(bmp, h, w, subHeight, subWidth, posRow, posCol);
	splitBMP(bmp, h, w, subHeight, subWidth, posRow, posCol, fileName);
	freeMem(bmp);	
	return 0;
}
