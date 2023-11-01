// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input: 1 4 4 
// Output: Phuong trinh vo nghiem

// Test case 2
// Input: 5 6 9 
// Output: Phuong trinh vo nghiem

// Test case 3
// Input: 1 -8 9 
// Output: x1=-1.16 x2=1.16 x3=-2.58 x4=2.58

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	double a,b,c;
	double x1,x2; 
	cin>>a>>b>>c;
	double delta;
    delta = b*b - 4*a*c; 
    if (a != 0)
	    {
	    	if (delta<0) cout<<"Phuong trinh vo nghiem";
			if (delta>=0) {
				x1=-(b+ sqrt(delta))/(2*a) ;
				x2=-(b- sqrt(delta))/(2*a) ;
				if (x2>0) cout<<setprecision(2)<<fixed<<"x1="<<-sqrt(x1)<<" "<<"x2="<<sqrt(x1)<<" "<<"x3="<<-sqrt(x2)<<" "<<"x4="<<sqrt(x2);
				if (x1<0) cout<<"Phuong trinh vo nghiem";
				if (x1>0 && x2<0) cout<<setprecision(2)<<fixed<<"x1="<<-sqrt(x1)<<" "<<"x2="<<sqrt(x1);
				
			} 
		 } 
	if (a == 0) 
	    {
	    	if (b==0 && c==0) cout<<"Phuong trinh vo so nghiem";
			if ((b==0 && c!=0) || (b!=0 && c>0)) cout<<"Phuong trinh vo nghiem";
			if (b!=0 && c<0) cout<<setprecision(2)<<fixed<<"x1="<<-sqrt(-c/b)<<" "<<"x2="<<-sqrt(-c/b);
		 } 
    return 0; 
} 
