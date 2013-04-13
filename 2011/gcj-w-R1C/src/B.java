import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email :contact@ahmadmedhat.com
 **/
public class B {

	static int T;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "B-test.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scnr = new Scanner(fin);
		
		// Output file
		String out = "B.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		 
		T = scnr.nextInt();
		
		int tt;
		for (tt = 1 ; tt <= T ; tt++) {
			int L = scnr.nextInt();
			int t = scnr.nextInt();
			int N = scnr.nextInt();
			int c = scnr.nextInt();
			int C[] = new int[c];
			for (int i =0 ; i < c ; i++) {
				C[i] = scnr.nextInt();
			}
			int Num[] = new int[N];
			int rev[] = new int[N];
			for (int i =0 ; i < N ; i ++) {
				Num[i] = C[i%c];
			}
			for (int i =0 ; i < N ; i ++) {
				rev[i] = 2;
				int tmp = t;
				int j = i ;
				while(tmp >= 0){
					if (tmp - Num[j] > 0) {
						tmp-=Num[j];
						j++;
					} else if (tmp - Num[j] < 0){
						rev[i] = Num[j] - tmp;
						tmp-=Num[j];
					} else {
						if (j+1 < N ){
							rev[i] = Num[j+1];
						} else {
							rev[i] = 0;
						}
					}
				}
			}
			
			
			ps.println("Case #" + tt + ": ");
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}
