import java.util.*;
import java.io.*;
import java.math.*;

public class cf489C {
	public static int n,s;
	public static BigInteger dp[][] = new BigInteger[109][909];
	public static BigInteger dpMin[][] = new BigInteger[109][909];
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		for(int i = 0; i <= 100; ++i) {
			for(int j = 0; j <= 900; ++j){
				dp[i][j] = BigInteger.ZERO;
				dpMin[i][j] = BigInteger.ZERO;
			}
		}
		for(int i = 1; i <= 100; ++i) {
			for(int j = 1; j <= 900; ++j) {
				for(int k = 0; k < 10 && (j-k) >= 0; ++k) {
					BigInteger p = new BigInteger(dp[i-1][j-k].toString());
					BigInteger pp = BigInteger.ONE;
					pp = p.multiply(BigInteger.valueOf(10));
					BigInteger x = BigInteger.valueOf(k);
					pp = pp.add(x);
					int comp = dp[i][j].compareTo(pp);
					if(comp== -1) {
						dp[i][j] = pp;
					}
				}
			}
		}
		for(int i = 1; i <= 100; ++i) {
			for(int j = 1; j <= 900; ++j) {
				for(int k = 0; k <= 9 && (j-k) >= 0 ; ++k) {
					BigInteger p = new BigInteger(dpMin[i-1][j-k].toString());
					BigInteger pp = BigInteger.ONE;
					pp = p.multiply(BigInteger.valueOf(10));
					pp = pp.add(BigInteger.valueOf(k));
					if(i <= 2 && j <= 15) {
						System.out.println("k -> " + k +" = " + pp);
					}
					int comp = dpMin[i][j].compareTo(pp);
					if(pp.compareTo(BigInteger.ZERO) == 0)	continue;
					if(comp == 1 || dpMin[i][j].compareTo(BigInteger.ZERO) == 0) {
						dpMin[i][j] = pp;
					}
				}
				if(i <= 2 && j <= 15)
					System.out.println(i + "," + j + " = " + dpMin[i][j]);
			}
		}
		n = cin.nextInt();
		s = cin.nextInt();
		System.out.println( dpMin[n][s] + " " + dp[n][s]);
	}
}
