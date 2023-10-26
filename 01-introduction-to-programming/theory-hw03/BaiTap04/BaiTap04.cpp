# include <iostream >
using namespace std;
int main(){
	double a,b,c;
	cin>>a>>b>>c; 
	if (a+b>c && a+c>b && b+c>a) {
		if (a==b && b==c) cout<<"Tam giac deu";
		if ((a==b&&b!=c)||(a==c&&a!=b)||(b==c&&a!=c)) cout<<"tam giac can";
		if ((a*a+b*b==c*c)|| (b*b+c*c==a*a)|| (c*c+a*a==b*b) ) cout<<"tam giac vuong";
		 
	} 
	else cout<<"khong tao thanh tam giac";
	return 0; 
} 
