#include <bits/stdc++.h>
using namespace std;
#define MAX 300005
int a[300005],n,flagMin=MAX,flagMax=MAX,maxim=0,minim=MAX,maxDif,profit=0,changedMin=MAX;
bool check[300005];
int main()
{
	freopen("Buy Low Sell High.txt","r",stdin);
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<=n;i++)	check[i] = false;
	i=0;
	while(i<n)
	{
		if(check[i]==true)
		{
			i++;
			continue;
		}
		if(a[i] < minim)
		{
			minim = a[i];
			flagMin = i;
			cout << minim << endl;
		}
		else
		{
			changedMin = flagMin;
			for(j=i+1;j<n;j++)
			{
				if(a[j] == true)	continue;
				if(a[j] < minim)
				{
					minim = a[j];
					changedMin = j;
					j++;
				}
				if((a[j]-minim) > maxDif && j > changedMin)
				{
					maxDif = a[j]-minim;
					flagMax = j;
					flagMin = changedMin;
				}
			}
			if(flagMax != MAX && flagMin != MAX)
			{
				cout << maxDif << endl;
				check[flagMax] = true;
				check[flagMin] = true;
				cout << a[flagMin] << endl;
				flagMax = MAX;
				flagMin = MAX;
				changedMin = MAX;
				profit += maxDif;
				i=0;
				maxim = 0;
				minim = MAX;
				maxDif = 0;
				continue;
			}
			else 
			{
				i = n;
			}
		}
		if(i>=(n-1))	break;
		i++;
		
	}
	cout << profit << endl;
	return 0;
}
