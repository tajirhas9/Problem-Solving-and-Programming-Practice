#include <bits/stdc++.h>
using namespace std;
int main()
{
	double t,a,n=3,flag=0;
	double r;
	cin >> t;
	while(t--)
	{
		n=3;
		r = (n-2)*180;
		r /= n;
		cin >> a;
		while(r <= a)
		{
			if(r==a)
			{
				flag = 1;
				cout << "YES" << endl;
				break;
			}
			n++;
			r = (n-2)*180;
			r /= n;
		}
		if(flag == 0)	cout << "NO" << endl;
		flag = 0;
	}
	return 0;
}
