#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
	ull n,a[100005],p[100005],m,m_val=1005,total=0,remain,cost=0;
	cin >> n;
	for(ull i=0;i<n;i++)
	{
		cin >> a[i] >> p[i];
		total += a[i];
		if(m_val>p[i])
		{
			m_val=p[i];
			m=i;
		}
	}
	remain=total;
	for(ull i=0;i<n&&remain;i++)
	{
		if(i==m)
		{
			cost += remain*p[i];
			remain=0;
		}
		else
		{
			ull j=i;
			while(p[j]>=p[i] && j<m)
			{
				remain -= a[j];
				cost += a[j]*p[i];
				j++;
			}
			i=--j;
		}
	}
	cout << cost << endl;
	return 0;
}
