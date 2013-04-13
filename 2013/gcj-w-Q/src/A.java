import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


/**
 * @author: Ahmed Medhat Othman
 * @codeJame: AMedOs
 * @topCoder: AMedOs
 * @email :amedhat.cs@gmail.com
 * */
public class A {

	static int T;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "A.in";
		
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "A.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		T = scn.nextInt();scn.nextLine();
		int tc,i,j=0,res;
		for (tc=1 ; tc<= T ; tc++) {
			res =0;
			ps.println("Case #" + (tc) + ": " + res);
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}
