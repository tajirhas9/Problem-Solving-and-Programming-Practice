#include <stdio.h>
int main()
{
    int list[1000],a,b,people=0,n,i,capacity;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        people -= a;
        people += b;
        list[i] = people;
    }
    capacity = list[0];
    for(i=1;i<n;i++)
    {
        if(capacity < list[i])
            capacity = list[i];
    }
    printf("%d",capacity);
    return 0;
}
