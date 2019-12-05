#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define cin2(n,m) 	scanf("%d %d",&n,&m)
#define cin1(n)		scanf("%d",&n)
priority_queue <int> plane;
priority_queue <int,vector<int>,greater<int> > planeMin;
queue <int> man;
int main()
{
	int temp,n,m,ma=0,mi=0,x;
	cin2(n,m);
	for(int i=1;i<=m;i++)
	{
		cin1(x);
		plane.push(x);
		planeMin.push(x);
	}
	while(n--)
	{
		if(plane.top() <= 0)	plane.pop();
		ma += plane.top();
		temp  = plane.top();
		plane.pop();
		temp--;
		plane.push(temp);
		if(planeMin.top() <= 0)	planeMin.pop();
		mi +=  planeMin.top();
		temp = planeMin.top();
		planeMin.pop();
		temp--;
		planeMin.push(temp);
	}
	cout << ma << " " << mi << endl;
	return 0;
}
