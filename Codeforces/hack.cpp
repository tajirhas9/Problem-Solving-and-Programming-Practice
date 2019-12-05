#include <bits/stdc++.h>
using namespace std;
 
int q,n;
int a[505];
int cnt[10004];
set<int>pro;
int no;
 
int main(){
 
    cin >> q;
 
    while(q--){
        no = 0;
        memset(cnt, 0, sizeof cnt);
        memset(a, 0, sizeof a);
        pro.clear();
        cin >> n;
 
        for(int i = 1; i <= 4*n; ++i){
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i = 1; i <= 10001; ++i){
            if(cnt[i] % 2 == 1){
                no = 1;
                break;
            }
        }
        if(no){
            cout << "NO\n";
            continue;
        }
        sort(a+1, a + 4*n + 1);
 
        for(int i = 1; i <= 2*n; i += 2){
            pro.insert(a[i] * a[4*n-i+1]);
        }
        if(pro.size() == 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}