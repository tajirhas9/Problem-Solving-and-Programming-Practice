#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	double t,r,sum=0;
	cin >> t;
	while(t--)
	{
		cin >> r;
		while(r > 0.00000000000000000000000001)
		{
			sum += r;
			r = r/sqrt(2);
		}
		printf("%.1lf\n",sum);
		sum = 0;
	}
	return 0;
}
