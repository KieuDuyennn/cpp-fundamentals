#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
	double n,x;
	cin>>x>>n;
	int r=x;
	double sum=0; 
	for (int i=1;i<=n;i++) {
		sum=sqrt(sum+r);
		r=r*x; 
	}
	cout<<setprecision(2)<<fixed<<sum;
	return 0; 
} 
