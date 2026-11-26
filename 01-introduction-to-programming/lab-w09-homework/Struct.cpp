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

void addDay(Date &date, int &n)
{
	int daysInMonth;
	while (n > 0)
	{
		daysInMonth = 31;
		if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
		{
			daysInMonth = 30;
		}
		else if (date.month == 2)
		{
			if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)
			{
				daysInMonth = 29;
			}
			else
			{
				daysInMonth = 28;
			}
		}

		if (n >= daysInMonth - date.day + 1)
		{
			n -= daysInMonth - date.day + 1;
			date.day = 1;
			if (date.month == 12)
			{
				date.month = 1;
				date.year++;
			}
			else
			{
				date.month++;
			}
		}
		else
		{
			date.day += n;
			n = 0;
		}
	}

}

int CountDay(Date &date) {
        if (date.month < 3) {
            date.year--;
            date.month += 12;
        }
        return 365*date.year + date.year/4 - date.year/100 + date.year/400 + (153*date.month - 457)/5 + date.day - 306;
    }


struct Student 
{
	int id;
	char fullname[100], address [100];
	float gpa;
	Date date_of_birth; 
 } ;
 
void input_a_student ( Student &s){
	cin>>s.id;
	cin>>s.gpa; 
    cin.ignore();
    cin.get(s.fullname, sizeof(s.fullname)); 
	cin.ignore();
	cin.get(s.address, sizeof(s.address)); 
	Input(s.date_of_birth); 
}

void output_a_student(Student s){
	cout<<s.id;
	cout<<s.gpa; 
	cout<<s.fullname;
	cout<<s.address;
	Output(s.date_of_birth) ;
} 

// Comparators return -1, 0 or 1, like strcmp.
int CmpId(Student &s1,Student &s2)
{
	if (s1.id < s2.id) return -1;
	if (s1.id > s2.id) return 1;
	return 0;
}

int CmpGPA(Student &s1, Student &s2)
{
	if (s1.gpa < s2.gpa) return -1;
	if (s1.gpa > s2.gpa) return 1;
	return CmpId(s1, s2);
}

int CmpName(Student &s1, Student &s2)
{
	int r = strcmp(s1.fullname, s2.fullname);
	if (r < 0) return -1;
	if (r > 0) return 1;
	return CmpId(s1, s2);
}

int CmpDob(Student &s1,Student &s2)
{
	const Date &d1 = s1.date_of_birth, &d2 = s2.date_of_birth;
	if (d1.year != d2.year) return d1.year > d2.year ? 1 : -1;
	if (d1.month != d2.month) return d1.month > d2.month ? 1 : -1;
	if (d1.day != d2.day) return d1.day > d2.day ? 1 : -1;
	return CmpId(s1, s2);
}

 struct Course {
 	int id;
	char name[105];
	Student s[105];
	int status;
	int maxi;
	int mini; 
 }; 
int main()
{
	Date date;
	Student s; 
	int t;
	while(1)
	{
		cout<< "Nhap 1,2,6,7,8,9,13,15,16,21,22,23,24,25,26"; 
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
			cout<<endl; 
		}
		if(t == 8)
		{   Input(date);
			FindTomorrow(date);
			Output(date);
			cout<<endl; 
		}
		if (t==9)
		{
			Input(date);
			int k;
			cin>>k;
			addDay(date,k);
			Output(date);
			cout<<endl; 
			
		 }
		if (t==13)
		{
			Date date1;
			Date date2;
			Input(date1);
			Input(date2);
			int Numbers_of_Days;
			Numbers_of_Days =  CountDay(date1) - CountDay(date2);
			cout<< Numbers_of_Days; 
			cout<<endl; 
		}
		  
		if (t == 15)
		{
			input_a_student(s); 
		 } 
		if (t == 16)
		{
			input_a_student(s);
			output_a_student(s); 
		 } 
		 
		if (t == 21)
		{
			Student s1;
			Student s2; 
			input_a_student(s1); 
			input_a_student(s2); 
			int k = CmpId(s1,s2);
			cout<<k; 
			cout<<endl; 
		}
		
		if (t == 22)
		{
			Student s1;
			Student s2; 
			input_a_student(s1); 
			input_a_student(s2); 
			int k = CmpGPA(s1,s2);
			cout<<k; 
			cout<<endl; 
		}
		
		if (t == 23)
		{
			Student s1;
			Student s2; 
			input_a_student(s1); 
			input_a_student(s2); 
			int k = CmpName(s1,s2);
			cout<<k; 
			cout<<endl; 
		 } 
		
		if (t == 24)
		{
			Student s1;
			Student s2; 
			input_a_student(s1); 
			input_a_student(s2); 
			int k = CmpName(s1,s2);
			cout<<k; 
			cout<<endl; 
		 } 
		 
		if (t == 25)
		{
			Student s1;
			Student s2; 
			input_a_student(s1); 
			input_a_student(s2); 
			int k = CmpName(s1,s2);
			cout<<k; 
			cout<<endl; 
		 } 
		
		if (t == 26)
		{
			Student s1;
			Student s2; 
			input_a_student(s1); 
			input_a_student(s2); 
			int k = CmpDob(s1,s2);
			cout<<k; 
			cout<<endl; 
		 } 
		if(t == 0) break;
	}
	return 0;
}


