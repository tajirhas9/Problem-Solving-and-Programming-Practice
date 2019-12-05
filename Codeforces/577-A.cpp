#include <bits/stdc++.h>
#include <map>
using namespace std;
map<int,int> m_table;
int main()
{
	long long x,y,count=0;
	cin >> x >> y;
	for(long long i=1;i<=x;i++)
	{
		if(y%i==0 && i*x >= y)	count++;
	}
	cout << count << endl;
	return 0;
}
