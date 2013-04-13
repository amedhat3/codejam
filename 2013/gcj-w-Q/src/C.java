import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;

/**
 * @author: Ahmad Medhat Othman
 * @codeJame: AMedOs
 * @topCoder: AMedOs
 * @email :amedhat.cs@gmail.com
 * */
public class C {
	
	public static void main(String[] args) throws Exception  {
		// Input file
		//A-small.in
		//A-large.in
		String in = "C.in";
		
		FileInputStream fin = new FileInputStream(in);
		Scanner scn = new Scanner(fin);
		
		// Output file
		String out = "C.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		
		int T=0;
		T = scn.nextInt();
		
		int t,j,k=0;
		Long min,max,i=0l;
		Queue<String> q;
		Map<String,Integer> mp;
		for (t=1 ; t<= T ; t++) {
			mp = new HashMap<String, Integer>();
			q = new LinkedList<String>();
			min = scn.nextLong();
			max = scn.nextLong();
			for(i =min;i<=max;i++){
				String str = i + "";
				for(j=0;j<str.length();j++){
					q.add(str.charAt(j)+"");
				}
				StringBuilder sb = new StringBuilder();
				for(j=0;j<str.length();j++){
					q.add(q.poll());
					String[] tot = new String[str.length()];
					tot = q.toArray(tot);
					for(k=0;k<tot.length;k++){
						sb.append(tot[k]); 
					}
					//mp.put(sb., arg1)
				}
				System.out.println(str);
			}
			ps.println("Case #" + t + ": " + 3);
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}
