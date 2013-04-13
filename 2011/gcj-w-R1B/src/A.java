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
 * @email : contact@ahmadmedhat.com
 **/
public class A {

	static int T;
	//RPI = 0.25 * WP + 0.50 * OWP + 0.25 * OOWP
	
	//static double RPI,WP,OWP,OOWP;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "A-large.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scnr = new Scanner(fin);
		
		// Output file
		String out = "A.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		 
		T = scnr.nextInt();
		
		int tt = 0;
		for (tt = 1 ; tt <= T ; tt++) {
			ps.println("Case #" + tt + ":");
			int N = scnr.nextInt();
			List<String> str = new ArrayList<String>();
			for (int i =0 ; i < N ; i ++ ){
				String tmp = scnr.next();
				str.add(tmp);
			}
			double WP[] = new double[N]; 
			double OWP[] = new double[N];
			double OOWP[] = new double[N];
			
			//calc wp
			for (int i =0 ; i < N ; i ++ ){
				int count =0;
				double summ =0;
				for (int j =0 ; j < N ; j++) {
					if (str.get(i).charAt(j) == '1'){
						summ++;
						count ++;
					} else if (str.get(i).charAt(j) == '0') {
						count ++;
					}
				}
				WP[i] = summ/count;
				//System.out.println("WP[i]  -->"+ i +"  "+ WP[i]);
			}
			
			//calc owp
			for (int i =0 ; i < N ; i++) {
				double totsum=0.0;
				double totcount=0;
				for (int j =0 ; j < N ; j++) {
					if (i == j || str.get(i).charAt(j) == '.') continue;
					int count = 0 ;
					double summ = 0;
					for (int k =0 ; k < N ; k++) {
						if (str.get(j).charAt(k)!='.' && k != i){
							count++;
							if (str.get(j).charAt(k)=='1'){
								summ++;
							}
						}
					}
					totsum += (summ/count);
					totcount++;
				}
				OWP[i] = totsum/totcount;
			}
			
			//calc oowp
			for (int i =0 ; i < N ; i ++) {
				double totsum=0.0;
				int totcount =0;
				for (int j=0; j < N ;j++) {
					if (i == j || str.get(i).charAt(j) == '.') continue;
					totsum += OWP[j];
					totcount++;
				}
				OOWP[i] = (totsum/totcount);
			}
			
			for (int i =0 ; i < N ; i++) {
				double RPI = (0.25*WP[i]) + (0.50*OWP[i]) + (0.25*OOWP[i]);
				ps.println(RPI);
			}
			
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}