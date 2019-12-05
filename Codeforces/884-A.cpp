#include <bits/stdc++.h>
using namespace std;
#define DAY 86400
int main()
{
	int n,t,a[200];
	cin >> n >> t;
	int day=0,read=0;
	bool flag = false;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(!flag)
		{
			read += DAY-a[i];
			day++;
		}
		if(read >= t)	flag=true;
	}
	cout << day << endl;
	return 0;
}
