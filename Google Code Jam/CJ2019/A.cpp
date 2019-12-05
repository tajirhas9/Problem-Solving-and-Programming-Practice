#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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


ll N,a,b;
bool done = false;

bool isOk(ll x) {
    while(x) {
        int r = x % 10;
        x /= 10;
        
        if(r == 4)
            return false;
    }
    return true;
}

void solve(int idx, ll aa, int carry) {
 //   dbg(aa);
    if(idx > 1 && aa == 0)  return;
    if(aa >= N)   return;
    if(isOk(aa) && isOk(N-aa)) {
        a = aa;
        b = N-a;
        done = true;
        return;
    }

    int r = N % (ll)pow(10,idx+1);
    r -= carry;

    int i;

    if(r & 1)
        i = 0;
    else
        i = 1;
    
    for( ; i <= 9 && !done; i += 2) {
        
        if(i == 4)  continue;
        
        ll p = aa*10+i;
        if(p >= N)  continue;
        
        int r = N % (ll)pow(10,idx+1);
        r -= carry;
        if(r < i) {
            int c = 1;
            int sub = r+10-i;
            if(sub == 4)
                continue;
            solve(idx+1,aa*10+i,c);
        }
        else {
            int sub = r-i;
            if(sub == 4)
                continue;
            solve(idx+1,aa*10+i,0);
        }
    }
}

int main() {
    #ifdef tajir
        freopen("input.txt","r",stdin);
    #else
        //online submission
    #endif
    
    int T;
    cin >> T;
    
    for(int kase = 1; kase <= T; ++kase) {
        cin >> N;
        
        bool flag = false;
        
        solve(0,0,0);
        
        cout << "Case #" << kase << ": " << a << " " << b << endl;

        done = false;
    }
    return 0;
}