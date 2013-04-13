import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email :a.medhat.cs@gmail.com
 * */
public class A {

	static int N;
	//static Map<Integer, Map<Double,Double> > num = new HashMap<Integer, Map<Double, Double> >();
	static Map<Integer, List<Double> > num = new HashMap<Integer, List<Double> >();
	static List <Integer> rl = new ArrayList<Integer>();
	
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "A-small-attempt0.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "A.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		N = scn.nextInt();
		
		int n=0;
		
		int x;
		for (n = 0 ; n < N ; n++) {
			num.clear();
			ps.println("Case #" + (n+1) + ": ");
			x = scn.nextInt();
			Double tt;
			int maxRes=0;
			for (int i = 0 ; i < x ; i ++) {
				tt = scn.nextDouble();
				
				Integer res = solve2(0.0,1.0,1,tt);
				maxRes = Math.max(res, maxRes);
				List<Double> tmp = num.get(res);
				if (tmp == null){
					tmp = new ArrayList<Double>();
				}
				tmp.add(tt);
				num.put(res, tmp);
			}
			
			for (int i = 1 ; i <= maxRes ; i++) {
				List<Double> ans = num.get(i);
				if (ans != null){
					Collections.sort(ans);
					for (Double d : ans ) {
						ps.println(d);
					}
				}
			}
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
	
	private static Integer solve2(Double start, Double end, Integer round, Double test) {
		//System.out.println(start+ " -- " + end + " ----> "+ round + "---->>>>>>" + test);
		
		Double third = 1.0/(Math.pow(3, round));
		Double newS = start + third;
		Double newE = end - third;

		if (test >= newS && test <= newE){
			return round;
		}
		
		if (test < newS) {
			return solve2(start,newS,round+1,test);
		} else if (test > newE) {
			return solve2(newE,end,round+1,test);
		} else {
			return 0;
		}
	}
}
