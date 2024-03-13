#include <iostream>
#include <iomanip>

// Calculate A = 1+2+3+..+n
int calA(int n){
	if (n==1) return 1;
	return n+calA(n-1); 
} 

// Calculate x^n 
int calB(int n,int x){
	if (n==0) return 1;
	return x*calB(n-1,x); 
} 

// Calculate C=1/1-1/2+1/3-1/4+....
// Cong thuc truy hoi:	C(1) = 1
//						C(n+1) = C(n) + (-1)^n * 1.0/(n+1)
double calC(int n){
	if (n == 1)
		return 1;
	if (n % 2 == 0)
		return calC(n - 1) - 1.0 / n;
	return calC(n - 1) + 1.0 / n; 
} 

// Print pascal triangle 
long long combination(int n, int k) {
	if (k == 0 || k == n) return 1;
	return combination(n - 1, k) + combination(n - 1, k - 1);
}

void printPascalTriangle(int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j)
			std::cout << combination(i, j) << " ";
		std::cout << '\n';
	}
} 
int main(){
	int choice;
	std::cout<<"Enter 1,2,3,4";
	std::cin>>choice; 
	if (choice == 1) {
		int n;
		std::cin>>n;
		std::cout<<calA(n); 
	}
	if (choice == 2){
		int x,n;
		std::cin>>x>>n;
		std::cout<<calB(n,x); 
	} 
	if (choice == 3){
		int n;
		std::cin>>n;
		std::cout<<calC(n); 
	} 
	if (choice == 4){
		int n;
		std::cin>>n;
	    printPascalTriangle(n); 
	} 
} 
