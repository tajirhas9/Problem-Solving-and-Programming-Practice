#include <bits/stdc++.h>
using namespace std;
char s[9];
int num[9],n,energy=0;
void addOne(void);
int countCost(void);
void convertNum(void);
void convertString(void);
void reset(void);
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		reset();
		scanf("%d",&n);
		scanf("%s",s);
		while(n--)
		{
			energy += countCost();
			convertNum();
			addOne();
			convertString();
		}
		printf("%d\n",energy);
	}
	return 0;
}
void reset(void)
{
	energy=0;
}
void convertNum(void)
{
	int i;
	for(i=0;i<8;i++)
	{
		switch(s[i])
		{
			case '1':
				num[i] = 1;
				break;
			case '2' :
				num[i] = 2;
				break;
			case '3':
				num[i] = 3;
				break;
			case '4' :
				num[i] = 4;
				break;
			case '5':
				num[i] = 5;
				break;
			case '6' :
				num[i] = 6;
				break;
			case '7':
				num[i] = 7;
				break;
			case '8' :
				num[i] = 8;
				break;
			case '9':
				num[i] = 9;
				break;
			case 'A' :
				num[i] = 10;
				break;
			case 'B':
				num[i] = 11;
				break;
			case 'C' :
				num[i] = 12;
				break;
			case 'D':
				num[i] = 13;
				break;
			case 'E' :
				num[i] = 14;
				break;
			case 'F':
				num[i] = 15;
				break;
			case '0' :
				num[i] = 0;
				break;
		}
	}
}
int countCost()
{
	int i,sum=0;
	for(i=0;i<8;i++)
	{
		switch(s[i])
		{
			case '1':
				sum += 2;
				break;
			case '2' :
				sum += 5;
				break;
			case '3':
				sum += 5;
				break;
			case '4' :
				sum += 4;
				break;
			case '5':
				sum += 5;
				break;
			case '6' :
				sum += 6;
				break;
			case '7':
				sum += 3;
				break;
			case '8' :
				sum += 7;
				break;
			case '9':
				sum += 6;
				break;
			case 'A' :
				sum += 6;
				break;
			case 'B':
				sum += 5;
				break;
			case 'C' :
				sum += 4;
				break;
			case 'D':
				sum += 5;
				break;
			case 'E' :
				sum += 5;
				break;
			case 'F':
				sum += 4;
				break;
			case '0' :
				sum += 6;
				break;
		}
	}
	return sum;
}
void addOne(void)
{
	int i,carry=0;
	num[7]++;
	if(num[7] > 15)
	{
		num[7] = 0;
		carry = 1;
	}
	i=6;
	while(carry==1)
	{
		num[i] += carry;
		carry=0;
		if(num[i] > 15)
		{
			num[i] = 0;
			carry = 1;
		}
		i--;
		if(i<0)	break;
	}
}
void convertString()
{
	int i;
	for(i=0;i<8;i++)
	{
		switch(num[i])
		{
			case 1:
				s[i] = '1';
				break;
			case 2 :
				s[i] = '2';
				break;
			case 3:
				s[i] = '3';
				break;
			case 4 :
				s[i] = '4';
				break;
			case 5:
				s[i] = '5';
				break;
			case 6 :
				s[i] = '6';
				break;
			case 7:
				s[i] = '7';
				break;
			case 8 :
				s[i] = '8';
				break;
			case 9:
				s[i] = '9';
				break;
			case 10 :
				s[i] = 'A';
				break;
			case 11:
				s[i] = 'B';
				break;
			case 12 :
				s[i] = 'C';
				break;
			case 13:
				s[i] = 'D';
				break;
			case 14 :
				s[i] = 'E';
				break;
			case 15:
				s[i] = 'F';
				break;
			case 0 :
				s[i] = '0';
				break;
		}
	}
}
