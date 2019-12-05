#include <bits/stdc++.h>
using namespace std;
#define MAX 10000000
typedef unsigned long long ull;
bool isPrime(ull n);
ull result=1;
int main()
{
	ull n,i;
	cin >> n;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			result *= i;
			while(n%i==0)
				n /= i;
		}
	}
	if(n>1)	result *= n;
	cout << result << endl;
	return 0;
}
/*
734337660466
* */
