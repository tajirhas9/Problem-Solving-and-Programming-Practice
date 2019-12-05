#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long
int main()
{
	long long count=0,n,i;
	string init,fin;
	cin >> n >> init >> fin;
	for(i=0;i<n;i++)
	{
		long long in,f,right,left;
		in = init[i]-'0';
		f = fin[i]-'0';
		right = abs(in-f);
		left =10-right;
		count += min(right,left);
	}
	cout << count << endl;	
	return  0;
}


