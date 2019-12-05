import java.io.*;
import java.util.*;
public class af1173
{
	public static void main(String[] args)
	{
		int t;
		int a[] = new int[11];
		Scanner cin = new Scanner(System.in);
		t = cin.nextInt();
		a[0] = t;
		for(int i=1; i<10;i++)
		{
			a[i] = a[i-1]<<1;
		}
		for(int i=0;i<10;i++)
			System.out.println("N["+i+"] = "+a[i]);
	}
}
