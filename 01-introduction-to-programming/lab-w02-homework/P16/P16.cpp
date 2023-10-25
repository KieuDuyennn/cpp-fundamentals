// Lê Pham Kieu Duyen 
// 23CLC04

// Test case 1
// Input: 99999
// Output:5

// Test case 2
// Input:88888
// Output:0

// Test case 3 
// Input:12345
// Output:5
 
#include <iostream>
using namespace std;
int main(){
	int s,n=0;
	cin>>s;
	n = s%10;
	s = s/10;
	n += s%10;
	s = s/10;
	n += s%10;
	s = s/10;
	n += s%10;
	s = s/10;
	n+=s%10;
	n=n%10;
	cout<<n;
	return 0;
	
} 
 
