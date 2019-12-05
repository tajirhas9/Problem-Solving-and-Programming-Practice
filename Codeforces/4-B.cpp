#include <bits/stdc++.h>
#include <queue>
using namespace std;
int main()
{
	int mi[35],ma[35],a[35],d,sumTime,timeLeft,timeSpent=0;
	cin >> d >> sumTime;
	timeLeft = sumTime;
	for(int i=1;i<=d;i++)
	{
		cin >> mi[i] >> ma[i];
		a[i] = mi[i];
		timeLeft -= a[i];
		timeSpent += a[i];
	}
	if(timeSpent == sumTime)
	{
		cout << "YES" << endl;
		for(int i=1;i<=d;i++)	cout << a[i] << " ";
		cout << endl;
	}
	else if(timeSpent > sumTime)
	{
		cout << "NO" << endl;
		return 0;
	}
	else
	{
		int i=d;
		while(timeLeft>0)
		{
			if(ma[i] <= timeLeft)
			{
				timeSpent -= a[i];
				timeLeft += a[i];
				a[i] = ma[i];
				timeSpent += a[i];
				timeLeft -= a[i];
			}
			else if(ma[i] > (timeLeft+a[i]))
			{
				a[i] += timeLeft;
				timeLeft = 0;
				timeSpent = sumTime;
			}
			else
			{
				a[i] += (ma[i]-mi[i]);
				timeLeft -= (ma[i]-mi[i]);
				timeSpent += (ma[i]-mi[i]);
			}
			i--;
			if(i==0)	break;
		}
		if(timeLeft>0)	cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			for(int i=1;i<=d;i++)
				cout << a[i] << " ";
			cout << endl;
		}
		
	}
	return 0;
}
