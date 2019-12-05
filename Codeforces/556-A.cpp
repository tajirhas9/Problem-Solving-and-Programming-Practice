#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
vector <int> v;
int main()
{
	int n,x,y,zero=0,one=0;
	string s;
	bool changed=false;
	cin >> n >> s;
	for(int i=0;i<n;i++)
	{
		v.push_back(s[i]-'0');
		if(s[i] == '0')	zero++;
		else 	one++;
	}
	cout << n-(min(zero,one)*2) << endl;
	/*while(1)
	{
		changed = false;
		for(int i=0;i+1<v.size();i++)
		{
			x = v[i];
			y = v[i+1];
			if((x==0 && y==1) || (x==1 && y==0))
			{
				v.erase(v.begin()+i);
				v.erase(v.begin()+i);
				n-=2;
				changed=true;
			}
			if(v.empty())	break;
		}
		if(!changed)	break;
		if(v.empty())	break;
	}
	cout << n << endl;*/
	return  0;
}


