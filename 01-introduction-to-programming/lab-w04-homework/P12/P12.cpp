#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
	double x;
	int n;
	cin>>x>>n;
	int X=x; 
	double sum=0;
	for (int i=1;i<=n;i++){
		sum+=x;
		x=x*X; 
		
	}
	cout<<setprecision(2)<<fixed<<sum; 
	return 0; 
} 
