#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,a[200],i,c,onHand=0,give=0,day=0;
	cin >> n >> k;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		if(give < k)
		{
            if(give+onHand >= k)
            {
                give += onHand;
                day++;
                continue;
            }
			if(a[i] >= 8)
			{
				c = 8-onHand;
				give += 8;
				onHand = 0;
				onHand = a[i]-c;
			}
			else
			{
				if(a[i]+onHand > 8)
				{
					onHand = a[i]+onHand-8;
					give += 8;
				}
				else
				{
					give += a[i]+onHand;
				}
			}
		day++;
		}
	}
	if(give >= k)
		cout << day << endl;
	else
		cout << -1 << endl;
	return 0;
}
