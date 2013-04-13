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
public class C {

	static int N,L,W;
	static boolean[][] land;
	static int[][] best;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "C-large.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "C.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		 
		N = scn.nextInt();
		int i,j,k=0;
		for (i=0 ; i< N ; i++) {
			L = scn.nextInt();
			W = scn.nextInt();
			land = new boolean[W][L];
			best = new int[W][L];
			
			for (j = 0 ; j < W ; j++) {
				String str = scn.next();
				for (k =0 ; k < L ; k++) {
					best[j][k] = -1;
					char tmp = str.charAt(k); 
					if (tmp == 'G' || tmp == 'S') {
						land[j][k] = true; 
					}
					else {
						land[j][k] = false;
					}
				}
			}
			
			int maxA = 0;
			for (j = 0 ; j < W; j++) {
				for (k = 0 ; k < L ; k++) {
					if (land[j][k] == true) {
						maxA = Math.max(maxA, solve(j, k));
					}
				}
			}
			ps.println("Case #" + (i+1) + ": " + maxA);
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
	
	private static int solve(int x ,int y) {
		int maxA = 1;
		int i,j;
		int lastJ = L-1;
		int lastI = W-1;
		for (i = x ; i < W ; i++) {
			for (j = y ;j <= lastJ ; j++) {
				if (land[i][j] == false){
					break;
				}
				else {
					maxA = Math.max(maxA, ((i+1-x)*(j+1-y)) );
				}
			}
			lastJ = j-1;
		}
		
		for (j = y ;j < L ; j++) {
			for (i = x ; i <= lastI ; i++) {
				if (land[i][j] == false){
					break;
				}
				else {
					maxA = Math.max(maxA, ((i+1-x)*(j+1-y)) );
				}
			}
			lastI = i-1;
		}
		
		return maxA;
	}
}
