#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
vector <char> graph[100000];
queue <char> q;
int main()
{
    int t;
    string x;
    cin >> t;
    while(t--)
    {
        cin >> x;
        graph.push_back(x);
    }
    return 0;
}
