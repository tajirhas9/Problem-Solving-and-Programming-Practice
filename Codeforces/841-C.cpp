#include <bits/stdc++.h>
#include <algorithm>
#include <queue>
using namespace std;
long long int n,a[300000],b[300000],temp[300000],level[3000000] = {0};
queue <long long int> q;
int main()
{
    long long int i,j;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[i]<a[j])
                swap(a[i],a[j]);
        }
    }
    for(i=0; i<n; i++)
    {
        cin >> b[i];
        temp[i] = b[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(temp[i]>temp[j])
                swap(temp[i],temp[j]);
        }
        q.push(temp[i]);
    }
    i=0;
    j=0;
    while(!q.empty())
    {
        if(q.front() == b[j])
        {
            swap(a[i],a[j]);
            q.pop();
            i++;
            j=0;
            continue;
        }
        j++;
    }
    for(i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
