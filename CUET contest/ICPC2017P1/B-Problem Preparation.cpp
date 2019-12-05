#include <bits/stdc++.h>
using namespace std;
int t,n,a[200],easiest = 20000,hardest=-200000,countEasy=0;
bool problemLess = false,easyNot1=false,easyLess=false,difError=false;
void reset(void);
int main()
{
	int i,j;
	cin >> t;
	while(t--)
	{
		reset();
		cin >> n;
		if(n<10 || n>13)	problemLess = true;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(easiest > a[i])
			{
				easiest = a[i];
				countEasy = 0;
			}
			if(easiest == a[i])
				countEasy++;
			if(hardest < a[i])	hardest = a[i];
		}
		if(easiest != 1)	easyNot1 = true;
		if(countEasy < 2)	easyLess = true;
		for(i=1;i<=n;i++)
		{
			for(j=i+1;j<=n;j++)
			{
				if(a[i] > a[j])
					swap(a[i],a[j]);
			}
		}
		//cout << problemLess << " " << easyNot1 << " " << easyLess << endl;
		for(i=1,j=2;j<=n;i++,j++)
		{
			if(a[j] == hardest)	continue;
			if(abs(a[i]-a[j]) > 2)
			{
				difError = true;
				break;
			}
		}
		if(problemLess==false && easyNot1==false && easyLess==false && difError==false)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
void reset(void)
{
	easiest = 200000;
	hardest = -20000;
	countEasy = 0;
	problemLess = false;
	easyNot1 = false;
	easyLess = false;
	difError = false;
}
