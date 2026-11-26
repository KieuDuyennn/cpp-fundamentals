// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input:6 
// Output:1 3  

// Test case 2
// Input: 28 
// Output:1 7 

// Test case 3
// Input: 126 
// Output:1 3 7 9 21 63
#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n/2;i++) 
	  if (n%i==0 && i%2!=0) cout<<i<<" ";
	return 0;
} 
