import java.io.*;
import java.util.*;

public class theDebutAlbum
{
	public static void main(String[] args)
	{
		int n,a[4];
		long long ans=0;
		Scanner cin = new Scanner(System.in);
		n = cin.nextInt();
		a[1] = cin.nextInt();
		a[2] = cin.nextInt();
		for(int i=1;i<=2;i++)
		{
			ans += solve(i,1LL,a[i],1LL);
		}
		System.out.println(ans+"\n");
	}
	public static long long solve(long long cur,long long hm,long long cap,long long len)
}
