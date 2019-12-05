#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1<<31
#define MAX 100005
#define PI 2*acos(0.0)
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define pf(a) printf("%lld\n", a)
#define Case(t) printf("Case %d: ", t)
#define pii pair<int, int>
#define MOD 1000000007

vector<pair<int,int> >v;
map<int, string>mp;

bool cmp(pair<int,int>a, pair<int,int>b)
{
    if(a.S == b.S)
        a.F < b.F;
    else
        a.S > b.S;
}

int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int roll, marks;
        string name;
        cin>>roll>>name>>marks;
        v.push_back({roll, marks});
        mp[roll] = name;
    }
    sort(v.begin(), v.end(), cmp);
    cout<<"Roll | Name       | Marks"<<endl;
    cout<<"-------------------------"<<endl;
    for(int i = 0; i < v.size(); i++)
    {
        cout<<setw(4)<<v[i].first<<" | "<<mp[v[i].first];
        int sz = mp[v[i].first].size();
        for(int j = 0; j < 10-sz; j++)
            cout<<" ";
        cout<<" | "<<v[i].second<<endl;
    }

    return 0;
}
