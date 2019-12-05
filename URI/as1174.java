import java.io.*;
import java.util.*;
import java.text.*;
public class as1174
{
	public static DecimalFormat df2 = new DecimalFormat("#0.0");
	public static void main(String[] args)
	{
		int t;
		double a[] = new double[112];
		Scanner cin = new Scanner(System.in);
		for(int i=0;i<100;i++)
			a[i] = cin.nextDouble();
		for(int i=0;i<100;i++)
		{
			if(a[i]<=10)
				System.out.println("A["+i+"] = "+df2.format(a[i]));
		}
	}
}
