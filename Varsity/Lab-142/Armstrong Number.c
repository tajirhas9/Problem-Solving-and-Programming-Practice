#include <stdio.h>
int main()
{
    int number, temp_num, r, result = 0;

    printf("Enter a three digit integer: ");
    scanf("%d", &number);

    temp_num = number;

    while (temp_num != 0)
    {
        r = temp_num%10;
        result += r*r*r;
        temp_num /= 10;
    }

    if(result == number)
        printf("%d is an Armstrong number.",number);
    else
        printf("%d is not an Armstrong number.",number);

    return 0;
}
