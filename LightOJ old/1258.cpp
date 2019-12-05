#include <bits/stdc++.h>
using namespace std;

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
#include <bits/stdc++.h>
using namespace std;

class Manachar {
private:
    int maxPalindrome=0, maxPalindromeSuffixSize=0;
    int n;
    string s,palindrome_substring, palindrome_suffix;
    vector < int > P;

    string convertToNewString(const string &s) {
        string newString = "@";

        for (int i = 0; i < s.size(); i++)
            newString += "#" + s.substr(i, 1);

        newString += "#$";
        return newString;
    }

    void longestPalindromeSubstring() {
        string Q = convertToNewString(s);
        int c = 0, r = 0;

        for (int i = 1; i < Q.size() - 1; i++) {
            int iMirror = c - (i - c);

            if(r > i) {
                P[i] = min(r - i, P[iMirror]);
            }

            while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]]){
                P[i]++;
            }

            if (i + P[i] > r) {
                c = i;        
                r = i + P[i];
            }
        }

        int centerIndex = 0;
        int centerIndexSuffix = 0;

        for (int i = 1; i < Q.size() - 1; i++) {

            if (P[i] > maxPalindrome) {
                maxPalindrome = P[i];
                centerIndex = i;
            }
            if (P[i] > maxPalindromeSuffixSize && i+P[i] == Q.size()-2 ) {
                maxPalindromeSuffixSize = P[i];
                centerIndexSuffix = i;
            }
        }  

        palindrome_substring = s.substr( (centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
        palindrome_suffix = s.substr( (centerIndexSuffix - 1 - maxPalindromeSuffixSize) / 2, maxPalindromeSuffixSize);
    }
public:
    Manachar(string str) {
        n = str.size();
        s = str;
        P.resize(4*n+100,0);
        longestPalindromeSubstring();
    }
    int getPalindromeSubStringSize() {
        return maxPalindrome;
    }

    string getPalindromeSubstring() {
        return palindrome_substring;
    }

    int getPalindromeSuffixSize() {
        return maxPalindromeSuffixSize;
    }
    string getPalindromeSuffix() {
        return palindrome_suffix;
    }

};


int main() {
    #ifdef tajir
        freopen("input.txt","r",stdin);
    #else
        //online submission
    #endif
    int T;

    cin >> T;

    for(int kase = 1; kase <= T; ++kase) {
        
        string s;
        cin >> s;

        Manachar lps(s);

        int sz = s.size() + s.size() - lps.getPalindromeSuffixSize();

        cout << "Case " << kase << ": " << sz << endl;
    }
    return 0;
}