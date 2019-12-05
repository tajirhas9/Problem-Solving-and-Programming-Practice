#include <bits/stdc++.h>
#include <cmath>
using namespace std;
double n,x,y,ri,i,r,d,c=0;
int main()
{	
	cin >> r >> d;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> x >> y >> ri;
		if(sqrt(x*x+y*y) >= (r-d+ri) && (sqrt(x*x+y*y)+ri) <= r)
			c++;
	}
	cout << c << endl;
	return 0;
}
