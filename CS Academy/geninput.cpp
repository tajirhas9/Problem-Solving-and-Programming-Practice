#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b)	for(i=a;i<=b;i++)
typedef long long ll;
vector < string > v;
void solve(string s , int len) {
    if(len > 4) return;
    v.push_back(s);
    string p = s;
    p += 'c';
    solve(p , len+1);
    p.clear();
    p = s;
    p += 'd';
    solve(p , len + 1);
}

int main()
{
    fstream input;
    input.open("./input.txt",ios::out|ios::trunc);
    ll n;
    string a;
    a += 'c';
    solve(a,1);
    a.clear();
    a += 'd';
    solve(a,1);
    for(int i = 0; i < v.size(); ++i)
        input << v[i] << " ";
    input << endl;
    input.close();
    cout << "done" << endl;
    return 0;
}
