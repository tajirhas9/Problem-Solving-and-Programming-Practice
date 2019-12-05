#include <bits/stdc++.h>
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

//#Defines

//#define pb push_back
#define pb emplace_back
#define F first
#define S second
#define mp make_pair
#define all(c)		c.begin(),c.end()
#define endl '\n'
#define pf printf
#define sf scanf
#define MOD 1000000007
//#define harmonic(n) 0.57721566490153286l+log(n)

#define RESET(a,b)	memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;

template <class T, int n> struct Trie {
    int words, prefixes;
    Trie <T, n> **children;

    Trie (): words(0), prefixes(0), children (NULL) {}

    int value (typename T::const_iterator it) {
        // return *it; // for integers
        return *it - 'a'; // for lowercase strings
        // return *it - 'A'; // for uppercase strings
        // return 'a' <= *it && *it <= 'z' ? *it - 'a' : *it - 'A' + 26; // for both lower and uppercase strings
        // return *it - '0'; // for integer strings
    }

    void Insert (typename T::const_iterator it, typename T::const_iterator end, int val = 1) {
        prefixes += val;
        if (it != end) {
            int i = value(it);
            if (!children) {
                children = new Trie <T, n> *[n] ();
            }
            if (!children[i]) {
                children[i] = new Trie <T, n> ();
            }
            children[i]->Insert(++it, end, val);
        } else {
            words += val;
        }
    }

    void Insert (const T& word, int val = 1) {
        Insert(word.begin(), word.end(), val);
    }

    pair <int, int> Count (typename T::const_iterator it, typename T::const_iterator end) {
        if (it == end) {
            return make_pair (words, prefixes);
        } else {
            int i = value(it);
            return children[i] ? children[i]->Count(++it, end) : make_pair(0, 0);
        }
    }

    pair <int, int> Count (const T& word) {
        return Count(word.begin(), word.end());
    }
/*
    void Print (int tab = 0) {
        cout << "Words: " << words << ", Prefixes: " << prefixes << ", Childrens:" << endl;
        for (int i = 0; i < n; ++i) if (children[i]) {
                cout << setw(tab) << i << " -> ";
                children[i]->Print(tab + 4);
            }
    }
*/
    ~Trie () {
        if (children) {
            for (int i = 0; i < n; ++i) if (children[i]) {
                    delete children[i];
                }
            delete[] children;
        }
    }
};

int main() {
	
	optimize();

	#ifdef tajir
		freopen("input.txt", "r", stdin);
	#else
		// online submission
	#endif

	string s[1001];
	int n=0;
	Trie < string , 26 > T;

	while(cin>>s[n]) {
		T.Insert(s[n++]);
	}

	for(int i = 0; i < n; ++i) {
		string p = s[i];
		string x;
		bool flag = false;
		for(int j = 0; j < p.size(); ++j) {
			x += p[j];
			pii data = T.Count(x);
			if(data.S == 1) {
				cout << p << " " << x << endl;
				flag = true;
				break;
			}
		}
		if(flag)	continue;
		cout << p << " " << x << endl;
	}

	return 0;
}