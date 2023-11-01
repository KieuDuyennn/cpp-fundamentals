// Lê Pham Kieu Duyen
// 23CLC04 

/* Test case 1
 Input:
9.5
8.5
8.0
0
 Output: 8.6 PASSED 

 Test case 2
 Input:
4.0
6.0
7.0
0
 
 Output:5.8 PASSED

 Test case 3
 Input:
9.5
8.0
9.0
1
 Output: 0 FAILED 
 */
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double bt,th,lt,cheat;
    double dtb; 
	cin>>bt>>th>>lt>>cheat;
	if (cheat!=0) cout<<setprecision(1)<<fixed<<0<<" "<<"FAILED";
	if (cheat==0) {
		dtb=bt*0.3+th*0.3+lt*0.4;
		if (dtb>=5) cout<<setprecision(1)<<fixed<<dtb<<" "<<"PASSED";
		if (dtb<5) cout<<setprecision(1)<<fixed<<dtb<<" "<< "FAILED";
	} 
    return 0;		
} 
