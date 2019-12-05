#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
bool primes[1005];
void seive(void);
vector<int> primeSet;
int main()
{
	seive();
	int n,c;
	while((scanf("%d %d",&n,&c)) != EOF)
	{
		for(int i=1;i<=n;i++)
		{
			if(!primes[i])
			{
				primeSet.push_back(i);
			}
		}
		cout << n << " " << c << ":";	
		if(primeSet.size()%2==0)
		{
			if(2*c < primeSet.size())
			{
				int start,end;
				start = (primeSet.size()/2)-(c-1)-1;
				end = start+2*c;
				for(int i = start;i <end;i++)
					cout << " " << primeSet[i];
			}
			else
			{
				for(int i=0;i<primeSet.size();i++)
					cout << " " <<  primeSet[i];
			}
		}
		else
		{
			if((2*c-1) < primeSet.size())
			{
				int start,end;
				start = (primeSet.size()/2)-(c-1);
				end = start+(2*c-1);
				for(int i=start;i<end;i++)
					cout << " " << primeSet[i];
			}
			else
			{
				for(int i=0;i<primeSet.size();i++)
					cout << " " << primeSet[i];
			}
		}
		cout << endl << endl;
		primeSet.clear();
	}
	return 0;
}
void seive(void)
{
	memset(primes,false,sizeof(primes));
	for(int i=2;i*i<=1005;i++)
	{
		if(!primes[i])	//if prime
		{
			for(int j=i*i;j<=1005;j+=i)
			{
				primes[j] = true;
			}
		}
	}
}
