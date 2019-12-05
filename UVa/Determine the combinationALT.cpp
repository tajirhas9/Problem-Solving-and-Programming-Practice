#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define all(v)	v.begin(),v.end()

int n;

void print( vector<char> v, int indx ,int cnt, char s[])	{
	bool flag = false;
	s[cnt] = v[indx];
	if(cnt >= (n-1))	{
		printf("%s\n", s);
		return;
	}
	for(int i=indx+1; i< v.size(); ++i){
		s[cnt+1] = v[i];
		if(v[i] == v[i-1] && i > (indx+1))	continue;
		print(v, i, cnt+1,s);
	}
}

int main()
{
	char s[30000],s1[30000];
	vector<char> v;

	while((scanf(" %s %d",s,&n) != EOF)) {
		int strln = strlen(s);

		for(int i=0; i< strln; ++i )
			v.pb(s[i]);
		
		sort(all(v));
		
		for(int i=0; i< v.size(); ++i)	{
			if(v[i] == v[i-1])	continue;
			for(int i=0; i< strln; i++)	s1[i] = '\0';
			print(v,i,0,s1);
		}
		
		v.clear();
		for(int i=0; i< strln; i++)	s[i] = '\0';
	}
	return 0;
}