// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input: 2 3 
// Output: -1.50 

// Test case 2
// Input: 4 5 
// Output: -1.25

// Test case 3
// Input: 8 5 
// Output: -0.62

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	double a,b;
	cin>>a>>b;
	if (a==0 && b==0) cout<<"Phuong trinh vo so nghiem"; 
	if (a==0 && b!= 0) cout<<"Phuong trinh vo nghiem";
	if (a != 0) 
	cout<<setprecision(02)<<fixed<<-b/a;
	return 0; 
} 
