#include <iostream>
using namespace std;
int main(){
	int n;
	int i=1;
	int dem=0; 
	cin>>n; 
	while (i*i<=n){
		if (i*i==n) dem++;
		i++; 
	}
	if (dem==1) cout<<"n la so lap phuong";
	else cout<<"n khong la so lap phuong";
	return 0; 
} 
