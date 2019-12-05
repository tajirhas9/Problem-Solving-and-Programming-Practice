#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k,n[15],i,s=0,j,m=0;
	cin >> k;
	for(i=1;i<=12;i++)	cin >> n[i];
	for(i=1;i<=12;i++)
	{
		for(j=i+1;j<=12;j++)
		{
			if(n[i] < n[j])	swap(n[i],n[j]);
		}
	}
	i=1;
	while(!(s>=k))
	{
		s += n[i];
		m++;
		i++;
		if(i>12)	break;
	}
	if(s<k)	cout << -1 << endl;
	else	cout << m << endl;
	return 0;
}
