// Le Pham Kieu Duyen
// 23CLC04

// Test case 1
// Input: 2018 
// Output: Khong phai nam nhuan

// Test case 2
// Input: 2020 
// Output: Nam nhuan 

// Test case 3
// Input: 1800 
// Output: Khong phai nam nhuan

#include<iostream>
using namespace std;
int main(){
	int year;
	cin>>year; 
	if ((year%4==0 && year%100 !=0) || year%400==0) cout<< "Nam nhuan";
	else cout<<"Khong phai nam nhuan";
	return 0; 
} 
