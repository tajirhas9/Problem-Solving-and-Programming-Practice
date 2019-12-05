#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
void seive(void);
bool isPrime(ull x);
bool prime[100];
int main()
{
	seive();
	ull x;
	while(1)
	{
		scanf("%llu",&x);
		if(x==0)	break;
		ull a=1,b=1;
		for(ull i=1;i<=x;i++)
		{
			a *= 2;
			if(i<x)	b *= 2;
		}
		if(isPrime(a-1))
			printf("Perfect: %llu!\n",b*(a-1));
		else if(isPrime(x))
			printf("Given number is prime. But, NO perfect number is available.\n");
		else
			printf("Given number is NOT prime! NO perfect number is available.\n");
	}
	return 0;
}
void seive(void)
{
	memset(prime,false,sizeof(prime));
	for(ull i=3;i*i<100;i+=2)
	{
		if(!prime[i])
		{
			for(ull j=i*i;j<100;j+=i+i)
			{
				prime[j] = true;
			}
		}
	}
}
bool isPrime(ull x)
{
	if(x==2)	return true;
	if(x<2) 	return false;
	if(x%2==0)	return false;
	for(ull i=3;i*i <= x;i+=2)
	{
		if(x%i==0)	return false;
	}
	return true;
}
