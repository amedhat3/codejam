import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


/**
 * @author: Ahmad Medhat Othman
 * @codeJame: AMedOs
 * @topCoder: AMedOs
 * @email :amedhat.cs@gmail.com
 * */
public class A {
	public static void main(String[] args) throws Exception  {
		String in = "A.in";
		
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "A.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		int N = scn.nextInt();
		for (int tc =1; tc <= N ; tc++) {
			int L = scn.nextInt();
			int M = scn.nextInt();
			int[] arr = new int[M];
			int ans = 0;
			for (int i =0; i < M ; i++){
				arr[i] = scn.nextInt();
				 
			}
			//ans += L*arr[i];
			//if ()
			//int tot = L * M;
			ps.println("Case #" + (tc) + ": " + ans);
		}
	}

}
