import java.io.*;
import java.util.*;
public class fa1176
{
	public static long fib[] = new long[100];
	public static void main(String[] args)
	{
		genFib();
		Scanner cin = new Scanner(System.in);
		int t,x;
		t = cin.nextInt();
		for(int i=0;i<t;i++)
		{
			x = cin.nextInt();
			System.out.println("Fib("+x+") = "+fib[x]);
		}
	}
	public static void genFib()
	{
		fib[0] = 0; fib[1] = 1;
		for(int i=2;i<61;i++)
			fib[i] = fib[i-1]+fib[i-2];
	}
}
