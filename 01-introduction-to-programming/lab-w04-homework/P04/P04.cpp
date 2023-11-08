// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input:6 
// Output:1.22 

// Test case 2
// Input: 28 
// Output:1.96 

// Test case 3
// Input: 5 
// Output 1.14
 
#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
	double n;
	cin>>n;
	double sum=0; 
	for (double i=2;i<= 2*n;i=i+2) sum += 1/i; 
	cout<<setprecision(2)<<fixed<< sum;
	return 0; 
} 
