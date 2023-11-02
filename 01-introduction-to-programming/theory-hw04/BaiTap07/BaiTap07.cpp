#include <iostream>
using namespace std;
int main(){
	int x1=1,x2=1;
	int n;
	cin>>n;
	cout<<1<<" "<<1<<" ";
	for (int i=3;i<=n;i++){
		int tmp= x1+x2;
		cout<<tmp<<" ";
		x1=x2;
		x2=tmp; 
	}
	return 0; 
} 
