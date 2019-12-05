#include <bits/stdc++.h>
using namespace std;
double min(double a,double b)
{
	if(a<b)	return a;
	else return b;
}
char min(char a,char b)
{
	if((int)a<(int)b)	return a;
	else return b;
}
int min(int a,int b)
{
	if(a<b)	return a;
	else return b;
}
int main()
{
	double a,b;
	int x,y;
	char s,t;
	cin >> a >> b;
	cout << min(a,b) << endl;
	cin >> x >> y;
	cout << min(x,y) << endl;
	cin >> s >> t;
	cout << min(s,t) << endl;
	return 0;
}



/*
 * struct edge{
 * 		int w;
 * 		bool operator < (const edge& p) const
 * 		{
 *			return  w < p.w;
 * 		} 
 * };
 */
