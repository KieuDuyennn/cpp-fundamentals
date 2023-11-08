#include <iostream>
#include <math.h>
#include <iomanip> 
using namespace std;
int main(){
	double n;
	cin>>n;
	double s=0;
	double gt=1; 
	for (double i=1;i<=n;i++) {
		s=sqrt(s+(gt));
		gt=gt*(i+1); 
	}
	cout<< setprecision(2)<<fixed<<s;
	return 0; 
} 
