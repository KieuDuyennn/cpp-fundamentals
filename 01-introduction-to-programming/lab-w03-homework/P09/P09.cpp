// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input: 1 4 4 
// Output: x1=-2.00 x2=-2.00

// Test case 2
// Input: 5 6 9 
// Output: Phuong trinh vo nghiem

// Test case 3
// Input: 1 -8 9 
// Output: x1=6.65 x2=1.35

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	double a,b,c;
	cin>>a>>b>>c;
	double delta;
    delta = b*b - 4*a*c;
	if (a!=0) 
	      {
	       if (delta >= 0) cout<<setprecision(2)<<fixed<<"x1="<<(-b+ sqrt(delta))/(2*a)<<" "<<"x2="<<(-b-sqrt(delta))/(2*a);
	       if (delta <0) cout<<"Phuong trinh vo nghiem"; 
		   }
    if (a==0)
	      {
	      	if (b==0 &c==0) cout<<"Phuong trinh vo so nghiem";
			if (b==0 &c!=0) cout<<"Phuong trinh vo nghiem";
			if (b !=0) cout<<setprecision(2)<<fixed<< -c/b; 
		  }
} 
