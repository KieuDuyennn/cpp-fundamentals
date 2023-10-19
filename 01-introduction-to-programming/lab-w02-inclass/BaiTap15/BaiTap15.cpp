// Lê Pham Kieu Duyen
// 23CLC04
 
// Test case1
// Input 10 
// Output 1788.9110640674 0.0000000217
 
// Test case2 
// Input 5 
// Output 611.2135955000 0.0002405389

// Test case3 
// Input 3 
// Output 283.8460969083 0.0080338429
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	double x;
	double y1,y2;
	cin>>x;
	y1 = 4* (x*x+10*x*sqrt(x)+3*x+1);
	y2=(sin(3.14*x*x)+sqrt(x*x+1)) / (pow(2.71,2*x)+cos(3.14/4*x));
	cout<<setprecision(10)<<fixed<<y1<<" "<<y2;
	return 0;
}

