import java.io.*;
import java.util.*;
public class ac1175
{
	public static void main(String[] args)
	{
		int a[] = new int[24];
		Scanner cin = new Scanner(System.in);
		for(int i=0,j=19;i<20;i++,j--)
		{
			a[j] = cin.nextInt();
		}
		for(int i=0;i<20;i++)
			System.out.println("N["+i+"] = "+a[i]);
	}
}
