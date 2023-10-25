// Lê Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input:3 4 5  
// Output: 14 5 3 

// Test case 2
// Input: 6 8 9 
// Output:8 9 6 

// Test case 3
// Input: 1 2 3  
// Output:2 3 1 
 #include <iostream>
 using namespace std;
 int main(){
 	int a,b,c;
	 cin>>a>>b>>c;
	 a = a+b;
	 b = a-b;
	 a = a-b;
	 b = b+c;
	 c = b-c;
	 b = b-c;
	 cout<<a<<" "<<b<<" "<<c;
	 return 0; 
 } 
