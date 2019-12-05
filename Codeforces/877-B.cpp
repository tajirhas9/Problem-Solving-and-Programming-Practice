#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	char s[5005];
	int got1,got2,i,j,l;
	bool got1a,got2a;
	got1a = got2a = false;
	scanf("%s",s);
	l = strlen(s);
	for(i=0,j=l-1;i<l;i++,j--)
	{
		if(s[i] == 'a' && !got1a)
		{
			got1 = i;
			got1a = true;
		}
		if(s[j] == 'a' && !got2a)
		{
			got2 = j;
			got2a = true;
		}
		if(got1a && got2a)	break;
	}
	if(got2==got1)
	{
		if(got1 == (l-1))
			got1a = false;
		else
			got2a = false;
	}
	if(got1a && got2a)
		l = (got2-got1)+1;
	else if(!got2a)
		l = (strlen(s)-got1);
	else if(!got1a)
		l = (got2-0)+1;
	if(got1a)
	{
		for(i=got1+1;i<got2;i++)
		{
			if(s[i] == 'a')	l--;
		}
	}
	else
	{
		for(i=got2-1;i>=0;i--)
		{
			if(s[i] == 'a')	l--;
		}
	}
	bool altB;
	int altL=0;
	altB=false;
	/*if(!got1a)
	{
		for(i=0;i<strlen(s);i++)
		{
			if(s[i] == 'b' && !altB)
			{
				altB = true;
				altL++;
				for(int j=i+1;j<strlen(s);j++)
				{
					altL++;
					if(s[j] == 'a')	break;
				}
			}
		}
	}*/
	cout << max(l,altL) << endl;
	return 0;
}
