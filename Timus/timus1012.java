import java.io.*;
import java.util.*;
import java.math.*;
public class timus1012
{
	public static long n,k;
	public static BigInteger dp[][] = new BigInteger[1805][10];
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger p = new BigInteger("0");
		n = cin.nextLong();
		k = cin.nextLong();
		for(int i=0;i<1805;i++)
		{
			for(int j=0;j<10;j++)
				dp[i][j] = BigInteger.ZERO;
		}
		for(int i=1;i<k;i++)
		{
			p = p.add(solve(1,i,-1));
		}
		System.out.println(p);
	}
	public static BigInteger solve(int curLen,int cur,int prev)
	{
		BigInteger p,x,y;
		//System.out.println(n);
		p = new BigInteger("0");
		x = new BigInteger("0");
		y = new BigInteger("1");
		int i;
		if(prev==cur && cur==0)	return x;
		if(curLen==n)	return y;
		if(dp[curLen][cur] != BigInteger.ZERO)	return dp[curLen][cur];
		for(i=0;i<k;i++)
		{
			if(cur==0 && i==0)	continue;
			p = p.add(solve(curLen+1,i,cur));
		}
		return (dp[curLen][cur]=p);
	}
};
