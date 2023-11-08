#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
	int n;
	cin>>n; 
	double sum; 
	for (double i=1;i<=2*n+1;i=i+2)
	 sum += i/(i+1);
	cout<<setprecision(2)<<fixed<<sum;
	return 0; 
} 
