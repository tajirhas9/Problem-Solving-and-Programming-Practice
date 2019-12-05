#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000
int i,j,n,a[5],v[10000];
int solve(int n)
{
	if(n<0)	return -1000;
	if(v[n]==-1)
	{
		int x,y,z;
		x = solve(n-a[0])\+1;
		y = solve(n-a[1])+1;
		z = solve(n-a[2])+1;
		if (x>=y && x>=z)
            v[n]=x;
        if (y>=x && y>=z)
            v[n]=y;
        if (z>=x && z>=y)
            v[n]=z;
	}
	return v[n];
}
int main()
{
	cin >> n >> a[0] >> a[1] >> a[2];
	for(i=1;i<=10000;i++)	v[i] = -1;
	v[0] = 0;
	cout << solve(n) << endl;
	return  0;
}


