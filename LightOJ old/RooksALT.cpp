#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	scanf("%lld",&t);
	for(int j=1;j<=t;j++)
	{
		long long n,k,ans=1;
		scanf("%lld %lld",&n,&k);
		for(int i=1;i<=n;i++)
			ans *= i;
		if(k==1)	ans = n*n;
		else if(k<n)
			ans *= k+1;
		else if(k>n)	ans=0;
		printf("Case %d: %lld\n",j,ans);
	}
	return 0;
}
