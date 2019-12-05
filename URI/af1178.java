import java.io.*;
import java.util.*;
import java.text.*;
public class af1178
{
	public static DecimalFormat df4 = new DecimalFormat("#0.0000");
	public static void main(String[] args)
	{
		double n;
		Scanner cin = new Scanner(System.in);
		n = cin.nextDouble();
		for(int i=0;i<100;i++)
		{
			System.out.println("N["+i+"] = "+df4.format(n));
			n /= 2;
		}
	}
};
