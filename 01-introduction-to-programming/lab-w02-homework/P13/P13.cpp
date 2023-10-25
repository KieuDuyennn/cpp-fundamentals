// Lê Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input:3.00 4.00 5.00
// Output: 12.00 6.00

// Test case 2
// Input: 4.00 6.00 5.00
// Output:15.00 9.92

// Test case 3
// Input: 6.00 7.00 8.00
// Output:21.00 20.33

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	double ed1,ed2,ed3; 
	double cv,dt,n; 
	cin>>ed1>>ed2>>ed3;
	cv = ed1+ed2+ed3;
	n=cv/2; 
	dt = sqrt(n*(n-ed1)*(n-ed2)*(n-ed3)) ;
	cout<<setprecision(2)<<fixed<<cv<<" "<<dt;
	return 0; 
	 
} 
 
