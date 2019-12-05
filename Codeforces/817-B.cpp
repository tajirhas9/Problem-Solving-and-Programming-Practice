#include <bits/stdc++.h>
#include <climits>
using namespace std;
long long int fact(long long int n);
int main()
{
    long long int a[100000],b[100000],min_a=LLONG_MAX,min_b=LLONG_MAX,min_c=LLONG_MAX,n,i,j,r,count_a=0,count_b=0,count_c=0;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i] < min_a)
        {
            min_c = min_b;
            min_b = min_a;
            min_a = a[i];
        }
        else if(a[i] < min_b)
        {
            min_c = min_b;
            min_b = a[i];
        }
        else if(a[i] < min_c)
        {
            min_c = a[i];
        }
    }
    if(min_b == LLONG_MAX)
        min_b = a[1];
    if(min_c == LLONG_MAX)
        min_c = a[2];
    for(i=0;i<n;i++)
    {
        if(a[i] == min_a)
            count_a++;
        if(a[i] == min_b)
            count_b++;
        if(a[i] == min_c)
            count_c++;
    }
    if(min_a == min_b && min_b == min_c)
    {
        count_b = 1;
        count_c = 1;
    }
    else
    {
        if(min_a == min_b)
        {
            count_a = 1;
            count_b = 1;
        }
        if(min_a == min_c)
        {
            count_a = 1;
            count_c  = 1;
        }
        if(min_b == min_c)
        {
            count_b = 1;
            count_c  = 1;
        }
    }
    //cout << min_a << " " << min_b <<  " " << min_c << endl;
    cout << count_a*count_b*count_c;
    return 0;
}
long long int fact(long long int n)
{
    long long int factorial;
    if(n== 0)
        return 1;
    else
    {
        factorial = n*fact(n-1);
        return factorial;
    }
}
