#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
     char s[300];
    int length[300] = {0},i,k=0,m=0,t;
    cin >> t;
    getchar();
    scanf("%[^\n]s",s);
    for(i=0;i<t;i++)
    {
        if(s[i] == '\0')
            break;
        else if(s[i] == ' ')
            k++;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            length[k]++;
    }
    for(i=0;i<=k;i++)
    {
        if(m < length[i])
            m = length[i];
    }
    cout << m << endl;
    return 0;
}
