// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input: 2 2019 
// Output: 28 

// Test case 2
// Input: 7 2012 
// Output: 31 

// Test case 3
// Input: 4 2023 
// Output: 30 

#include <iostream>
using namespace std;
int main(){
	int m,y;
	cin>>m>>y;
	if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ) cout<<31;
	if (m==4 || m==6 || m==9 || m==11) cout<<30; 
	if (m==2 && ((y%4 == 0 && y%100 != 0) || (y%400 == 0))) cout<<29;
	else if (m==2) cout<<28;
	return 0; 
} 
