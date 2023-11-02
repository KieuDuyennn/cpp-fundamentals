#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int mi=n%10,ma=n%10;
	bool checkt = 1, checkg = 1; 
	n=n/10;
	while (n != 0) {
		if (mi > (n%10)) checkg = 0;
		mi = n%10;
		n = n/10;  
	} 
	while (n != 0) {
		if (ma < (n%10)) checkt = 0;
		ma = n%10;
		n = n/10;  
	} 
	if(!checkt && !checkg) cout << "Day khong co tinh chat tang // giam";
	else if(checkt && checkg)   cout << "Day khong co tinh chat tang // giam";
	else if(checkt) cout<<"Day tang";
	else cout<<"Day giam";
	return 0; 
} 
