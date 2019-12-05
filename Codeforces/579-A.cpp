#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll x,a=0;
	cin >> x;
	while(x)
	{
		a += x&1;
		x>>=1;
	}
	cout << a << endl;
	return 0;
}
