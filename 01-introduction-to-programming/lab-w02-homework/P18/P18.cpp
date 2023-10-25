// Lê Pham Kieu Duyen
// 23CLC04
 
// Test case1
// Input 3 5 
// Output 5 3 
 
// Test case2 
// Input 5 8 
// Output 8 5 

// Test case3 
// Input 6 7 
// Output 7 6 
#include <iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	a= a+b;
	b= a-b;
	a=a-b;
	cout<<a<<" "<<b;
	return 0;
}
