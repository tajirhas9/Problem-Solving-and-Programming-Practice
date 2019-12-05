#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long T,n,r,change=0,x,fin,init=1500;
	cin >> T;
	while(T--)
	{
		cin >> n >> r;
		while(n--)
		{
			cin >> x;
			init += x;
		}
		if(init==r)	cout << "Correct" << endl;
		else 		cout << "Bug" << endl;
		init = 1500;
	}
	return 0;
}
