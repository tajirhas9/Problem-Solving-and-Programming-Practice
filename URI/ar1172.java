import java.io.*;
import java.util.*;
public class ar1172
{
	public static void main(String[] args)
	{
		int i,k;
		int x[] = new int[13];
		Scanner cin = new Scanner(System.in);
		for(i=0;i<10;i++)
		{
			k = cin.nextInt();
			if(k<=0)
				x[i] = 1;
			else
				x[i] = k;
		}
		for(i=0;i<10;i++)
			System.out.println("X["+i+"] = "+x[i]);
	}
}
