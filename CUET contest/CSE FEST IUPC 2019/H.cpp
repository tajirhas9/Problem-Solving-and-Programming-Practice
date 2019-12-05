#include <bits/stdc++.h>
using namespace std;

#define all(c)    c.begin(),c.end()

int main() {

    #ifdef tajir
        freopen("input.txt","r",stdin);
    #else
        //online submission
    #endif
    
//    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int T;

    scanf("%d",&T);

    for(int kase = 1; kase <= T; ++kase) {
        int n,X;
        scanf("%d %d",&n,&X);

        vector < int > c(n);

        for(int i = 0; i < n; ++i)
            scanf("%d",&c[i]);

        vector < int > pair_sum;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j)
                pair_sum.push_back(c[i]+c[j]);
        }

        set < int > Set;

        for(auto x : pair_sum)
        	Set.insert(x);

        int sz = pair_sum.size();

        bool flag = false;

       for(auto x : Set) {
            int y = X-x;

            flag |= binary_search(all(pair_sum) , y);
        }

        printf("Case %d: ", kase);
        if(flag)
            printf("HIGH\n");
        else
            printf("LOW\n");
    }
    return 0;
}