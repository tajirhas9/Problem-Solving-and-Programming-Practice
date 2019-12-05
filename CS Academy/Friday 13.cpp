#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int day=1,c=0,i,j,monthEnd;
	cin >> s;
	if(s== "Sunday")	day = 3;
	else if(s == "Monday")	day = 4;
	else if(s == "Tuesday")	day = 5;
	else if(s == "Wednesday")	day = 6;
	else if(s == "Thursday")	day = 7;
	else if(s == "Friday")	day = 1;
	else if(s == "Saturday")	day = 2;
	for(i=1;i<=12;i++)
	{
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
			monthEnd = 31;
		else if(i==2)	monthEnd = 28;
		else monthEnd = 30;
		for(j=1;j<=monthEnd;j++)
		{
			if(j==13)
			{
				if(day == 1)	c++;
			}
			day++;
			if(day>7)	day=1;
		}
	}
	cout << c << endl;
	return 0;
}
