#include <stdio.h>

int main()
{
    int n,a,b;

    printf("Choose Operation : \n\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("5.Remainder\n\n");
    printf("*************\n\n");

    scanf("%d",&n);
    if( n > 0 && n <= 5)
    {
        printf("Enter first number : ");
        scanf("%d",&a);
        printf("Enter second number : ");
        scanf("%d",&b);
        switch(n)
        {
        case 1 :
            printf("%d\n",a+b);
            break;
        case 2 :
            printf("%d",a-b);
            break;
        case 3 :
            printf("%d",a*b);
            break;
        case 4 :
            printf("%.3f",(float)a/b);
            break;
        case 5 :
            printf("%d",a%b);
            break;
        default :
            printf("Wrong Input\n");
            break;
        }
    }
    else
    {
        printf("Wrong Selection.\n");
    }

    return 0;
}
