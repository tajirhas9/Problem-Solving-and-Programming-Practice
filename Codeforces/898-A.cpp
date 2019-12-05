#include <bits/stdc++.h>
using namespace std;
long long n,r;
int main()
{
	cin >> n;
	r = n%10;
	if(r<=5)
		cout << n-r << endl;
	else
		cout << n+(10-r) << endl;
	return 0;
}
