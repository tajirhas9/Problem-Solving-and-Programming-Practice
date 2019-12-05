#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define pii pair<int,int>
void dfs(int s,int cycle,int scale1,int scale2);
vector<int> v[2000];
queue<int>q;
set <int> weight;
set<vector<int>> seq;
vector<int> temp;
int m,pos=0;
bool flag=false;
//int scale1=0,scale2=0,prev=-1;
int main()
{
	char s[11];
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		if(s[i] == '1')	weight.insert(i+1);
	}
	scanf("%d",&m);
	dfs(0,1,0,0);
	q.push(0);
	set<vector<int>>::iterator it;
	if(!flag)
	cout << "NO" << endl;
	return 0;
}
void dfs(int s,int cycle,int scale1,int scale2)
{
	if(cycle>m)	return;
	if(cycle%2 && !flag)
	{
		set<int>::iterator it;
		set<int>::iterator f_it = weight.end();
		--f_it;
		for(it = weight.begin();it != weight.end();it++)
		{
			if(*it != s && scale1+*it>scale2)
			{
				//scale1 += *it;
				temp.push_back(*it);
				if(it != f_it)
					pos = temp.size();
				//cout << "Scale 1: " << *it << " ";
				dfs(*it,cycle+1,scale1+*it,scale2);
				seq.insert(temp);
				for(int p=0;p<temp.size();p++)	cout << temp[p] << " ";
				cout << endl;
				if(temp.size()==m)
				{	
					cout << "YES" << endl;
					for(int p=0;p<temp.size();p++)	cout << temp[p] << " ";
					cout << endl;
					flag=true;
				}
				temp.erase(temp.begin()+pos,temp.end());
				pos=0;
			}
		}
	}
	else if(!flag)
	{
		set<int>::iterator it;
		set<int>::iterator f_it=weight.end();
		--f_it;
		for(it = weight.begin();it != weight.end();it++)
		{
			if(*it != s && scale2+*it>scale1)
			{
				//scale2 += *it;
				temp.push_back(*it);
				if(it != f_it)
					pos = temp.size();
				//cout << "Scale 2: " << *it << " ";
				dfs(*it,cycle+1,scale1,scale2+*it);
				seq.insert(temp);
				for(int p=0;p<temp.size();p++)	cout << temp[p] << " ";
				cout << endl;
				if(temp.size() == m)
				{	
					cout << "YES" << endl;
					for(int p=0;p<temp.size();p++)	cout << temp[p] << " ";
					cout << endl;
					flag = true;
				}
				temp.erase(temp.begin()+pos,temp.end());
				pos=0;
			}
		}
	}
}
