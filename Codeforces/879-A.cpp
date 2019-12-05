#include <bits/stdc++.h>
using namespace std;
int main()
{
	int s[1005],d[1005],n,day=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i] >> d[i];
		if(day < s[i])
		{
			day += (s[i]-day);
		}
		else
		{
			for(int j=s[i]; ; j+=d[i])
			{
				if(j > day)
				{
					day += (j-day);
					break;
				}
			}
		}
	}
	cout << day << endl;
	return 0;
}
