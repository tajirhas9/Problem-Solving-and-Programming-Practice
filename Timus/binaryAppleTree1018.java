import java.io.*;
import java.util.*;
public class binaryAppleTree1018
{
	public static void main(String[] args)
	{
		Vector v[][] = new Vector[200][200];
		Scanner cin = new Scanner(System.in);
		int n,q,x,y,w;
		n = cin.nextInt();
		q = cin.nextInt();
		for(int i=0;i<(n-1);i++)
		{
			x = cin.nextInt();
			y = cin.nextInt();
			w = cin.nextInt();
			v[x].addElement(new Integer(y));
			v[y].addElement(new Integer(x));
		}
	}
};
