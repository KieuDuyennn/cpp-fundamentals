
#include "function.h"
int tongcs(int n) {
	int s = 0;
	while (n != 0) {
		s += n % 10;
		n = n / 10;
	}
	return s;
}
int tich(int n) {
	int res = 1;
	while (n != 0) {
		int k = n % 10;
		if (k % 2 == 1) {
			res *= k;
			n = n / 10;
		}
		else n = n / 10;
	}
	return res;
}
int mi(int n) {
	int Mi = 10;
	int k;
	while (n != 0)
	{
		k = n % 10;
		if (k == 0) { return 0;break; }
		else {

			if (k < Mi) {
				Mi = k;
				n = n / 10;
			}
			else n = n / 10;
		}
	}
	return Mi;
}

int checkchan(int n){
	int dem=0;
	while (n!=0) {
		int t= n%10;
		if (t%2==0) dem++;
		n=n/10; 
	}
	if (dem==0) return 1;
	else return 0; 
} 

int ucln(int a,int b){
	int uoc=0; 
	int k;
	if (a<b) k=a;
	else k=b;
	for (int i=k/2;i>=1;k--)
	 if (a%k==0 && b%k==0) {
	 	uoc=k;
		 break; 
	 } 
	return uoc; 
} 

int Pow(double a,int b){
	double tich=1;
	for (int i=1;i<=b;i++) tich*=a;
	return tich; 
} 

int gt(int k){
	int giaithua=1;
	for (int i=1;i<=k;i++) giaithua*=i;
	return giaithua; 
} 

int k3(int n){
	int dem=0;
	while (n!=1){
		if (n%3==0) n=n/3;
		else dem++; 
	}
	if (dem==0) return 1;
	else return 0; 
} 

void addDay(int &day, int &month, int &year, int n)
{
	int a = n;
	int daysInMonth;
	while (n > 0)
	{
		daysInMonth = 31;
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			daysInMonth = 30;
		}
		else if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			{
				daysInMonth = 29;
			}
			else
			{
				daysInMonth = 28;
			}
		}

		if (n >= daysInMonth - day + 1)
		{
			n -= daysInMonth - day + 1;
			day = 1;
			if (month == 12)
			{
				month = 1;
				year++;
			}
			else
			{
				month++;
			}
		}
		else
		{
			day += n;
			n = 0;
		}
	}

	cout<<day<<" "<<month<<" "<<year; 
}
int checknt(int n){
	int dem=0;
	for (int i=2;i<=n/2;i++) 
	 if (n%i==0) dem++;
	 if (dem==0) return 1;
	 else return 0; 
} 
int giaiPT(float a, float b, float c,float &x1, float &x2){
	float delta = b*b - 4*a*c;
	if(delta<0){
		x1=x2=0.0;
		return 0;
	}
	else if(delta==0){
		x1 = x2 = -b/(2*a);
		return 1;
	}
	else{
		delta = sqrt(delta);
		x1 = (-b + delta) / (2*a);
		x2 = (-b - delta) / (2*a);
		return 2;
	}
}
