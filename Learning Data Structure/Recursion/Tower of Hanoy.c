#include <stdio.h>
int hanoy(int n,char from,char to,char temp);
int main()
{
    int n,steps;
    char from,to,temp;
    scanf("%d",&n);
    hanoy(n,'A','B','C');
    return 0;
}
int hanoy(int n,char from,char to,char temp)
{
    if(n == 1)
    {
        printf("Disk 1 moved from %c to %c\n",from,to);
        return 0;
    }
    hanoy(n-1,from,temp,to);
    printf("Disk %d moved from %c to %c\n",n,from,to);
    hanoy(n-1,temp,to,from);
}
