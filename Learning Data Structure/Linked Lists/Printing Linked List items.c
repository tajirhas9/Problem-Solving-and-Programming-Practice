#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct book
{
    char title[20];
    char author[20];
    double price;
    int pages;
};
typedef struct book book;
int main()
{
    int i,n,*fp;
    book danBrown[6];
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        printf("Book %d:\n",i+1);
        printf("Title : ");
        gets(danBrown[i].title);
        printf("Author : ");
        gets(danBrown[i].author);
        printf("Price : ");
        scanf("%lf",&danBrown[i].price);
        printf("Pages : ");
        scanf("%d",&danBrown[i].pages);
        getchar();
    }
    fp = fopen("RANDOM","w");
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s %s %lf %d\n",danBrown[i].title,danBrown[i].author,danBrown[i].price,danBrown[i].pages);
    }
    fclose(fp);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        printf("%s %s %.2lf %d\n",
                danBrown[i].title,
                danBrown[i].author,
                danBrown[i].price,
                danBrown[i].pages
                );
    }
    return 0;
}
