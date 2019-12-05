import java.io.*;
import java.util.*;
import java.math.*;

public class uva10070 {
	public static void main(String[] args) {
		BigInteger p , q = BigInteger.ZERO;
		Scanner cin = new Scanner(System.in);
		while(cin.hasNextBigInteger()) {
			p = cin.nextBigInteger();
			
			boolean l = false, h = false, b = false;
			if(p.mod(valueOf(400)) == q) {
				l = true;
				if(p.mod(valueOf(55)).equals(ZERO))
				b = true;
			}
			if(p.mod(valueOf(15)).equals(ZERO))
				h = true;
			if(!l && !h && !b)
			System.out.println("This is an ordinary year.");
			else {
				if(l)
					System.out.println("This is leap year.");
				if(h)
					System.out.println("This is huluculu festival year.");
				if(b)
					System.out.println("This is bulukulu festival year.");
			}
		}
	}
}
