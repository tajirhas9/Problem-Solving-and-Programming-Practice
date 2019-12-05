#include <stdio.h>
int main()
{
    int forward,reverse,first,second,temp;
    while((scanf("%d %d",&first,&second)) == 2)
    {
        if(first == -1 && second == -1) return 0;
        if(first > second)
        {
            temp = first;
            first = second;
            second = temp;
        }
        forward = second-first;
        if(forward < 0) forward = -forward;
        reverse = (first-0)+1+(99-second);
        if(reverse < 0) reverse = -reverse;
        if(forward < reverse) printf("%d\n",forward);
        else printf("%d\n",reverse);
    }
    return 0;
}
