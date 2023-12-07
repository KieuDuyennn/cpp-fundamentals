#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Date
{
	int day, month, year;
};

void Input(Date &date)
{
	cin >> date.day >> date.month >> date.year;
//	date.day = d;
//	date.month = m;
//	date.year = y;
}

void Output(Date d1)
{
	cout << setfill('0') << setw(4) << d1.year << " ";
	cout << setfill('0') << setw(2) << d1.month << " ";
	cout << setfill('0') << setw(2) << d1.day << "\n";
}

int DateCmp(Date d1, Date d2)
{
	if(d1.year > d2.year) return 1;
	else if(d1.year < d2.year) return -1;
		 else if(d1.month > d2.month) return 1;
		 	  else if(d1.month < d2.month) return -1;
				   else	if(d1.day > d2.day) return 1;
					    else if(d1.day < d2.day) return -1;
	return 0;
}		

bool IsLeapYear(int year)
{
	if(year % 400 == 0) return 1;
	if(year % 100 == 0) return 0;
	if(year % 4 == 0) return 1;
	return 0;
}
int DaysOfMonth(Date date)
{
	switch(date.month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			return 28 + IsLeapYear(date.year);
		default:
			return 0;  
	}
}
void FindTomorrow(Date &date)
{
	int LimDay = DaysOfMonth(date);
	if(date.month == 12 && date.day == LimDay) 
	{
		date.day = 1;
		date.month = 1;
		date.year++; 
	}
	else
	{
		if(date.day == LimDay)
		{
			date.day = 1;
			date.month++;
		}
		else
			date.day++;
	}
}

void FindYesterday(Date &date)
{
	if(date.month == 1 && date.day == 1) 
	{
		date.day = 31;
		date.month = 12;
		date.year--; 
	}
	else
	{
		if(date.day == 1)
		{
			date.month--;
			date.day = DaysOfMonth(date);	
		}
		else
			date.day--;
	}
}

int main()
{
	Date date;
	int t;
	while(1)
	{
		cout<< "Nhap 1,2,6,7,8"; 
		cin >> t;
		if(t == 1) Input(date);
		if(t == 2) Output(date);
		if(t == 6){
			Date d1, d2;
			Input(d1);
			Input(d2);
			cout << DateCmp(d1, d2) << "\n";
		}
		if(t == 7) 
		{   Input(date);
			FindYesterday(date);
			Output(date);
		}
		if(t == 8)
		{   Input(date);
			FindTomorrow(date);
			Output(date);
		}
		if(t == 0) break;
	}
	return 0;
}


