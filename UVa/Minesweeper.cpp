#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
using namespace std;
char s[200][200],s1[200];
int i,j,l,c=0,n,m,t=1;
int main()
{
    //freopen("Minesweeper.txt","r",stdin);
    while(1)
    {
        for(i=0;i<200;i++)
        {
            s1[i] = '\0';
            for(j=0;j<200;j++)
                s[i][j] = '\0';
        }
        cin >> n >> m;
        getchar();
        if(n== 0 && m == 0)     return 0;
        for(i=0;i<n;i++)
        {
            cin >> s[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(s[i][j] != '*')
                {
                    if(j+1 <m && s[i][j+1] == '*')    c++;
                    if(j-1 >= 0 && s[i][j-1] == '*')    c++;
                    if(i+1 < n && s[i+1][j] == '*')    c++;
                    if(i-1 >= 0 && s[i-1][j] == '*')    c++;
                    if(i+1 < n && j+1 < m && s[i+1][j+1] == '*')  c++;
                    if(i+1 < n && j-1 >= 0 && s[i+1][j-1] == '*')  c++;
                    if(i-1 >= 0 && j+1 < m && s[i-1][j+1] == '*')  c++;
                    if(i-1 >= 0 && j-1 >= 0 && s[i-1][j-1] == '*')  c++;
                    s[i][j] = c+'0';
                }
                c = 0;
            }
        }
        if(t != 1)        cout << endl;
        cout << "Field #" << t << ":" << endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                cout << s[i][j];
            cout << endl;
        }
        t++;
        c = 0;
    }
	return 0;
}
