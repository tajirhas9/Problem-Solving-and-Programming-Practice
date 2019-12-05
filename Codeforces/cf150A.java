import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.BitSet;
import java.io.InputStreamReader;
import java.io.InputStream;

public class Main {
	public static void main (String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader (inputStream);
		PrintWriter out = new PrintWriter (outputStream);
		TaskA solver = new TaskA ();
		solver.solve (1, in, out);
		out.close ();
	}
	
	static class TaskA {
		
	}
	
	static class InputReader {
		private BufferedReader reader;
		private StringTokenizer tokenizer;
		
		public InputReader (InputStream stream) {
			reader = new BufferedReader (new InputStreamReader (stream), 32768);
			tokenizer = null;
		}
		
		public String next () {
			while (tokenizer == null || !tokenizer.hasMoreTokens ()) {
				try {
					String str;
					if ((str = reader.readLine ()) != null) tokenizer = new StringTokenizer (str);
					else return null;//to detect eof
				} catch (IOException e) {
					throw new RuntimeException (e);
				}
			}
			return tokenizer.nextToken ();
		}
		
		public long nextLong () {
			return Long.parseLong (next ());
		}
		
	}
}
