import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


/**
 * @author: Ahmad Medhat Othman
 * @codeJame: AMedOs
 * @topCoder: AMedOs
 * @facebook: ahmadmedhat.othman
 * @email :a.medhat.cs@gmail.com
 * */
public class A {

	static int N;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "A-large.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "A.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		 
		N = scn.nextInt();
		String tmp ="";
		int i,j,k=0;
		for (i=0 ; i< N ; i++) {
			List<Integer> B = new ArrayList<Integer>();
			List<Integer> R = new ArrayList<Integer>();
			int l = scn.nextInt(); 
			for (j = 0 ; j < l ; j++) {
				tmp = scn.next();
				if(tmp.charAt(tmp.length() - 1) == 'R') {
					R.add(Integer.parseInt(tmp.substring(0, tmp.length() - 1)));
				}
				else if (tmp.charAt(tmp.length() - 1) == 'B') {
					B.add(Integer.parseInt(tmp.substring(0, tmp.length() - 1)));
				}
			}
			Collections.sort(R);
			Collections.sort(B);
			int sz = Math.min(R.size(), B.size());
			int sm=0;
			for (k=0 ; k < sz ; k++) {
				sm+=R.get(R.size()-k-1);
				sm+=B.get(B.size()-k-1);
			}
			if (sm > 0) {
				sm -= (sz*2);
			}
			
			ps.println("Case #" + (i+1) + ": " + sm);
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}
