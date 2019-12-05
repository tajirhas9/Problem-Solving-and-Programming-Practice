#include<bits/stdc++.h> /*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including */
using namespace std;
//using namespace __gnu_pbds;

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

/*
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
*/

//#Defines
#define rep(i,a,b)	for(i=a;i<=b;i++)
#define repR(i,a,b)	for(i=a;i>=b;i--)
//#define pb push_back
#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()

class Deque {
	ll a[112345] , fIndex = -1, bIndex = 0, size;
	bool isFull() {
		return ((fIndex==0 && bIndex == size-1) || (fIndex == bIndex+1));
	}
public:
	void create(ll n) {
		size = n;
		bIndex = n-1;
		fIndex = -1;
	}
	void push_front(ll x) {
		if(fIndex == -1) {
			fIndex = 0;
			bIndex = 0;
		}
		else if(fIndex == 0) {
			fIndex = size-1;
		}
		else
			fIndex = fIndex-1;
		a[fIndex] = x;
	}
	void push_back(ll x) {
		if(fIndex == -1) {
			fIndex = 0;
			bIndex = 0;
		}
		else if(bIndex == size - 1) {
			bIndex = 0;
		}
		else
			bIndex++;
		a[bIndex] = x;
	}
	void pop_front() {
		if(fIndex  == bIndex) {
			fIndex = -1;
			bIndex = -1;
		}
		else {
			if(fIndex == size - 1 )
				fIndex = 0;
			else
				fIndex++;
		}
	}
	void pop_back() {
		if(fIndex == bIndex) {
			fIndex = -1;
			bIndex = -1;
		}
		else if(bIndex == 0)
			bIndex = size -1;
		else
			bIndex--;
	}
	ll front() {
		return a[fIndex];
	}
	ll back() {
		return a[bIndex];
	}
	ll size() {
		return (abs(bIndex-fIndex)+1);
	}
};

int main()
{
	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif
	Deque q;
	ll T,n,m,x;
	string s;
	cin >> T;
	for(ll kase = 1; kase <= T; kase++) {
		cin >> n >> m;
		q.create(n);
		cout << "Case " << kase << ":\n";
		while(m--) {
			cin >> s;
			if(s.compare("pushLeft") == 0) {
				cin >> x;
				if(q.size() == n) {
					cout << "The queue is full\n";
				}
				else {
					q.push_front(x);
					cout << "Pushed in left: " << x << endl;
				}
			}
			else if(s.compare("pushRight") == 0) {
				cin >> x;
				if(q.size() == n) {
					cout << "The queue is full\n";
				}
				else {
					q.push_back(x);
					cout << "Pushed in right: " << x << endl;
				}
			}
			else if(s.compare("popLeft") == 0) {
				if(q.size() == 0) {
					cout << "The queue is empty\n";
				}
				else {
					x = q.front();
					q.pop_front();
					cout << "Popped from left: " << x << endl;
				}
			}
			else if(s.compare("popRight") == 0) {
				if(q.size() == 0) {
					cout << "The queue is empty\n";
				}
				else {
					x  = q.back();
					q.pop_back();
					cout << "Popped from right: " << x << endl;
				}
			}
		}
	}
	return 0;
}






//?
