#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[200],i,sum=0;
	cin >> n >> m;
	for(i=0;i<n;i++)	cin >> a[i];
	for(i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		if(a[i]>a[j])	 swap(a[i],a[j]);
	}
	for(i=0;i<m;i++)
	{
		if(a[i] <= 0)
			sum += a[i];
	}
	cout << -sum << endl;
	return 0;
}
