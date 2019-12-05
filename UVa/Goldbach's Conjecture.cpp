#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define MAX 1000005
bool primes[MAX];
vector<int> prime;
void seive(void);
int main()
{
	seive();
	int n;
	while((scanf("%d",&n)))
	{
		if(n==0)	break;
		printf("%d = ",n);
		for(int i=n-1;i>=n/2;i--)
		{
			if(!primes[i] && !primes[n-i] && (n-i) > 1)
			{
				printf("%d + %d\n",n-i,i);
				break;
			}
		}
	}
	return 0;
}
void seive(void)
{
	memset(primes,false,sizeof(primes));
	for(int i=2;i*i <= MAX;i++)
	{
		if(!primes[i])     //if prime
		{
			for(int j = i*i;j<=MAX;j+=i)
			{
				primes[j] = true;
			}
		}
	}
}
