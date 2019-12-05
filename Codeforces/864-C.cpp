#include <bits/stdc++.h>
using namespace std;
long long a,b,f,k;
int main()
{
	long long c=0,fuel,pos=0,refill=0;
	cin >> a >> b >> f >> k;
	fuel = b;
	while(c<k)
	{
		if(pos==0)
		{
			if(fuel >= a && c == (k-1))
			{
				c++;
				pos = a;
				fuel -= a;
				//printf("%lld %lld\n",pos,fuel);
			}
			else if(fuel >= (2*a-f))
			{
				c++;
				fuel -= a;
				pos = a;
				//printf("%lld %lld\n",pos,fuel);
			}
			else if(fuel >= f)
			{
				fuel -= f;
				pos = f;
				//printf("%lld %lld\n",pos,fuel);
			}
			else
			{
				cout << -1 << endl;
				return 0;
			}
		}
		else if(pos==f)
		{
			fuel = b;
			refill++;
			//printf("Refill in journey : %lld\n",c);
			if(c%2==0)
			{
				if(fuel >= (a-f) && c == k-1)
				{
					c++;
					fuel -= a-f;
					pos = a;
				}
				else if(fuel >= 2*(a-f))
				{
					c++;
					fuel -= a-f;
					pos = a;
				//printf("%lld %lld\n",pos,fuel);
				}
				else
				{
					cout << -1 << endl;
					return 0;
				}
			}
			else
			{
				if(fuel >= f && c == k-1)
				{
					c++;
					fuel -= f;
					pos = 0;
				}
				else if(fuel >= 2*f)
				{
					c++;
					fuel -= f;
					pos = 0;
				//printf("%lld %lld\n",pos,fuel);
				}
				else
				{
					cout << -1 << endl;
					return 0;
				}
			}
		}
		else if(pos == a)
		{
			if(fuel >= a && c == (k-1))
			{
				c++;
				pos = 0;
				fuel -= a;
				//printf("%lld %lld\n",pos,fuel);
			}
			else if(fuel >= (a+f))
			{
				c++;
				pos = 0;
				fuel -= a;
				//printf("%lld %lld\n",pos,fuel);
			}
			else if(fuel >= (a-f))
			{
				pos = f;
				fuel -= (a-f);
				//printf("%lld %lld\n",pos,fuel);
			}
			else
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << refill << endl;
	return 0;
}
	
