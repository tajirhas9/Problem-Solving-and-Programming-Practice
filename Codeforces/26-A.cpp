#include <bits/stdc++.h>
using namespace std;
void seive(void);
bool prime[3005];
int divisor(int x);
int main()
{
	seive();
	int x,almostPrime=0;
	cin >> x;
	for(int i=1;i<=x;i++)
	{
		if(divisor(i) == 2)
		{
			almostPrime++;
		}
	}
	cout << almostPrime;
	return 0;
}
void seive(void)
{
	memset(prime,false,sizeof(false));
	prime[0] = prime[1] = true;
	for(int i=2;i*i < 3005;i++)
	{
		if(prime[i] == false)
		{
			for(int j=i*i;j<3005;j+=i)
			{
				prime[j] = true;
			}
		}
	}
}
int divisor(int x)
{
	int count=0;
	for(int i=2;i*2<=x;i++)
	{
		if(x%i==0 && prime[i]==false)
			count++;
	}
	return count;
}
