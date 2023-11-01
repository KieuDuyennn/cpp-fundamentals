// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input: 2.12 
// Output: 2.00 

// Test case 2
// Input: 3.45 
// Output: 3.50 

// Test case 3
// Input: 7.75 
// Output: 8.00 

#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
	double n;
	cin>>n;
	double x = n - (int) n;
	if (x<0.25) cout<< (int) n;
	if (0.25 <=x && x < 0.75) cout<<setprecision(2)<<fixed<< (int)n+0.5;
	if (x >= 0.75) cout<< (int) n+1;
	return 0; 
} 
