#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int main()
{
    string s;
    ll i,j,k,l,m,n,t,cs=1,res;
    scanf("%lld",&t);
    while(t--)
    {
        bool mark=false;
        char g[100008];
        scanf("%s",g);
        s=string(g);
        if(s.size()==1 && s[0]=='W')
        {
            printf("Case %lld: 3\n",cs++);
            continue ;
        }
        ll ans,w=0,answ=1,anscon=1;
        ll cnt= 0;
        for(i= 0 ; i<s.size()-1; i++)
        {
            if(s[i]=='W')
            {
                mark=true;
                if(s[i]==s[i+1])
                {
                    anscon =(anscon * 2) ;
                    cnt++;
                }
                else
                {
                    if(s[i-1]==s[i+1])
                    {
                        answ = (answ*2);
                    }
                }
            }
        }
        //cout<<cnt+1<<endl;
        if(cnt+1 == s.size())
        {
            anscon *= 3;
        }
        else
        {
            if(cnt+1>1)
            {
                anscon =(anscon * 2);
            }
        }
        if(s[s.size()-1]=='W')
        {
            if(s[s.size()-2]!=s[s.size()-1])answ= (answ*2);
            mark=true;
        }
        res = ((anscon%M) * (answ%M))%M ;
        if(!mark)res=0;
        printf("Case %lld: %lld\n",cs++,res);
        //  cout<<answ*anscon<<endl;
    }
}