#include <bits/stdc++.h>
using namespace std;
double l,r,x,y,k,i,j;
int main()
{
	int flag = 0;
	cin >> l >> r >> x >> y >> k;
	for(i=y;i>=x;i--)
	{
		if(i*k <= r && i*k >= l)
			flag = 1;
	}	
	(flag == 0) ? cout << "NO" << endl : cout << "YES" << endl;
	return 0;
}

