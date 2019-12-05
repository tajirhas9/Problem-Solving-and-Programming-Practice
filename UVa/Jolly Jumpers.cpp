#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int n,a[5000],i,flag=0,b[5000],j=1;
    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            if(i==0)	continue;
            if(abs(a[i] - a[i-1]) < 1 || abs(a[i] - a[i-1]) >= n)
				flag = 1;
			else
			{
				b[j] = abs(a[i]-a[i-1]);
				j++;
			}
        }
        for(i=1;i<j;i++)
        {
			for(int k = i+1;k<j;k++)
			{
				if(b[i] > b[k])		swap(b[i],b[k]);
			}
		}
        for(i=1;i<j;i++)
        {
			if(b[i] != i)	flag = 1;
		}
        if(flag == 0)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
        flag = 0;
        j=1;
    }
    return 0;
}
