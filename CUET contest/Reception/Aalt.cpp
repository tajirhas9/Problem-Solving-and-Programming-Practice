#include <bits/stdc++.h>
using namespace std;
#define cin(x) scanf("%lld",&x)
#define cinS(x) scanf("%s",x)
#define cout(x) printf("%lld\n",x)
#define coutS(x) printf("%s\n",x)
typedef long long ll;
int main()
{
	ll l,T,i,j,mid;
	char s[1000005],s1[1000005];
	cin(T);
	while(T--)
	{
		cinS(s);
		l = strlen(s);
		l--;
		mid = l/2;
		for(i=0,j=l;i<=j; i++,j--)
		{
			if(i==j)
			{
				if(l%2)	continue;
				else
				{
					if((s1[i+1]-'0')<=(s[i+1]-'0'))
					{
						s1[i] = s[i];
						s1[i]++;
						break;
					}
					else
					{
						s1[i] = s[i];
					}
				}
			}
			if((j==i+1) && l%2)
			{
				if(s[j]>s[i])
				{
					s1[i] = s1[j] = s[i]+1;
				}
				else
				{
					s1[i] = s1[j] = s[i];
				}
			}
			else
			{
				s1[i] = s1[j] = s[i];
			}
		} 
		coutS(s1);
		for(ll i=0;i<=l;i++) {s1[i]='\0'; s[i] = '\0';}
	}
	return 0;
}

