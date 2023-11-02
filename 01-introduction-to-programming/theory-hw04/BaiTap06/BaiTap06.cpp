#include <iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	for (int i=a/2;i>=1;i--)
		for (int j=b/2;j>=1;j--) 
		 if (i==j && a%i==0 && b%j==0) {
		 	 cout<<i;
			 break; 
		 }
	 return 0; 
} 
