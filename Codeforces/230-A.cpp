#include <bits/stdc++.h>
using namespace  std;
int main()
{
	long long int s,n,x[1100],y[1100],i,j;
	cin >> s >> n;
	for(i=0;i<n;i++)
	{
		cin >> x[i] >> y[i];
	}
	for(i=0;i<n;i++)
	{
		if(s > x[i] && x[i] != 0 )
		{
			x[i] = 0;
			s += y[i];
		}
		else
		{
			for(j = 0;j<n;j++)
			{
				if(s > x[j] && x[j] != 0)
				{
					x[j] = 0;
					s += y[j];
					break;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(x[i] != 0)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}
