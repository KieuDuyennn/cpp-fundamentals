// Lê Pham Kieu Duyen 
// 23CLC04

// Test case 1
// Input: 2361000 
/* Output:500000: 4
200000: 1
100000: 1
50000: 1
20000: 0
10000: 1
5000: 0
2000: 0
1000: 1

 Test case 2
 Input:2567000
 Output:500000: 5
200000: 0
100000: 0
50000: 1
20000: 0
10000: 1
5000: 1
2000: 1
1000: 0

 Test case 3 
 Input:678000 
 Output:
500000: 1
200000: 0
100000: 1
50000: 1
20000: 1
10000: 0
5000: 1
2000: 1
1000: 1

*/
#include<iostream>
using namespace std;
int main(){
	int money;
	cin>>money; 
	int to500,to200,to100,to50,to20,to10,to5,to2,to1;
	to500 = money/500000;
	money= money%500000; 
	to200 = money/200000;
	money= money%200000; 
	to100 = money/100000;
	money= money%100000; 
	to50 = money/50000;
	money= money%50000; 
	to20 = money/20000;
	money= money%20000; 
	to10 = money/10000;
	money= money%10000; 
	to5 = money/5000;
	money= money%5000; 
	to2 = money/2000;
	money= money%2000; 
	to1 = money/1000;
	cout<< "500000: " << to500<<endl; 
	cout<< "200000: " << to200<<endl; 
	cout<< "100000: " << to100<<endl; 
	cout<< "50000: " << to50<<endl; 
	cout<< "20000: " << to20<<endl; 
	cout<< "10000: " << to10<<endl; 
	cout<< "5000: " << to5<<endl; 
	cout<< "2000: " << to2<<endl; 
	cout<< "1000: " << to1<<endl;  
	return 0;} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	 
