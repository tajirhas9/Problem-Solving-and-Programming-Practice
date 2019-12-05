#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long x,count=0;
	string s;
	while((scanf("%lld",&x)))
	{
		count = 0;
		if(x==0)	break;
		for(int i=1;i*i<=x;i++)
		{
			if(i*i==x)
			{
				x /= i;
				count++;
			}
			else if(x%i==0)
			{
				x /= i;
				count += 2;
			}
		}
		(count%2==0) ? cout << "no" << endl : cout << "yes" << endl;
	}
	return 0;
}
