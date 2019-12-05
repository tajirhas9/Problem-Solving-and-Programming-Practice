#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
int n,a[MAX];
int prefixSum(int r);
int suffixSum(int r);
int main()
{
	int i,index=MAX,index1,s,t;
	cin >> t;
	while(t--)
	{	
		cin >> n;
		for(i=1;i<=n;i++)		cin >> a[i];
		for(i=1;i<=n;i++)
		{
			index1 = prefixSum(i)+suffixSum(i);
			//cout << prefixSum(i) << " " << suffixSum(i) << endl;
			if(index1 < index)		
			{
				index = index1;
				s = i;
			}
		}
		cout << s << endl;
		index = MAX;
	}
	return 0;
}
int prefixSum(int r)
{
	int sum=0;
	for(int i=1;i<=r;i++)	sum += a[i];
	return sum;
}
int suffixSum(int r)
{
	int sum=0;
	for(int i = n; i>= r;i--)		sum += a[i];
	return sum;
}
