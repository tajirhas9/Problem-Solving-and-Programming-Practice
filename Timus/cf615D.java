import java.io.*;
import java.util.*;
import java.math.*;

public class cf615D {
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		BigInteger p,store,i,j,ans	;
		
		store = BigInteger.ONE;
		long n;
		n = cin.nextLong();
		for(long i = 0; i < n; ++i) {
			p = cin.nextBigInteger();
			 store = store.multiply(p);
		}
		//System.out.println(store);
	}
}
