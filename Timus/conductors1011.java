import java.io.*;
import java.util.*;

public class conductors1011
{
	public static void main(String[] args)
	{
		double p,q,x;
		int flag = 0;
		Scanner cin = new Scanner(System.in);
		p = cin.nextDouble();
		q = cin.nextDouble();
		for(int i=1;i<=10000 && flag==0;i++)
		{
			for(int j=1;j<=10000 && flag==0;j++)
			{	
				x = ((double)i/(double)j)*100;
				if(x>p && x<q)
				{
					//cout << x <<  " " << pp << endl;
					System.out.println(j+"\n");
					flag =1;
				}
			}
		}
		if(flag==0)
			System.out.println(p+"\n");
	}
};
