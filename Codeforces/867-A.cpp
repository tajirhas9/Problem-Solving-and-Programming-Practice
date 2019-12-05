#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	int n,fromFransisco=0,fromSeatle=0;
	char s[200],now;
	scanf("%d %s",&n,s);
	now = s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i] != now)
		{
			if(now == 'S')
			{
				fromSeatle++;
				//cout << "Flew from Seatle on day " << i << endl;
				now = 'F';
			}
			else
			{
			 	fromFransisco++;
				//cout << "Flew from Fransisco on day " << i << endl;
				now = 'S';
			}
		}
	}
	if(fromSeatle > fromFransisco)	cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
