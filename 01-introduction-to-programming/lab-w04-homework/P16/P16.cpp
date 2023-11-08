#include <iostream>
#include <iomanip> 
using namespace std;
int main(){
	double x;
	int n;
	cin>>x>>n;
	int X=x; 
	double mau=0;
	double sum=0; 
	for (int i=1;i<=n;i++) {
		mau+=i;
		sum+= x/mau;
		x=x*X; 
	}
	cout<<setprecision(2)<<fixed<<sum;
	return 0;
	
}
	 
	
