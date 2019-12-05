/*
*
*Armstrong Numbers from 100 to 999;
*
*/
#include <stdio.h>
#include <math.h>
int main()
{
    int number,temp_num,i,total=0;
    number = 100;
    while(number<=999)
    {
        temp_num = number;
        while(temp_num>0)
        {
            i = temp_num%10;
            total += pow(i,3);
            temp_num /= 10;
        }
        if(total == number)
            printf("%d ",number);
        total = 0;
        number++;
    }
    printf("\n");
    return 0;
}
