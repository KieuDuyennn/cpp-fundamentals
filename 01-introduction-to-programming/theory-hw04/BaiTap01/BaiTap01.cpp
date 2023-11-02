#include <iostream> 
using namespace std;
#define for(i,a,b) for(int i=a;i<=b;i++) 
int main(){
	int dem=0;
	for (i,1,9) {
         for (j,0,9) {
         	for (k,0,9) 
         	if (i==j+k) { dem++; cout<<i<<j<<k<<endl;} 
			 
		 } 
	} 
	cout<<dem;
	return 0; 
} 
