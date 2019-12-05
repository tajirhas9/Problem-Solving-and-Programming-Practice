#include <stdio.h>
#include <string.h>

int main()
{
  char str1[100], str2[100];
  int count, j,len ;

  printf("Enter a string to delete vowels\n");
  gets(str1);
 len=strlen(str1);

  for(count = 0,j=0; count<len; count++)
    {
        if((str1[count] == 'a' || str1[count] == 'e' || str1[count] == 'i' || str1[count] == 'o' || str1[count] == 'u') ||
           (str1[count]== 'A' || str1[count] == 'E' || str1[count] == 'I' || str1[count] == 'O' || str1[count] == 'U' ))
        {
            continue;
        }
        else
        {
            str2[j]=str1[count];
            j++;
        }


    }


  str2[j] = '\0';
  printf("String after deleting vowels: %s\n", str2);
  getch();

  return 0;
}


