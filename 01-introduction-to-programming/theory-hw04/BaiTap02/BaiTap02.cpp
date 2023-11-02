#include <iostream>
using namespace std;
int main(){
	long long n;
	long long m=0; 
	cin>>n;
	long long N=n; 
	while (n!=0){
		m=m*10+n%10; 
		n=n/10;

	} 

	if (m==N) cout<<1;
	else cout<<0; 
	return 0; 
} 
