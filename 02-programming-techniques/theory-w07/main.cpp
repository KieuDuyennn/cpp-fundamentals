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
	cout << "ARGUMENTS PARSE:" << endl;
	cout << "Filename = " <<  fileName << endl;
	cout << "h = " << h << "   w = " << w << "\n\n";

	FILE* f = fopen(fileName, "rb");
	if (f == NULL) {
		cout << "File not found!" << fileName << endl;
		return 1;
	}

	BMPFile bmp;
	readBMP(f, bmp);
	fclose(f);
	printInfo(bmp);	
	positionCalculate(bmp, h, w, subHeight, subWidth, posRow, posCol);
	splitBMP(bmp, h, w, subHeight, subWidth, posRow, posCol, fileName);
	freeMem(bmp);	
	return 0;
}
