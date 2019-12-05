#include <stdio.h>
#include <math.h>
int reverse(int x);
int isPalindrome(int x);
int main()
{
    int n;
    scanf("%d", &n);

    if(isPalindrome(n) == 1)
        printf("%d is a palindrome\n",n);
    else
        printf("%d is not a palindrome\n",n);
    return 0;
}
int reverse(int n)
{
    int p;
    if(n==0)
        return 0;
    p = (int)log10(n);
    return ((n%10 * pow(10,p)) + reverse(n/10));
}
int isPalindrome(int x)
{
    if(x == reverse(x))
        return 1;
    return 0;
}
