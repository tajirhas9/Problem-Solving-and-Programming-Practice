#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;
char s[200][200];
int main()
{
    int x,t,m,n,i,j,k,l,height=0,width=0,area=1,flag=0;
    cin >> t;
    for(x=1;x<=t;x++)
    {
        cin >> m >> n;
        getchar();
        for(i=0;i<m;i++)
        {
            scanf("%[^\n]",s[i]);
            getchar();
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                k = j;
                l = i;
                while(s[i][k] == s[i][j] && s[i][j] == s[l][j])
                {
                    k++;
                    l++;
                    width++;
                    height++;
                }
                //cout << height << " " << width << endl;
                if(height==width && height > 1)
                {
                    for(k=i+1;k<=((i+height)-1);k++)
                    {
                        for(l=j+1;l<=((j+width)-1);l++)
                        {
                            if(s[k][l] != s[i][j])
                            {

                                flag = 1;
                                break;
                            }
                        }
                    }
                }
                if(flag == 0)
                {
                    if(area < height*width)
                        area = height*width;
                }
                flag = 0;
                height = 0;
                width = 0;
            }
        }
        if(x==1)
            cout << endl;
        cout << area << endl;
        area = 1;
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
                s[i][j] = '\0';
        }
        flag = 0;
        height = 0;
        width = 0;
    }
    return 0;
}
