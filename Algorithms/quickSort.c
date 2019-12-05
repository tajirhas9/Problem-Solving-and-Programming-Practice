#include <stdio.h>
void quickSort(int arrayStrength[100000],int start,int end)
{
    int pIndex;
    if(start < end)
    {
        pIndex = partition(arrayStrength,start,end);
        quickSort(arrayStrength,start,pIndex-1);
        quickSort(arrayStrength,pIndex+1,end);
    }
}
int partition(int arrayStrength[100000],int start,int end)
{
    int i,pivot,pIndex;
    pivot = arrayStrength[end];
    pIndex = start;
    for(i = start; i <= end-1; i++)
    {
        if(arrayStrength[i] <= pivot)
        {
            swap(&arrayStrength[i],&arrayStrength[pIndex]);
            pIndex++;
        }
    }
    swap(&arrayStrength[pIndex],&arrayStrength[end]);
    return pIndex;
}
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int n,array[100000],i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&array[i]);
    }
    quickSort(array,0,n-1);
    for(i = 0; i < n; i++)
    {
        printf("%d ",array[i]);
    }
    return 0;
}
