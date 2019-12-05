#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],n,i,l,r,mid;
int main()
{
	cin >> n;
	for(i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	l = 0;
	r = n>>1;
	while(l<r)
	{
		mid = (l+r+1)>>1;
		bool flag=true;
		for(i=0;i<mid;i++)
		{
			if(a[i]*2 > a[n-mid+i])	{ flag=false; break;}
		}
		if(flag)	l = mid;
		else 		r = mid-1;
	}
	cout << n-l << endl;
	return  0;
}
