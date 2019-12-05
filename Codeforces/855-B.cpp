#include <bits/stdc++.h>
using namespace std;
long long n,p,q,r,a[100005],x=0;
long long findMax(void);
long long findMin(void);
int main()
{
	long long i,ma,mi,b,c,d,maxSecondary=-10000000000,minSecondary=10000000000;
	cin >> n >> p >> q >> r;
	for(i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	ma = findMax();
	mi = findMin();
	/*if(p>=0 && q >= 0 && r >= 0)
	{
		x = p*a[ma]+q*a[ma]+r*a[ma];
	}
	else
	{*/
		//cout << "entered" << endl;
		if(p < 0)
		{
			b = mi;
			x += p*a[b];
		}
		else
		{
			b = ma;
			x += p*a[b];
		}
		//cout << x << endl;
		if(q < 0)
		{
			c = mi;
			if(c < b)
			{
				for(i=1;i<=n;i++)
				{
					if(a[i] < minSecondary && i >= b)
					{
						c = i;
					}
				}
			}
			x += q*a[c];
		}
		else
		{
			c = ma;
			if(c < b)
			{
				for(i=1;i<=n;i++)
				{
					if(a[i] > maxSecondary && i >= b)
					{
						c = i;
					}
				}
			}
			x += q*a[c];
		}
		//cout << x << endl;
		maxSecondary = -10000000000;
		minSecondary = 10000000000;
		if(r < 0)
		{
			d = mi;
			if(d < c)
			{
				for(i=1;i<=n;i++)
				{
					if(a[i] < minSecondary && i >= c)
					{
						d = i;
					}
				}
			}
			//cout << a[d] << endl;
			x += r*a[d];
		}
		else
		{
			d = ma;
			if(d < c)
			{
				for(i=1;i<=n;i++)
				{
					if(a[i] < maxSecondary && i >= c)
					{
						d = i;
					}
				}
			}
			x += r*a[d];
		}
	/*}*/
	cout << x << endl;
	return 0;
}
long long findMax(void)
{
	long long i,m=-10000000000,mPos;
	for(i=1;i<=n;i++)
	{
		if(m < a[i])	
		{
			mPos = i;
			m = a[i];
		}
	}
	return mPos;
}
long long findMin(void)
{
	long long i,m=10000000000,mPos;
	for(i=1;i<=n;i++)
	{
		if(m > a[i])
		{
			mPos = i;
			m = a[i];
		}
	}
	return mPos;
}
