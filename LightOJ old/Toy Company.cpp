#include <bits/stdc++.h>
#include <set>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
#define cin1(x) scanf("%d",&x)
#define ui unsigned int
void dfs(string s,int count);
string start,finish;
int n,c=0;
int f1[15] = {-1,-1,-1,-1,0,0,0,0,0,0,0,1,1,1,1};
int f2[15] = {-1,-1,0,0,-1,-1,0,0,0,1,1,0,0,1,1};
int f3[15] = {-1,0,-1,0,-1,0,-1,0,1,0,1,0,1,0,1};
set <string> banned;
bool setX=false,possible=true;

int main()
{
	int T;
	cin1(T);
	getchar();
	for(int i=1;i<=T;i++)
	{
		setX = false;
		cin >> start >> finish;
		cin1(n);
		getchar();
		for(int i=0;i<n;i++)
		{
			string s1,s2,s3;
			cin >> s1 >> s2 >> s3;
			for(ui j=0;j<s1.length();j++)
			{
				for(ui k=0;k<s2.length();k++)
				{
					for(ui l=0;l<s3.length();l++)
					{
						char s[3];
						s[0] = s1[j];
						s[1] = s2[k];
						s[2] = s3[l];
						banned.insert(s);
					}
				}
			}
		}
		dfs(start,0);
		if(!possible)
		{
			printf("Case %d: -1\n",i);
		}
		else
			printf("Case %d: %d\n",i,c);
		c=0;
	}
	return 0;
}
void dfs(string s,int count)
{
	if(s == finish)
	{
		if(!setX)	{c = count; setX = true; return;}
	}
	if(!possible)	return;
	for(int i=0;i<15;i++)
	{
		char v[3];
		v[0] = s[0]+f1[i];
		v[1] = s[1]+f2[i];
		v[2] = s[2]+f3[i];
		if(v[0] < 'a')	v[0] = 'z';
		if(v[1] < 'a')	v[1] = 'z';
		if(v[2] < 'a')	v[2] = 'z';
		if(v[0] > 'z')	v[0] = 'a';
		if(v[1] > 'z')	v[1] = 'a';
		if(v[2] > 'z')	v[2] = 'a';
		if(banned.count(v) != 0)	continue;
		if(count > 16)  {possible = false;}
		cout << count << " " <<  s << " "  << v << " " << count  << " ("<< f1[i] << ", " <<f2[i]  << ". "<< f3[i] << ")"<< endl;
		dfs(v,count+1);
	}
}
