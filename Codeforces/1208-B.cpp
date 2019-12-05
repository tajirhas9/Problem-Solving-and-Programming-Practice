#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

vector < int > a;

bool check(map < int , int > Map) {
    map < int , int > :: iterator it;

    for( it = Map.begin(); it != Map.end(); ++it) {
        if(it->second > 1)   return false;
    }
    return true;
}

bool isOk(int x) {
//    cout << "X : " << x << endl;
    map < int , int > Map;

    for(int i = 1; i <= n; ++i)
        Map[a[i]]++;

    map < int , int > :: iterator it;
/*
    for( it = Map.begin(); it != Map.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
    cout << endl << endl;
*/
    for(int i = 1 , j = 1+x-1; j <= n; ++i, ++j) {
        for(int k = i; k <= j; ++k)
            Map[a[k]]--;
/*
        cout << "i  : " << i << " " << " j : " << j << endl;
        for( it = Map.begin(); it != Map.end(); ++it) {
            cout << it->first << " : " << it->second << endl;
        }
        cout << endl << endl;
*/
        if(check(Map))
            return true;
        for(int k = i; k <= j; ++k)
            Map[a[k]]++;
    }
    return false;
}

int main() {

    cin >> n;

    a.resize(n+1);

    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    int lo = 0 , hi = n, loop = 400;

    while(lo < hi && loop--) {
        int mid = (lo+hi)/2;

        if(isOk(mid))
            hi = mid;
        else
            lo = mid+1;
    }

    if(isOk(lo))
        hi = lo;

    cout << hi << endl;

    return 0;
}
