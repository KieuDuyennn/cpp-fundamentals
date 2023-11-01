// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input: 1 10 2019
// Output: 2 10 2019 

// Test case 2
// Input: 31 10 2019
// Output: 1 11 2019

// Test case 3
// Input: 31 12 2019
// Output: 1 1 2020  

#include <iostream> 
using namespace std; 
int main(){
	int m,y,n,x; 
	cin>>n>>m>>y;
	if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ) x=31;
	if (m==4 || m==6 || m==9 || m==11) n=30; 
	if (m==2 && ((y%4 == 0 && y%100 != 0) || (y%400 == 0))) x=29;
	else if (m==2) x=28;
	if (n<x) cout<<n+1<<" "<<m<<" "<<y;
	if (n==x && m==12) cout<<1<<" "<<1<<" "<<y+1;
	if (n==x && m!=12) cout<<1<<" "<<m+1<<" "<<y;
	return 0; 
	 
	
} 
