#include<bits/stdc++.h>
using namespace std;
int main(){
   int nDay = 150,i,k=1;
   printf("%d\n", nDay);
   //printf("999 ");
   for(i=1;i<=nDay-4;i++)	printf("%d ",i);
   printf("4 ");
   i++;
   while(k<4)
   {
	   printf("%d ",k);
	   i++;
	   k++;
   }
   cout << endl;
   return 0;
}
