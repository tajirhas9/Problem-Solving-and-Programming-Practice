#include <bits/stdc++.h>
using namespace std;
int countDivisor(int n);
int main()
{
	int k,t,i,j,n,count[2000],number[2000];
	for(i=1;i<=1000;i++)
	{
		count[i] = countDivisor(i);
	}
	k=1;
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=1000;j++)
		{
            if(count[j] < count[i] && count[j] != -1)
			{
				number[k] = j;
			}
			else if(count[i]==count[j] && j > i && count[j] != -1)
			{
				number[k] = j;
			}
		}
		count[number[k]] = -1;
		k++;
	}
	number[1] = 1;
	for(i=1;i<=1000;i++)
        cout << number[i] << " ";
    cout << endl;
	cin >> t;
	for(i=1;i<=t;i++)
	{
		cin >> n;
		cout << "Case " << i << ": " << number[n] << endl;
	}
	return 0;
}
int countDivisor(int n)
{
	int count=0,i;
	for(i=1;i<=(n/2);i++)
	{
		if(n%i==0)
			count++;
	}
	return count;
}
