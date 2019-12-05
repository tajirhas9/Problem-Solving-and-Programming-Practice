#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[300],a[300];
	int l,i,k=0;
	scanf("%s",s);
	l = strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i] == '.')
		{	
			a[k] = '0';
			k++;
		}
		else if(s[i] == '-' && s[i+1] == '.')
		{
			a[k] = '1';
			k++;
			i++;
		}
		else if(s[i] == '-' && s[i+1] == '-')
		{
			a[k] = '2';
			k++;
			i++;
		}
	}
	a[k] = '\0';
	printf("%s\n",a);
	return 0;
}
