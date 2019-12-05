#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	int c=0;
	char s[105];
	scanf("%s",s);
	if(strstr(s,"Danil"))	c++;
	if(strstr(s,"Olya"))	c++;
	if(strstr(s,"Slava"))	c++;
	if(strstr(s,"Ann"))		c++;
	if(strstr(s,"Nikita"))	c++;
	if(c==1)	printf("Yes\n");
	else 	printf("No\n");
	return 0;
}
