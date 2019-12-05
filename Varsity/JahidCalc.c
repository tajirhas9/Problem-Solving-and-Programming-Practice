#include <stdio.h>

int main()
{
    int n,a,b,c;

    printf("Choose Operation : \n\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("5.Remainder\n\n");

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
            c = a+b;
            printf("%d\n",c);
            break;
        case 2 :
            c = a-b;
            printf("%d",c);
            break;
        case 3 :
            c = a*b;
            printf("%d",c);
            break;
        case 4 :
            printf("%.2f",(float)a/b);
            break;
        case 5 :
            c = a%b;
            printf("%d",c);
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
