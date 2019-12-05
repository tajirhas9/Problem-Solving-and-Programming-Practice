#include <bits/stdc++.h>

using namespace std;

#define mx 100005
typedef vector <int> VI;

int n, q;
int par[mx];
VI tmp[mx];
bitset <mx> mark;

//debug
#ifdef tajir
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
            os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
            os << *it;
    }
    return os << "]";
}

template < typename T >
ostream &operator << ( ostream & os, const multiset< T > &v ) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    for(auto it = v.begin(); it != v.end(); ++it) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
        }
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () {
    cerr << endl;
}

template <typename T>
void faltu( T a[], int n ) {
    for(int i = 0; i < n; ++i) cerr << a[i] << ' ';
    cerr << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) {
    cerr << arg << ' ';
    faltu(rest...);
}
#else
#define dbg(args...)
#endif // tajir


int fnd(int u) {
    if (par[u] == u) return u;
    return par[u] = fnd(par[u]);
}

int main() {
    #ifdef tajir
        freopen("input.txt","r",stdin);
    #else
        //online submission
    #endif
    
    int tc; scanf("%d", &tc);
    int t = 0;
    while (tc--) {
        mark = 0;
        scanf("%d %d",&n, &q);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            tmp[i].clear();
        }

        printf("Case %d:\n", ++t);
        while (q--) {
            int c; scanf("%d", &c);
            if (c == 0) {
                int u, v; scanf("%d %d", &u, &v);
                int pu = fnd(u);
                int pv = fnd(v);
                if (pu == pv) continue;
                if (tmp[pu].size() > tmp[pv].size()) {
                    swap(pu, pv);
                }

                for (auto x : tmp[pu]) tmp[pv].push_back(x);
                par[pu] = pv;
                mark[pv] = 1;
            } else if (c == 1) {
                int u, T;
                scanf("%d %d", &u, &T);
                int pu = fnd(u);
                tmp[pu].push_back(T);
                mark[pu] = 1;
            } else {
                int u, l, r;
                scanf("%d %d %d", &u, &l, &r);
                int pu = fnd(u);
                int ans = 0;
                if (mark[pu]) {
                    sort(tmp[pu].begin(), tmp[pu].end());
                    mark[pu] = 0;
                }

                auto lt = lower_bound(tmp[pu].begin(), tmp[pu].end(), l);
                auto rt = upper_bound(tmp[pu].begin(), tmp[pu].end(), r);

                if (rt > lt) ans = rt - lt;
                printf("%d\n", ans);
            }
        }
    }

    timeStamp;
}