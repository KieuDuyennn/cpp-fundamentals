#include <iostream>
#include "Function.h"
using namespace std;
int main() {

	int k;
	
	do {
		cout << "Nhap 44, 48 hoac 52 ";
		cin >> k;
		if (k == 44) {
			int n;
			cin >> n;
			cout << tongcs(n);
			
		}
		if (k == 48) {
			int n;
			cin >> n;
			cout << tich(n);
			
		}
		if (k == 52) {
			int n;
			cin >> n;
			cout << mi(n);
			
		}
		
		if (k==56){
			int n;
			cin>>n;
			if (checkchan(n)==1) cout<<"YES";
			else cout<<"NO"; 
		}
		
		if (k==60){
			int a,b;
			cin>>a>>b;
			cout<<ucln(a,b); 
		} 
		
		if (k==64){
			double x;
			int n;
			int kq=0;
			for (int i=2;i<=n;i=i+2)
			 kq += (-1)* Pow (x,i);
			cout<<kq;  
		}
		
		if (k==68){
			double x;
			int n;
			int sum=0; 
			cin>>x>>n;
			for (int i=1;i<=n;i++)
			 sum+= (-1)*Pow(x,i)/gt(i);
			cout<<sum; 
			 
		} 
		
		if (k==72){
			int n;
			if (k3(n)==1) cout<<"YES";
			else cout<<"NO"; 
		} 
		
		if (k==76){
			int day,month,year,n;
            cin>>day>>month>>year>>n;
            addDay(day,month,year,n) ;
            cout<<day<<month<<year; 
		}
		
		if (k==80){
			int n;
			cin>>n;
			if (checknt(n)==1) cout<<n;
			int before=0;
			int after=0;
			for (int i=n-1;i>=1;i--) 
			 if (checknt(i)==1) {
			 	before=i;
				break; 
			 }
			for (int i=n+1;i<=1e9;i++)
			 if (checknt(i)==1) {
			 	after =i;
				break; 
			 }
			if (n-before>=n-after) cout<< before;
			else cout<<after;
		} 
		
		if (k==95){
			float a,b,c;
         	float x1,x2;
         	cin>>a>>b>>c; 
         	while(!a);
	        int numNo = giaiPT(a,b,c,x1,x2);
            if(numNo == 0) {
		    cout<<"Phuong trinh da cho vo nghiem";
	}
        	else if(numNo == 1){
		cout<<"Phuong trinh da cho co nghiem kep x="<<x1; 
	}
	else{
	cout<<"Phuong trinh da cho co hai nghiem phan biet"<<x1<<" "x2; 
	}
}
        if (k==96){
        	int ngay,thang,nam;
			cin>>ngay>>thang>>nam; 
			addDay(day,month,year,1) ;
			cout<<day<<month<<year; 
			
		} 
		} 
	} while (k != 0);
	
}
