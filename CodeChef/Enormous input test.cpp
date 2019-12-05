#include <bits/stdc++.h>
using namespace std;
long long n,k,c=0;
int main()
{
	long long i,a;
	scanf("%lld %lld",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a);
		if(a%k==0)	c++;
	}
	printf("%lld\n",c);
	return 0;
}
