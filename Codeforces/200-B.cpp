#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,sum=0,total=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		sum += x;
		total += 100;
	}
	printf("%.10lf\n",(double)(((double)sum/(double)total)*100));
	return  0;
}


