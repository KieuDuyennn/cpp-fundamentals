// Lê Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input:42.195 1 59 40.2
// Output: 121.16 2.84

// Test case 2
// Input: 25.67 0.7 34 70 
// Output:19.96 3.01

// Test case 3
// Input: 
// Output:21.00 20.33

#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
	double km,h,m,s;
	cin>>km>>h>>m>>s;
	double pace,speed;
	pace = (h*60+m+s/60)/km;
	speed = km/ (h+m/60+s/3600);
	cout<<setprecision(2)<<fixed<<speed<<" "<<pace; 
	return 0; 
} 
