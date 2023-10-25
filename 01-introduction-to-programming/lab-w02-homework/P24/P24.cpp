// Lê Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input:40 100000 
// Output: 250000 

// Test case 2
// Input: 30 200000 
// Output:666666.67

// Test case 3
// Input: 34 678000 
// Output:1994117.65

#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
	double pe,quo;
	cin>> pe>> quo;
	cout<<setprecision(2)<<fixed<< quo/pe*100;
	return 0; 
} 
