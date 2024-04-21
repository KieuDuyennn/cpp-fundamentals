#include <iostream>
#include <math.h>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int a[MAX_N];
int length[MAX_N];
int path[MAX_N];

void inputArr(int n, int* a){
    for(int i = 0; i < n; ++i)
        cin >> a[i];
}

void init(int n, int* path, int* length){
    for(int i = 0; i < n; ++i){
        length[i] = 1;
        path[i] = -1;
    }
}

void subArrBottomUp(int n, int* a, int* length, int* path, int &posLast, int& maxLength){
    // ham tra ve idx cua phan tu lon nhat cua day con can tim
    posLast = 0;
    maxLength = 1;
	for (int i = 0; i < n; ++i) {
		length[i] = 1;
		path[i] = -1;
		for (int j = 0; j < i; ++j)
			if (a[j] <= a[i] && length[j] + 1 > length[i]) {
				length[i] = length[j] + 1; // Cap nhat do dai
				path[i] = j;
				if (length[i] > maxLength) {
					maxLength = length[i];
					posLast = i;
				}
			}
	}
		
}

int subArrTopDown(int n, int* a, int* length, int* path, int& posLast, int& maxLength) {
	if (length[n] != 0) {
		return length[n];
	}
	length[n] = 1;
	path[n] = -1;
	for (int j = 0; j < n; ++j) {
		int len_j = subArrTopDown(j, a, length, path, posLast, maxLength);
		if (a[j] <= a[n] && len_j + 1 > length[n]) {
			length[n] = len_j + 1; // Cap nhat do dai
			path[n] = j;
			if (length[n] > maxLength) {
				maxLength = length[n];
				posLast = n;
			}
		}
	}
	return length[n];
}

void printResult(int* a, int* path, int posMax, int maxLength){
    cout << "Chuoi con tang khong can lien tuc co do dai dai nhat la " << maxLength << endl;
    cout << "Cac phan tu: ";
    int tmp[MAX_N];
    for(int i = 0; i < maxLength; ++i){
        tmp[maxLength - 1 - i] = a[posMax];
        posMax = path[posMax];
    }
    for(int i = 0; i < maxLength; ++i)
        cout << tmp[i] << " ";
    cout << endl;
}


int main()
{
    int n, posLast, maxLength;

	// TopDown
	cout << "Nhap so luong phan tu so nguyen: ";
    cin >> n;
	cout << "Nhap " << n << " so nguyen, cach nhau boi khoang trang:" << endl;
    inputArr(n, a);
    subArrTopDown(n - 1,a,length,path, posLast,maxLength);
	cout << "Giai bang TopDown" << endl;
    printResult(a,path,posLast,maxLength);

	// BottomUp
	cout << "\n\n";
	posLast = maxLength = 0;
	cout << "Nhap so luong phan tu so nguyen: ";
	cin >> n;
	cout << "Nhap " << n << " so nguyen, cach nhau boi khoang trang:" << endl;
	inputArr(n, a);
	subArrBottomUp(n, a, length, path, posLast, maxLength);
	cout << "Giai bang BottomUp" << endl;
	printResult(a, path, posLast, maxLength);
    return 0;
}
