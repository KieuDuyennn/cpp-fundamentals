#include <iostream>
#include <cstring>
using namespace std;

void InputStr(char a[])
{
	cin.getline(a, 100, '\n');
	
}

void ConvertToLowercase(char a[])
{
	for(int i = 0; a[i] != 0; ++i)
		if(a[i] >= 'A' && a[i] <= 'Z')
			a[i] += 'a' - 'A';
}

void ConvertToUppercase(char a[])
{
	for(int i = 0; a[i] != 0; ++i)
		if(a[i] >= 'a' && a[i] <= 'z')
			a[i] -= 'a' - 'A';
}

void ConvertFirstCharToUpper(char a[])
{
	if(a[0] >= 'a' && a[0] <= 'z') a[0] -= 'a' - 'A';
	
	for(int i = 1; a[i] != 0; ++i)
		if(a[i-1] == ' ')
			if(a[i] >= 'a' && a[i] <= 'z')
				a[i] -= 'a' - 'A';
}

void DelStr(char a[], int l ,int r)
{
	if(l > r) return;
	
	int n = strlen(a);
	for(int i = r + 1; a[i] != 0; ++i) 
	
		a[i - (r - l + 1)] = a[i];
	
	a[n] = 0;
}
void RemoveMultipleSpace(char a[])
{
	int i = 0; 
	
	while(a[i] != 0)
	{
		int j = i;
		for(; a[j] != 0; ++j)
			if(a[j] != ' ') 
			{
				DelStr(a, i + 1, j - 1);
				i = j + 1;
			}
			
		if(a[j] == 0)
		{
			DelStr(a, i + 1, j - 1);
			i = j;
		} 
	}
}

void SubFirstnChar(char a[],int n,int index,char b[]) {
	int l = strlen(a);
	for (int i=index;i < index+n;i++)
	 b[i-index]=a[i]; 
	 b[n]=0; 
}

void SubLastnChar(char a[],int n,int index,char b[]) {
	for (int i=index-n;i<index;i++)
	  b[i-index+n]=a[i]; 
	  b[n]=0; 
}

int main()
{
	char a[100],b[100]; 
	
	while(1)
	{
		int t = -1;
		cin >> t;
		cin.getline(a, 100, '\n');
		if(t == 1) {
			InputStr(a);
			ConvertToLowercase(a);
			cout<<a;
			cout<<endl;
			
		}
		if(t == 2) {
			InputStr(a);
			ConvertToUppercase(a);
			cout<<a;
			cout<<endl;
		}
		if(t == 3){
			InputStr(a);
			ConvertFirstCharToUpper(a);
			cout<<a;
		}
		if(t == 4) 
		{
			InputStr(a);
			RemoveMultipleSpace(a);
			cout<<a;
		}
		if(t == 5)
		{
			InputStr(a);
			int n,index;
			
			cin>>n>>index;
			SubFirstnChar(a,n,index,b);
			cout<<b;
			
		}
		if(t == 6)
		{
			InputStr(a);
			int n,index;
			
			cin>>n>>index;
			SubLastnChar(a,n,index,b);
			cout<<b;
			
		}
		if(t==7)
		{
			InputStr(a);
			cout<<a;
		}
//		cout<<t<<"\n";
		if(t == 0) break;
	}
	return 0;
}
