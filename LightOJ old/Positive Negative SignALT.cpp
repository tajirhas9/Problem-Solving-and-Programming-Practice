#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int j=0,n,m,i,k,c=1,sum=0,t,check=1;
    cin >> t;
    while(++j<=t)
    {
		scanf("%lld %lld",&n,&m);
		if(n==1)
		for(i=1,k=n;i<=k;i++,k--)
		{
			if(check%2)
			{
				sum += k-i;
				cout << k << "-" << i << endl;
			}	
			else
			{
				sum += i-k;
				cout << i << "-" << k << endl;
			}
			c++;
			if(c>m)
			{
				c=1;
				check++;
			}
		}
		printf("Case %lld: %lld\n",j,sum);
		sum=0;
		check=1;
		c=1;
	}
    return 0;
}
