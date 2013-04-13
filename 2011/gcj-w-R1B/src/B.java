import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email :contact@ahmadmedhat.com
 **/
public class B {

	static int T;
	static Map <Integer, Integer> P = new HashMap<Integer, Integer>();
	static int min;
	static int max;
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
			P.clear();
			int c = scnr.nextInt();
			int d = scnr.nextInt();
			int p[]= new int[c];
			int v[]= new int[c];
			 
			
			for (int i =0 ; i < c ; i++){
				p[i] = scnr.nextInt();
				v[i] = scnr.nextInt();
				P.put(p[i], v[i]);
			}
			min = p[0];
			max = p[c-1];
			
			int time = 0;
			while (!isEshta(d)) {
				System.out.println("not yet");
				time++;
				for (int i = min; i <= max ; i++) {
					while (P.containsKey(i) && P.get(i) >= 1 && (needToMoveR(i,d) || needToMoveL(i,d))) {
						if (needToMoveR(i,d) && canL(i,d)) {
							movL(i);
						} else if (needToMoveL(i,d)) {
							movR(i);
						}
					}
				}
			}

			ps.println("Case #" + tt + ": "+time);
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
	
	private static boolean needToMoveL(int pos,int d) {
		if (P.get(pos) > 1) return true;
		if (P.get(pos) == 0)return false;
		for (int i =1 ; i < d ; i++){
			if (P.containsKey(pos-i) && P.get(pos-i) > 0) {
				return true;
			}
		}
		return false;
	}
	
	private static boolean needToMoveR(int pos,int d) {
		if (P.get(pos) > 1) return true;
		if (P.get(pos) == 0)return false;
		for (int i =1 ; i < d ; i++){
			if (P.containsKey(pos+i) && P.get(pos+i) > 0) {
				return true;
			}
		}
		return false;
	}
	
	private static boolean canL(int pos,int d) {
		for (int i =1 ; i < d ; i++){
			if (P.containsKey(pos-1-i) && P.get(pos-1-i) > 0){
				return false;
			}
		}
		return true;
	}
	private static void movL(int pos) {
		P.put(pos, P.get(pos)-1);
		P.put(pos-1, (P.get(pos-1)==null? 0 : P.get(pos+1))+1);
		if (pos-1 < min) min  = pos-1;
	}
	private static void movR(int pos) {
		P.put(pos, P.get(pos)-1);
		P.put(pos+1, (P.get(pos+1)==null? 0 : P.get(pos+1))+1);
		if (pos+1 > max) max  = pos+1;
	}
	
	private static boolean isEshta(int d) {
		for (int i = min; i <= max ; i++) {
			if (P.containsKey(i) && (needToMoveR(i,d) || needToMoveL(i,d))) return false;
		}
		return true;
	}
	
}
