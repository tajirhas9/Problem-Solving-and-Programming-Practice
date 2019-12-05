#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int a,i,sum=0;
	for(i=1;i<=5;i++)
	{
		cin >> a;
		sum += a;
	}
	if(!(sum%5) && sum)	cout << sum/5;
	else 			cout << -1;
	return  0;
}


