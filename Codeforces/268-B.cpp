#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull fact(ull n);
ull n;
int main()
{
	cin >> n;
	(n==1)? cout << 1 : cout << fact(n); cout << endl;
	return 0;
}
ull i=0;
ull fact(ull m)
{
	ull sum=0;
	if(m==1)	return 1;
	sum = fact(m-1)+m+(n-m)*(m-1);
	return sum;
}
