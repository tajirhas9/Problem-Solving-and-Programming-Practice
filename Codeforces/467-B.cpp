#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,a[1000005],fedora=0,dif=0,frnd=0;
bool flag=false;
int main()
{
	ll i,j;
	cin >> n >> m >> k;
	for(i=0;i<=m;i++)	cin >> a[i];
	fedora = a[m];
	for(i=0;i<m;i++)
	{
		flag = false;
		dif=0;
		j=0;
		while(j<=n)
		{
			if((a[i]&1<<j)^(fedora&1<<j))
			{
				dif++;
				if(dif>k)
				{
					flag = true;
					break;
				}
			}
			j++;
		}
		if(!flag)	frnd++;
	}
	cout << frnd << endl;
	return 0;
}
