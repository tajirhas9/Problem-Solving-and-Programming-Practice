#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,revH=0,r,t,i,minute=0,j,k;
    scanf("%2d:%2d",&h,&m);
    t = h;
    while(t > 0)
    {
        r = t%10;
        revH = revH*10+r;
        t /= 10;
    }
    if(h < 10)
    {
        revH *= 10;
    }
    if(m == revH)
    {
        cout << "0" << endl;
        return 0;
    }
    if(h != 23)
    {
        if(m < revH && revH < 60)
        {
            cout << revH-m << endl;
        }
        else
        {
            i=1;
            revH = 61;
            //cout << "check" << endl;
            while(revH >= 60)
            {
                t = h+i;
                revH = 0;
                //cout << "t = " << t << endl;
                while(t > 0)
                {
                    r = t%10;
                    revH = revH*10+r;
                    t /= 10;
                }
                if((h+i)<10)
                {
                    revH *= 10;
                }
                //cout << h+i << ":";
                //cout << revH << endl;
                i++;
            }
            for(j=h,k=m;j<=(h+i-1);k++)
            {
                if(k == revH && j == (h+i-1))
                    break;
                if(k == 60)
                {
                    k=0;
                    j++;
                }
                minute++;
            }
            cout << minute << endl;
        }
    }
    else
    {
        if(m < revH)
            cout << revH-m << endl;
        else
        {
            cout << 60-m << endl;
        }
    }
    return 0;
}
