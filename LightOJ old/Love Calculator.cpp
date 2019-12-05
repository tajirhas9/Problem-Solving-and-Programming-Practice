#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;
int m;

char a[100];
char b[100];
long long count;
unsigned long long dp2[40][40][40];
long long dp1[40][40];
int p;

unsigned long long explore(int i, int j, int l)
{
	
	if(i == n && j != m)
		return explore(i, j+1, l-1);

	if(j == m && i != n)
		return explore(i+1, j, l-1);
	
	if(i == n && j == m)
		return l==0;

	if(dp2[i][j][l] != -1)
		return dp2[i][j][l];

	if(a[i] == b[j])
		return dp2[i][j][l] = explore(i+1, j+1, l -1);

	return dp2[i][j][l] = explore(i+1, j, l -1) + explore(i, j+1, l -1);

}
int solve(int i, int j)
{
	if(i == n)
		return m - j;

	if(j == m)
		return n - i;

	if(dp1[i][j] != -1)
		return dp1[i][j];

	if(a[i] == b[j])
		return dp1[i][j] = 1 + solve(i+1, j+1);

	return dp1[i][j] = 1 + min(solve(i+1, j),solve(i, j+1));

}
int main()
{
	int T;
	long long epic;
	scanf("%d", &T);

	for (int kase = 1; kase <= T ; kase++) {
		scanf("%s", a);
		scanf("%s", b);

		n = strlen(a);
		m = strlen(b);
		
		memset(dp1, -1, sizeof(dp1));
		
		p = solve(0, 0);
		memset(dp2, -1, sizeof(dp2));
		epic = explore(0, 0, p);

		printf("Case %d: %d %lld\n",kase,p,epic);

	}

}