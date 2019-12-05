#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main()
{
	stack <double> store;
	unsigned long long x;
	while((scanf("%llu",&x))==1)
	{
		store.push(sqrt(x));
	}
	while(!store.empty())
	{
		printf("%.4lf\n",store.top());
		store.pop();
	}
	return 0;
}
