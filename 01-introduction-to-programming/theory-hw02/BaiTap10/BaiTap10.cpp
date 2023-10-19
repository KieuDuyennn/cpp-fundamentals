# include <iostream>
using namespace std;
int main(){
	float ld,wd,lw1,ww1,lw2,ww2,lr,wr,hr;
	cout<<"length and width of the door";
	cin>>ld>>wd;
	cout<<"length and width of the window1";
	cin>>lw1>>ww1;
	cout<<"length and width of the window2";
	cin>>lw2>>ww2;
	cout<<"length,width,height of the room";
	cin>>lr>>wr>>hr;
	float gallon;
	gallon = (2*lr*hr+2*wr*hr-ld*wd-lw1*ww1-lw2*ww2)/120;
	cout<< "amount of paint needed to paint the walls of the room"<<gallon<<"gallon";
	return 0;
	
} 
