#include<bits/stdc++.h> 
using namespace std;

//typedefs

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

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	optimize();
	
	string s,p;

	int n,pos=0;
	bool flag = false;
	cin >> n;
	cin >> s;

	if(n == 1) {
		cout << s << endl;
		return 0;
	}

	for(int i = 0; i < n-1; ++i) {
		if(s[i] > s[i+1] && !flag) {
			flag = true;
			pos = i;
			break;
		}
	}

	if(flag) {
		for(int i = 0; i < n; ++i) {
			if(i == pos)	continue;
			cout << s[i];
		}
	}
	else {
		for(int i = 0; i < n-1; ++i)
			cout << s[i];
	}
	cout << endl;
	
	return 0;
}






//?
