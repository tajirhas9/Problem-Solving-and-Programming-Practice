import java.util.*;
import java.math.*;

public class Main {
	

	public static void main(String[] args) {
		long  n,a;

		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNextLong()) {
			n = cin.nextLong();
			a = cin.nextLong();

			BigInteger sum = BigInteger.ZERO;

			BigInteger A = BigInteger.valueOf(a);

			for(int i = 1; i <= n; ++i) {
				BigInteger x = A;
				x = x.multiply(BigInteger.valueOf(i));
				sum = sum.add(x);

				A = A.multiply(BigInteger.valueOf(a));
			}

			System.out.println(sum);
		}
	}
}
