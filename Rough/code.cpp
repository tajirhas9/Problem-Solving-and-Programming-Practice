#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
    int n;

    cin>>n;
    int a[n],b[n],l,t=1000000000,pos;

    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i] = a[i];
    }

    sort(b,b+n);

    int m = b[0],k=0;
    for(int i=0;i<n; )
    {
        l=0;
        if(a[i]==m)
        {
            pos = i;

            for(int j=i+1;j<n;j++)
            {
                if(a[j]==m){
                    l++;
                    i = j;
                    break;
                }
                else
                {
                    l++;
                }

                if(j==n-1){
                    k=1;
                    break;
                }
            }

            if(k==0){
                if(l<t)
                    t=l;
            }

            if(k==1)
                break;
        }

        else
            i++;

        if(i==n-1)
            break;

    }

    cout<<t<<endl;

}
