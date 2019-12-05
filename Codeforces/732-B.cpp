#include <bits/stdc++.h> 
using namespace std; 
int main() 
{ 	
    int n,k,a[1000],first,extra=0,remain; 
    	cin >> n >> k; 	
    for(int i=0;i<n;i++) 		cin >> a[i]; 	
    for(int i=0;i<(n-1);i++) 	
    { 		
        if(a[i]+a[i+1]<k)
        {
            remain = k-(a[i]+a[i+1]);
            extra += remain;
            a[i+1] += remain;
        }
    } 	
    cout << extra << endl; 	
    for(int i=0;i<n;i++)	
        cout << a[i] << " "; 	
    cout << endl; 
    	return 0; 
}
