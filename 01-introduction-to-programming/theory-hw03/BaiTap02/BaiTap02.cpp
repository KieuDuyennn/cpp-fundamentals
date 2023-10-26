# include <iostream >
using namespace std;
int main(){
	int km;
	cin>>km;
	if (km<=1) cout<< 15000;
	if (1<km && ) cout << 15000+ (km-1)*13500;
	if (6<km && km<=120) cout<< 15000+13500*5+(km-6)*11000;
	if (km>120) cout<<  (15000+13500*5+(km-6)*11000) * 0.9;
	return 0; 
} 

