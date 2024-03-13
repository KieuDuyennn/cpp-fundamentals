#include <iostream>
#include <cmath>
#include <string> 
using namespace std;
#define MAX 1000
// 6.2a 
long long sumEvensInArray(int*& a, int n) {
	if (n == 1) {
		if (a[0] % 2 == 0) return a[0];
		else return 0;
	}
	if (a[n - 1] % 2 == 0) 
		return sumEvensInArray(a, n - 1) + a[n - 1] ;
	return sumEvensInArray(a, n - 1);
}
void inputArray(int*& a, int &n) {
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	a = new int[n];
	cout << "Nhap " << n << " so nguyen, cach nhau boi khoang trang:" << endl;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
}
// 6.2b 
int findMax(int*a, int n) {
    
    if (n == 1) {
        return a[0];
    }
    int restMax = findMax(a + 1, n - 1);
    return max(a[0], restMax);
}



// 6.2c 
void reverseString(string& str, int start, int end) {
    if (start >= end) {
        return; 
    }
    swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}

//6.2d  


void printCurrencyFormat(int num, int count) {
    if (num == 0) {
        if (count == 0) {
            cout << "0";
        }
        return;
    }
    printCurrencyFormat(num / 10, count + 1);
    cout << num % 10;
    if (count > 0 && count % 3 == 0) {
        cout << ",";
    }
}



int main() {
	int choice ;
	cin>>choice;
	int n;
	int *a=NULL;
	if (choice == 1){
		inputArray(a, n);
			cout << "Tong gia tri cac so nguyen chan trong mang la: " << sumEvensInArray(a, n) << endl;
			delete[] a;
	} 
	if (choice == 2){
		inputArray(a, n);
		cout<<findMax(a,n); 
	} 
    if (choice == 3){
    string input;
    cout << "Enter a string: ";
    cin >> input;

    reverseString(input, 0, input.length() - 1);

    cout << "Reversed string: " << input << endl;
}

    if (choice == 4) {
    	int num;
        cin >> num;

        if (num < 0) {
            cout << "Please enter a positive integer." << endl;
            return 1;
    }

        cout << "Currency format: $";
        printCurrencyFormat(num, 0);
        cout << endl;
	} 
	return 0; 
}

