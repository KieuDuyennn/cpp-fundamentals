#include <iostream>
using namespace std;
int main(){
	double h;
	cin>>h;
	if (h>=0 && h<=3) cout<<5;
	if (h>3 && h<=9) cout<< 6*int(h+1);
	if (h>9 && h<=24) cout<<60;
	return 0; 
} 
