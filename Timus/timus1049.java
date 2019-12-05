import java.io.*;
import java.util.*;
import java.math.*;
public class timus1049
{
	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger n = new BigInteger("1");
		BigInteger p;
		for(int ii=1;ii<=10;ii++)
		{
			p = cin.nextBigInteger();
			n = n.multiply(p);
		}
		BigInteger i = new BigInteger("1");
		BigInteger j = new BigInteger("1");
		int cnt=0;
		p = new BigInteger("0");
		BigInteger r = new BigInteger("0");
		while(!(i.compareTo(sqrt(n))==1))
		{
			if((n.mod(i)).compareTo(p)==0)
			{
				cnt++;
			}
			i = i.add(j);
			//System.out.println("\n"+i);
		}
		System.out.println(cnt%10);
	}
	public static BigInteger sqrt(BigInteger x) {
    BigInteger div = BigInteger.ZERO.setBit(x.bitLength()/2);
    BigInteger div2 = div;
    // Loop until we hit the same value twice in a row, or wind
    // up alternating.
    for(;;) {
        BigInteger y = div.add(x.divide(div)).shiftRight(1);
        if (y.equals(div) || y.equals(div2))
            return y;
        div2 = div;
        div = y;
    }
}
}
