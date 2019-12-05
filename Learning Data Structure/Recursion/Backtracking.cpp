#include <stdio.h>
int permutation(int n);
int main()
{
    int n;
    scanf("%d",&n);
    permutation(n);
    return 0;
}
int permutation(int n)
{
    int i;
    bool a[1000];
    for(i=1;i<=n;i++)
        a[i] = false;
    for(i=1;i<=n;i++)
    {
        if(a[i] == false)
        {
            a[i] = true;
            permutation(i+1);
            a[i] = false;
        }
        printf("\n");
    }
}

