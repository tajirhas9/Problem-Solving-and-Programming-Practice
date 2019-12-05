import java.io.*;
import java.util.*;
public class aboutGrisha2012
{
	public static void main(String[] args)
	{
		int f,tme = 240;
		Scanner cin = new Scanner(System.in);
		f = cin.nextInt();
		int reqt;
		reqt = 45*(12-f);
		if(reqt<=tme)
			System.out.println("YES\n");
		else
			System.out.println("NO\n");
	}
};
