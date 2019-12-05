#include<stdio.h> 
int main() 
{ 
    int n; 
    int i,a[100000],max,min; 
    scanf("%d",&n); 
    for(i=0; i<n; i++) 
    { 
        scanf("%d",&a[i]); 
    } 
    max = a[0]; 
    min = a[0]; 
    for(i=0; i<n; i++) 
    { 
        if(a[i]>max) 
        { 
            max = a[i]; 
        } 
        else if(a[i]<min) 
        { 
            min = a[i]; 
        } 
    } 
    printf("max = %d\n",max); 
    printf("min = %d",min); 
    return 0; 
}
