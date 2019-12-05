#include <bits/stdc++.h>
using namespace std;
double v;
int u;
int main()
{
	scanf("%d %lf",&u,&v);
	if(u>=v|| u==0 || (u+.5)>v)
	{
		printf("%.2lf\n",v);
		return 0;
	}
	(u%5==0) ? printf("%.2lf\n",(v-u)-.5) : printf("%.2lf\n",v);
	return 0;
}
