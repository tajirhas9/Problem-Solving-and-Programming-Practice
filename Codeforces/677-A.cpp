#include <bits/stdc++.h>
using namespace std;
int main()
{
	int w=0,n,h,i,x;
	cin >> n >> h;
	for(i=1;i<=n;i++)
	{
		cin >> x;
		(x>h)? w+=2 : w++;
	}
	cout << w << endl;
	return 0;
}
