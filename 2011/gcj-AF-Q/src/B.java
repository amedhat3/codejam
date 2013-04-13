import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email :a.medhat.cs@gmail.com
 * */
public class B {

	static final String IMPOSSIBLE = "IMPOSSIBLE";  
	static int N;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "B-large.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "B.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		 
		N = scn.nextInt();
		int i,j,k=0;
		
		for (i=0 ; i< N ; i++) {
			int M = scn.nextInt();
			List<Integer> data = new ArrayList<Integer>();
			for (j = 0 ; j < 12 ; j++) {
				data.add(scn.nextInt());
			}
			int maxProfit = 0;
			int from = 0;
			int to = 0;
			int units = 0;
			for (j = 0 ; j < 11 ; j ++) {
				if ( M / data.get(j) < 1)continue;
				for (k = j+1 ; k < 12 && (data.get(k) > data.get(j)) ; k ++) {
					int tmpProfit = 0;
					units = M / data.get(j);
					tmpProfit += ((units * data.get(k)) - (units * data.get(j)));
					
					if (tmpProfit > maxProfit) {
						from =j+1;
						to = k+1;
						maxProfit = tmpProfit;
					}
					else if (tmpProfit == maxProfit) {
						if (data.get(j) < data.get(from-1)) {
							from =j+1;
							to = k+1;
							maxProfit = tmpProfit;
						}
					}
				}
			}
			if (from == 0 || to == 0){
				ps.println("Case #" + (i+1) + ": " + IMPOSSIBLE);
			}
			else {
				ps.println("Case #" + (i+1) + ": " + from + " " + to + " " + maxProfit);
			}
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}
