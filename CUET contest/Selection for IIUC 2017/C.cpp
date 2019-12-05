#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a[100005],i,prev,b[100005],l,r,m,j;
bool flag=false;
int main()
{
	while(1)
	{
		ll prev;
		prev=1000000;
		m=0;
		cin >> n;
		if(n==0)	break;
		cin >> q;
		for(i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]!=prev)
			{
				b[i] = 1;
				prev = a[i];
			}
			else 	b[i] = b[i-1]+1;
		}
		for(i=1;i<=q;i++)
		{
			m=0;
			flag=false;
			cin >> l >> r;
			if(b[l]>1)	flag=true;
			for(j=l;j<=r;j++)
			{
				if(b[j]==1)	flag=false;
				if(flag)
					m = max(m,(b[j]-b[l]+1));
				else
					m = max(m,b[j]);
			}
			cout << m << endl;
		}
	}
	return 0;
}
