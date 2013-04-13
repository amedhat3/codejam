import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email : contact@ahmadmedhat.com
 **/
public class C {

	static int T;

	
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "C-test.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scnr = new Scanner(fin);
		
		// Output file
		String out = "C.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		 
		T = scnr.nextInt();
		for (int tt = 1 ; tt <= T ; tt++) {
			ps.println("Case #" + (tt) + ": ");
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}
