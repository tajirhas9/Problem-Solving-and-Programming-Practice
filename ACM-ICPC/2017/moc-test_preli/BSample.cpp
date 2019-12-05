#include<bits/stdc++.h>
using namespace std;
#define MX 1002
int stock_prices[MX], nDay, marked[MX];
int getMaximum(int start, int end){
   int ret = -1, mx = 0;
   for(int i = start; i <= end; i++){
       if(!marked[i] && mx <= stock_prices[i]){
           mx = stock_prices[i];
           ret = i;
       }
   }
   return ret;
}
int getMinimum(int start, int end){
   int ret = -1, mn = 1000000000;
   for(int i = start; i <= end; i++){
       if(!marked[i] && mn > stock_prices[i]){
           mn = stock_prices[i];
           ret = i;
       }
   }
   return ret;
}
int getProfit(int start, int end){
   int profit = 0, i,k=1;
   for(i = start; i <= end; i++) marked[i] = 0;
   while(1){
       int X = getMaximum(start, end);
       int Y = getMinimum(start, X - 1);
       if(X==-1 || Y==-1)
		{
			cout << k << endl;
		   break;
		}		
       profit += stock_prices[X] - stock_prices[Y];
       cout << stock_prices[X] << " "  << stock_prices[Y] << endl;
       marked[X] = marked[Y] = 1;
       k++;
   }
   return profit;
}
int main(){
	int i,k;
   scanf("%d", &nDay);
   for(i = 1; i <= nDay-4; i++)
   {
	   stock_prices[i] = i;
	   //scanf("%d", &stock_prices[i]);
   }
   stock_prices[i] = 4;
   i++;
   k=1;
   while(k<4)
   {
	   stock_prices[i] = k;
	   i++;
	   k++;
   }
   int profit = getProfit(1, nDay);
   printf("%d\n", profit);
   return 0;
}
