#include <bits/stdc++.h>
using namespace std;
void reset(void);
int a[1000],store[1000];
int n=1000,l,q,r,t,w,flag = 0,maxim=0;
int main()
{
	//freopen("E.txt","r",stdin);
	int i,j,k,stored=0;
	cin >> t;
	for(i=1;i<=t;i++)
	{
		reset();
		cin >> n >> q;
		for(j=1;j<=q;j++)
		{
			cin >> l >> r >> w;
			if(w > maxim)	maxim = w;
			for(k = l;k<=r;k++)
			{
				if(a[k] == w)
				{
					//cout << "Trapped here" << endl;
					flag =1;
					break;
				}
			}
			if(flag == 1)	
			{
				flag = 0;
				continue;
			}
			//cout << "Reached" << endl;
			if(a[r] == -1)
			{
				a[r] = w;
				//cout << "Stored in maximum" << endl;
			}
			else if(a[l] == -1)
			{
				a[l] = w;
				//cout << "Stored in minimum" << endl;
			}
			else
			{
				for(k = l;k<=r;k++)
				{
					if(a[k] == -1)
					{
						a[k] = w;
						//cout << "Stored in between" << endl;	
						stored  = 1;
						break;
					}
				}
			}
		}
		maxim++;
		for(j=1;j<=n;j++)
		{
			if(a[j] == -1)
			{
				a[j] = maxim;
				maxim++;
			}
		}
		cout << "Case " << i << ": ";
		for(j=1;j<=n;j++)
			cout << a[j] << " ";
		cout << endl;
	}
	return 0;
}
void reset()
{
	int x;
	flag = 0;
	maxim=0;
	for(x=0;x<=n;x++)
	{
		a[x] = -1;
	}
}
