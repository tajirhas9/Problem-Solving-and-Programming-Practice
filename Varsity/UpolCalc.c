#include <stdio.h>

int main()
{
    int n;
    float a,b,c;
    printf("Choose Operation : \n\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");

    scanf("%d",&n);
    if( n > 0 && n <= 4)
    {
        printf("Enter first number : ");
        scanf("%f",&a);
        printf("Enter second number : ");
        scanf("%f",&b);
        if(n == 1)
        {
            c = a+b;
            printf("%.2f",c);
        }
        else if(n == 2)
        {
            c = a-b;
            printf("%.2f",c);
        }
        else if(n == 3)
        {
            c = a*b;
            printf("%.2f",c);
        }
        else if(n == 4)
        {
            c = a/b;
            printf("%.2f",c);
        }
    }
    else
    {
        printf("Wrong Selection.\n");
    }

    return 0;
}
