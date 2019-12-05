#include <bits/stdc++.h>
using namespace std;
long long n,m,x,y;
bool a[1000000001]={false},b[1000000001]={false},c[1000000001]={false};
int main()
{
	int t;
	long long i,j,l,r,points=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld",&n,&m,&x,&y);
		for(i=1;i<=x;i++)
		{
			scanf("%lld %lld",&l,&r);
			for(j=l;j<=r;j++)
			{
				a[j] = true;
			}
		}
		for(i=1;i<=y;i++)
		{
			scanf("%lld %lld",&l,&r);
			for(j=l;j<=r;j++)
			{
				b[j] = true;
				if(a[j] == true)	c[j] = true;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(c[i] == true && c[i+1] == true && c[i+2] == true)
			{
				points++;
				i += 3;
				while(c[i] == true)
				{
					points++;
					i++;
				}
			}
		}
		printf("%lld\n",points);
		points=0;
		for(i=1;i<=n;i++)
		{
			a[i] = false;
			b[i] = false;
			c[i] = false;
		}
	}
	return 0;
}
