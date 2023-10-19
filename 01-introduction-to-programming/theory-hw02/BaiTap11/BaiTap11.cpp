#include <iostream>
using namespace std;
int main(){
	int stu;
	float cal,nut,amt;
	cout<<"number of students";
	cin>>stu;
	cout<<"number of calories required for each student from the mixture";
	cin>> cal;
	cout<<"number of calories in each pound of nuts";
	cin>>nut;
	amt= (stu*cal)/(1.7*nut) *2;
	cout<<"amount of nuts and dried fruit needed for the students "<< amt<<"pound";
	return 0;
	
	
}

