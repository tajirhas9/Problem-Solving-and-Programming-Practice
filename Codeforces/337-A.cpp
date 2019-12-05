#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a[100],i,minim = 1000000;
	cin >> n >> m;
	for(i=1;i<=m;i++)
		cin >> a[i];
	for(i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(a[i] > a[j])	swap(a[i],a[j]);
		}
	}
	for(i=1;i+(n-1) <=m;i++)
		minim = min(minim,a[i+(n-1)]-a[i]);
	cout << minim << endl;	
	return 0;
}
