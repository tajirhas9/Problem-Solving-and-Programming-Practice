#include <stdio.h>
int main()
{
    int a[30],i,located,move=0,moveRow,moveCol,row,col;
    for(i=0; i < 25; i++)
    {
        scanf("%d",&a[i]);
        if(a[i] == 1) located = i+1;
    }
    col = located%5;
    row = (located/5)+1;
    if(col == 0)
    {
        col = 5;
        row = located/5;
    }
    moveRow = (row-3);
    if(moveRow < 0)
        moveRow = -moveRow;
    moveCol = col-3;
    if(moveCol < 0)
        moveCol = -moveCol;
    move = moveRow+moveCol;
    printf("%d",move);
    return 0;
}
