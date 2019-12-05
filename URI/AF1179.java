import java.io.*;
import java.util.*;

public class AF1179
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		int n;
		Vector even = new Vector(16);
		Vector odd = new Vector(16);
		for(int i=0;i<15;i++)
		{
			n = cin.nextInt();
			if(n%2==0)	even.add(n);
			else 		odd.add(n);
			if(even.size()>=5)
			{
				Enumeration it = even.elements();
				int j=0;
				while(it.hasMoreElements())
					System.out.println("par["+(j++)+"] = "+it.nextElement());
				even.clear();
			}
			else if(odd.size()>=5)
			{
				Enumeration it = odd.elements();
				int j=0;
				while(it.hasMoreElements())
					System.out.println("impar["+(j++)+"] = "+it.nextElement());
				odd.clear();
			}
		}
		Enumeration it = odd.elements();
		int j=0;
		while(it.hasMoreElements())
			System.out.println("impar["+(j++)+"] = "+it.nextElement());
		odd.clear();
		it = even.elements();
		j=0;
		while(it.hasMoreElements())
			System.out.println("par["+(j++)+"] = "+it.nextElement());
		even.clear();
	}
};
