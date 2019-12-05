#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,minuites=0,i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d:%d",&h,&m);
        if(h == 12 || h == 6)
        {
            if(m==0)
                printf("%02d:%02d\n",h,m);
            else
                printf("%02d:%02d\n",h,(60-m));
        }
        else if(h>6)
        {
            for(i = h;i <12;i++)
            {
                for(j=1;j<60;j++)
                {
                    if(i == h && j == 1)
                        j = m+1;
                    minuites++;
                }
                minuites++;
            }
            printf("%02d:%02d\n",0+(minuites/60),minuites%60);
        }
        else if(h<6)
        {
            for(i = h;i>0;i--)
            {
                for(j=60;j>0;j--)
                {
                    if(i == h && j == 60)
                        j = m-1;
                    minuites++;
                }
                minuites++;
            }
            printf("%02d:%02d\n",12-(minuites/60),minuites%60);
        }
        if(t==0)
            break;
    }
    return 0;
}
