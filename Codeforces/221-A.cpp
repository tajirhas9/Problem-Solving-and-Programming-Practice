#include <bits/stdc++.h>
using namespace std;
int recurse(int n);
int a[2000];
int main()
{
	int n,i;
	cin >> n;
	for(i=1;i<=n;i++)
		a[i] = i;
	recurse(n);
	for(i=1;i<=n;i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
int recurse(int n)
{
	if(n==1)	return 0;
	swap(a[n],a[n-1]);
	recurse(n-1);
}
