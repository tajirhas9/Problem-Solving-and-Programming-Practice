import java.io.*;
import java.util.*;
public class lnp1180
{
	public static int t;
	public static void main(String[] args)
	{
		int a[] = new int[11234];
		Scanner cin = new Scanner(System.in);
		t = cin.nextInt();
		for(int i=0;i<t;i++)
			a[i] = cin.nextInt();
		int p = findMax(a);
		System.out.println("Menor valor: "+a[p]);
		System.out.println("Posicao: "+p);
	}
	public static int findMax(int[] a)
	{
		int pos=0;
		int m = Integer.MAX_VALUE;
		for(int i=0;i<t;i++)
		{
			if(a[i]<m)
			{
				pos = i;
				m = a[i];
			}
		}
		return pos;
	}
};
