/*
// Le Pham Kieu Duyen 
// 23CLC04
 
// Test case 1
// Input: 1 1 4 3 4 5 
// Output:  C khong thuoc hinh chu nhat

// Test case 2
// Input: 1 1 4 3 2 3
// Output: C thuoc hinh chu nhat

// Test case 3
// Input: 1 3 4 5 7 8  
// Output: C khong thuoc hinh chu nhat
*/

#include <iostream> 
using namespace std;
int main(){
	int xA,yA,xB,yB,xC,yC;
	int xmi,xma,ymi,yma; 
	cin>>xA>>yA>>xB>>yB>>xC>>yC;
	if (xA>xB) xmi= xB,xma=xA;
	else       xmi= xA,xma=xB;
	if (yA>yB) ymi= yB,yma=yA;
	else       ymi= yA,yma=yB;
	if (xmi<=xC && xC<=xma && ymi<=yC && yC<=yma) cout<<"C thuoc hinh chu nhat";
	else cout<<"C khong thuoc hinh chu nhat"; 
	return 0; 
	 
} 
