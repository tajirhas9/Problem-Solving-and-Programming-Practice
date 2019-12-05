#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main()
{
	char s[2000];
	int l,i,x=0,y=0;
	scanf("%s",s);
	l = strlen(s);
	for(i=0;i<l;i++)
	{
		if(s[i] == 'N')	y++;
		else if(s[i] == 'S')	y--;
		else if(s[i] == 'E')	x++;
		else if(s[i] == 'W')	x--;
	}
	cout << abs(x)+abs(y) << endl;
	return 0;
}
