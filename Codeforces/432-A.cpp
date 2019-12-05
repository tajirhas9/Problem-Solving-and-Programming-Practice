#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,k,count=0,a[2005],m=0;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		//cout << a[i] << endl;
		if((5-a[i])>=k)	m++;
		else
		{
			break;
		}
		
		if(m==3)
		{
			m=0;
			count++;
		}
	}
	cout << count << endl;
	return  0;
}


