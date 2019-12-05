#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	char s[5005];
	int got1,got2,gotB,i,l;
	bool gotA1,gotA2,gotBa;
	gotA1 = gotA2 = gotBa =false;
	scanf("%s",s);
	l = strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i] == 'a' && !gotA1)
		{
			got1 = i;
			gotA1 = true;
			gotBa = false;
		}
		else if(s[i] == 'a' && gotA1 && got1 < i)
		{
			got2 = i;
			gotA2 = true;
		}
		else if(s[i] == 'b' && gotA1 && gotA2 && i > gotA1 && i < gotA2)
		{
			gotB = i;
			gotBa = true;
		}
		else if(s[i] == 'b' && !gotA1)
		{
			gotBa = true;
			gotB = i;
		}
	}
	cout << got2-got1+1 << endl;
	return 0;
}
