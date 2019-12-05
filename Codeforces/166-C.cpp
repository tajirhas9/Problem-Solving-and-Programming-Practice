#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define FOR(i,n)	for(i=0;i<n;i++)
#define mp(x,y)		make_pair(x,y)
#define pb(x)		push_back(x)
#define all(x)	x.begin(),x.end()
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef set<ll> setL;
typedef set<string> setS;
deque<ll> q;
int main()
{
	ios_base::sync_with_stdio(0);
	ll med,i,n,x,a[1234],step=0,temp;
	bool flag = false;
	cin >> n >> x;
	for(i=0;i<n;i++)
	{
		cin >> a[i];
		if(x==a[i])	flag = true;
	}
	sort(a,a+n);
	for(i=0;i<n;i++)	q.push_back(a[i]);
	med = floor((n+1)/2);
	med--;
	if(x==a[med])
	{
		cout << step << endl;
		return 0;
	}
	else if(x<a[med])
	{
		deque<ll>::iterator it;
		ll pos = -1;
		if(!flag)	temp = x;
		else	temp = x-1;
		while(pos != med)
		{
			step++;
			q.push_front(temp--);
			sort(q.begin(),q.end());
			n = q.size();
			med = floor((n+1)/2);
			med--;
			for(it=q.begin(); it != q.end(); it++)
			{
				ll index = (ll)(it-q.begin());
				//cout << *it << " ";
				if((*it)==x)
				{
					if(index <= med)
					pos = index;
					//if(pos>=med)	
						//break;
				}
			}
		}
	}
	else
	{
		deque<ll>::iterator it;
		ll pos = -1;
		if(!flag)	temp = x;
		else 		temp = x+1;
		while(pos != med)
		{
			step++;
			q.push_back(temp++);
			sort(q.begin(),q.end());
			n = q.size();
			med = floor((n+1)/2);
			med--;
			//cout << step << "   "; 
			//cout << med << "   ";
			for(it=q.begin(); it != q.end(); it++)
			{
				ll index;
				index = (ll)(it-q.begin());
				//cout << *it << " ";
				if((*it)==x)
				{
					if(index <= med)
						pos = index;
					//if(pos>=med)	
						//break;
				}
			}
			//cout << endl;
		}
	}
	cout << step << endl;
	return  0;
}













//?

