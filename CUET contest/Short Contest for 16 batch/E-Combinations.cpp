#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int fact(int n)
{
	if(n==0) return 1;
	return n*fact(n-1);
}
int combination(int n,int r)
{
	return fact(n)/(fact(r)*fact(n-r));
}
int main()
{
	int n,r,i,t;
	cin >> t;
	for(i=1;i<=t;i++)
	{
		cin >> n >> r;
		cout << "Case " << i << ": " << combination(n,r)%1000003 << endl;
	}
	return 0;
}
