#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool flag = true;
	int a[200],i,j,n;
	for(i=0;i<=100;i++)	a[i] = i;
	scanf("%d",&n);
	if(n==1)
	{
		printf("%d\n",-1);
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]==i && i < n)
		{
			swap(a[i],a[i+1]);
			if(a[a[i]] != i)	flag = false;
		}
		else if(a[i]==i)
		{
		 	swap(a[i],a[i-1]);
			if(a[a[i]] != i)	flag = false;
		}
	}
	if(flag)
		for(i=1;i<=n;i++)	printf("%d ",a[i]);
	else
		printf("%d\n",-1);
	return 0;
}
