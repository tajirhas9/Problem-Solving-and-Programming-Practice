#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[101],c;
	string w[3];
	w[0] = "qwertyuiop";
	w[1] = "asdfghjkl;";
	w[2] = "zxcvbnm,./";
	int l;
	cin >> c;
	scanf("%s",s);
	l = strlen(s);
	for(int i=0;i<l;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k< w[j].length();k++)
			{
				if(w[j][k]== s[i])
				{
					if(c=='L')	putchar(w[j][k+1]);
					else 		putchar(w[j][k-1]);
				}
			}
		}
	}
	printf("\n");
	return 0;
}
