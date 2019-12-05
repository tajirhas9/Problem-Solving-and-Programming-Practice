#include <bits/stdc++.h>
using namespace std;
void lucky(void);
bool isLuck[1005];
int main()
{
	lucky();
	int x;
	cin >> x;
	if(isLuck[x])
	{
		cout << "YES" << endl;
		return 0;
	}
	else
	{
		for(int i=4;i*2<=x;i++)
		{
			if(isLuck[i])
			{
				if(x%i==0)
				{
					cout << "YES" << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
void lucky(void)
{
	memset(isLuck,false,sizeof(isLuck));
	for(int i=4;i<= 774;i++)
	{
		int temp,r;
		temp = i;
		while(temp > 0)
		{
			r = temp%10;
			if(r != 4 && r != 7)
				break;
			temp /= 10;
		}
		if(temp==0)
		{
			isLuck[i] = true;
		}
	}
}
