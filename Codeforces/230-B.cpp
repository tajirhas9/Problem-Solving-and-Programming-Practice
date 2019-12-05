#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005
bool seive(long long x);
void square(void);
long long store[1000005],storeFor[1000005],prime[1000005];
long long n,a[100005];
string ans[100005];
int main()
{
	memset(prime,-1,sizeof(prime));
	//square();
	cin >> n;
	for(int i=0;i<n;i++)
	{
		long long x;
		cin >> x;
		long long y;
		y = sqrt(x);
		if(y*y == x)
		{
			if(seive(y))
				ans[i] = "YES";
			else
				ans[i] = "NO";
		}
		else
			ans[i] = "NO";
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << endl;
	return 0;
}
bool seive(long long x)
{
	long long i;
	if(x==0 || x==1 || prime[x]==1)	return false;
	else if(prime[x] == 0)	return true;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			prime[x] = 1;
			return false;
		}
	}
	prime[x] = 0;
	return true;
}
void square(void)
{
	long long i;
	memset(store,0,sizeof(store));
	for(i=1;i*i<100005;i++)
	{
		store[i*i] = 1;
		storeFor[i*i] = i;
	}
}
