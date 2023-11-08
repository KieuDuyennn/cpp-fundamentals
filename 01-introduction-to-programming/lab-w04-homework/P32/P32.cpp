#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int check=0; 
	for (int i=1;i<=sqrt(n);i++) 
	   if (i*i==n) check=1;
	if (check==1) cout<<"YES";
	else cout<<"NO";
	return 0; 
} 
