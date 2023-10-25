// Lê Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input:2.4 5.6 
// Output: 62.20

// Test case 2
// Input: 5.8 9.1 
// Output: 205.70 

// Test case 3
// Input: 6.71 5.49 
// Output:148.62

#include <iostream> 
#include <iomanip> 
using namespace std;
int main(){
	double ed,ra;
	cin>>ed>>ra;
	double dt = ed*ed*3/4*3+ra*3.14*ra/2; 
	cout<<setprecision(02)<<fixed<<dt ; 
	return 0; 
} 
