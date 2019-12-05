#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,x,y,xNeg=0,xPos=0,i;
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> x >> y;
		if(x<0)	xNeg++;
		else if(x>0)	xPos++;
	}
	if(xNeg==1 || xPos==1 || xPos==n || xNeg==n)	cout << "Yes" << endl;
	else 					cout << "No" << endl;
	return 0;
}
