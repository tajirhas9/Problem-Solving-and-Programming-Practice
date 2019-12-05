#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,i,age,j,bmonth,cmonth,byear,cyear,bday,cday;

    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d/%d/%d",&cday,&cmonth,&cyear);
        scanf("%d/%d/%d",&bday,&bmonth,&byear);
        if(cyear > byear)
        {
            if(cmonth > bmonth)
            {
                age = cyear - byear;
            }
            else if(cmonth == bmonth)
            {
                if(cday >= bday)
                {
                    age = cyear - byear;
                }
                else
                {
                    age = (cyear - byear) - 1 ;
                }
            }
            else
            {
                age = (cyear - byear) -1;
            }
            if(age > 130)
            {
                printf("Case #%d: Check birth date\n",i);
            }
            else
            {
                printf("Case #%d: %d\n",i,age);
            }
        }
        else if(cyear == byear)
        {
            if(cmonth > bmonth)
            {
                printf("Case #%d: %d\n",i,0);
            }
            else if(cmonth == bmonth)
            {
                if(cday >= bday)
                {
                    printf("Case #%d: %d\n",i,0);
                }
                else
                {
                    printf("Case #%d: Invalid birth date\n",i);
                }
            }
            else
            {
                printf("Case #%d: Invalid birth date\n",i);
            }
        }
        else
        {
            printf("Case #%d: Invalid birth date\n",i);
        }

    }
    return 0;
}
