import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email :a.medhat.cs@gmail.com
 * */
public class D {

	static int N;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "D.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "D.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		N = scn.nextInt();
		
		int n=0;
		for (n=0 ; n< N ; n++) {
			
			ps.println("Case #" + (n+1) + ": ");
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}
