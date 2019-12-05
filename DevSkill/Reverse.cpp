#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    char s[1100],s1[1100];
    int i,j,t,l;
    scanf("%d",&t);
    getchar();
    while( t > 0)
    {
        cin >> s;
        l = strlen(s);
        for(i=(l-1),j=0; i >= 0; i--,j++)
            s1[j] = s[i];
            s1[l] = '\0';
        cout << s;
        t--;
    }
    return 0;
}

