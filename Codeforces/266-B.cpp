#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define input(n) scanf("%d",&n);
char s[60];
int n,t;
int main()
{
	int i,j;
    input(n);
    input(t);
    scanf("%s",s);
    for(i=1;i<=t;i++)
    {
		for(j=0;j<n;j++)
		{
			if(s[j] == 'B' && s[j+1] == 'G')
			{
				swap(s[j],s[j+1]);
				j++;
			}
		}
	}
	printf("%s\n",s);
    return 0;
}
