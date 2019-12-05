import java.io.*;
import java.util.*;
public class af1177
{
	public static void main(String[] args)
	{
		int t;
		int a[] = new int[1005];
		Scanner cin = new Scanner(System.in);
		t = cin.nextInt();
		for(int i=0,j=0;i<1000;i++,j++)
		{
			if(j==t)	j=0;
			a[i] = j;
		}
		for(int i=0;i<1000;i++)
			System.out.println("N["+i+"] = "+a[i]);
	}
}
