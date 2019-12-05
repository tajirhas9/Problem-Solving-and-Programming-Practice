#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
	long long a,b,count=0;
	int T;
	cin >> T;
	while(T--)
	{
		scanf("%lld %lld",&a,&b);
		if(max(a,b)%min(a,b) ==0)	 count++;
		for(int i=1;i<= min(a,b)/2;i++)
		{
			if(a%i==0 && b%i==0)
				count++;
		}
		printf("%lld\n",count);
		count=0;
	}
	return 0;
}
