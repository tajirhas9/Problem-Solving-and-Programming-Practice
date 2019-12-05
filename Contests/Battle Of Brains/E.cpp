#include <bits/stdc++.h>
#include <vector>
using namespace std;
vector <int> graph[200000];
int main()
{
    int x,y,i,n,e,c;
    long long int cost=0;
    cin >> n >> e;
    for(i=1;i<=e;i++)
    {
        cin >> x >> y >> c;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cost += c;
    }
    if(n==0 || n == 1)
        cout << 0 <<endl;
    else
        cout << cost*2 << endl;
}
