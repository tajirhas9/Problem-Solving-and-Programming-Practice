#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<int>::iterator vit;
typedef set<int>::iterator sit;

/*
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
*/

//#Defines
#define pb push_back
//#define pb emplace_back
#define F first
#define S second
#define all(c) c.begin() , c.end()
#define mp make_pair

#define RESET(a,b)	memset(a,b,sizeof(a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);



bool comp(pii const &a, pii const &b) {
	if(a.S == b.S)
		return a.F > b.F;
	return a.S < b.S;
}

int main()
{	
	int n,max_day=-1;
	map < int , int > M;
	vii v;

	cin >> n;

	v.resize(n);

	for(int i = 0; i < n; ++i)
		cin >> v[i].F;

	for(int i = 0; i < n; ++i) {
		cin >> v[i].S;
		max_day = max(max_day , v[i].S);
	}

	sort(all(v) , comp);


	for(auto x : v)
		M[x.S] = max(x.F , M[x.S]);

	int cur = 1;

	for(int i = cur; i <= max_day; ++i) {
		if(i % 3 == 0) {
			cout << 100 << " ";
			continue;
		}
		if(M[i] != 0)
			cout << M[i] << " ";
	}
	cout << endl;
	return 0;
}






//?
