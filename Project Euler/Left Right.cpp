#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,ans,T,k,kase;
    scanf("%d",&T);
    for(kase = 1; kase <= T; ++kase) {
        scanf("%d",&k);
        ans = 0;
        for(int i = 1; i <= k; ++i) {
        	scanf("%d %d",&a,&b);
        	ans ^= (b-a-1);
        }
        printf("Case %d: ", kase);
        if(ans == 0)
            printf("Bob\n");
        else
            printf("Alice\n");
    }
   
    return 0;
}