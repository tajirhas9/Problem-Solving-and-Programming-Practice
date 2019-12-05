#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long
struct data
{
	ll a,b,area,id;
};
bool operator < (const data &l, const data &r) { return l.area < r.area; }
vector <data> packet;
vector <ll> store;
int main()
{
	ll i,n,w,h;
	cin >> n >> w >> h;
	for(i=1;i<=n;i++)
	{
		ll x,y;
		data z;
		cin >> x >> y;
		if((x>w && y > h))
		{
			packet.push_back(data());
			z.a = x;
			z.b = y;
			z.area = x*y;
			z.id = i;
			packet.push_back(z);
		}
	}
	sort(packet.begin(),packet.begin()+packet.size());
	for(i=0;i<packet.size();i++)
	{
		if(packet[i].)
	}
	return  0;
}

