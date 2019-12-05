#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int k,r,i=1,c;
	cin >> k >> r;
	c = k;
	while(c%10!=r && c%10!=0)
	{
		c += k;
		i++;
	}
	cout << i << endl;
	return  0;
}
