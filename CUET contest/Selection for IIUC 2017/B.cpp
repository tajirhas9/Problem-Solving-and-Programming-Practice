#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll x[5],y[5],i;
	for(i=1;i<=3;i++)
		cin >> x[i] >> y[i];
	cout << 3 << endl;
	cout << x[1]+x[3]-x[2] << " " << y[1]+y[3]-y[2] << endl;
	cout << x[1]+x[2]-x[3] << " " << y[1]+y[2]-y[3] << endl;
	cout << x[2]+x[3]-x[1] << " " << y[2]+y[3]-y[1] << endl;
	return 0;
}
