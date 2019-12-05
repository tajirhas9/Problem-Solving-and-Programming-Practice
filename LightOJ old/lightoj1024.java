import java.util.Scanner;
import java.math.BigInteger;

public class lightoj1024 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T;
		T = scan.nextInt();
		for(int kase = 1; kase <= T; ++kase) {
			int n;
			n = scan.nextInt();

			BigInteger a = scan.nextBigInteger();
			
			BigInteger b = scan.nextBigInteger();
			
			BigInteger l = (a.multiply(b)).divide(a.gcd(b));	

			for(int i = 3; i <= n; ++i) {
				a = scan.nextBigInteger();
				l = (l.multiply(a)).divide(l.gcd(a));
			}
			System.out.println("Case " + kase + ": " + l);
			System.gc();
		}
	}
}
