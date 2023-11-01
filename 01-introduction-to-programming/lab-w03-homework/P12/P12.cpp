// Lê Pham Kieu Duyen
// 23CLC04 


// Test case 1
// Input: 1 2 3 4  
// Output:4 1 

// Test case 2
// Input: 23 45 8 91 
// Output:91 8 

// Test case 3
// Input: 45 78 9 23 
// Output:78 9 

#include<iostream>
using namespace std;
int main(){
	long long a,b,c,d;
	long long max=-10e9, min= 10e9;
	cin>>a>>b>>c>>d; 
	if (a>=max) max=a;
	if (b>=max) max=b;
	if (c>=max) max=c;
	if (d>=max) max=d;
	if (a<=min) min=a;
	if (b<=min) min=b;
	if (c<=min) min=c;
	if (d<=min) min=d;
	cout<< max<< " "<<min;
	return 0;  
} 
