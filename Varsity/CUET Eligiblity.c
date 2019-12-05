#include <stdio.h>
#include <string.h>
int main()
{
    float phy,math,chemistry,english,gpa;
    char sub[10];
    printf("Enter Subject : ");
    gets(sub);
    if(strcmp(sub,"Science") == 0 || strcmp(sub,"science") == 0)
    {
        printf("Total GPA : ");
        scanf("%f",&gpa);
        printf("GPA in physics : ");
        scanf("%f",&phy);
        printf("GPA in chemistry : ");
        scanf("%f",&chemistry);
        printf("GPA in math : ");
        scanf("%f",&math);
        printf("GPA in english : ");
        scanf("%f",&english);
        if((phy+math+chemistry+english) >= 19)
        {
            if(gpa == 5 && phy == 5 && chemistry == 5 && math == 5 && english >= 4.5)
            {
                printf("Eligible\n");
            }
            else
            {
                printf("Not Eligible\n");
            }
        }
        else
        {

            printf("Not Eligible\n");
        }
    }
    else
    {
        printf("Not Eligible\n");
    }
    return 0;
}
