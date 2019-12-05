#include <bits/stdc++.h>
using namespace std;
struct three
{
	int l,r,d;
};
int main()
{
	int n,m,k;
	int a[100005];
	three q[100005];
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=m;i++)
	{
		cin >> 	q[i].l >> q[i].r >> q[i].d;
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin >> x >> y;
		for(int j=x;j<=y;j++)
		{
			for(int k=q[j].l; k<= q[j].r;k++)
			{
				a[k] += q[j].d;
			}
		}
	}
	for(int i=1;i<=n;i++)	cout << a[i] << " ";
	return 0;
}
