import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email : contact@ahmadmedhat.com
 **/
public class C {

	static int T;

	
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "C-large.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scnr = new Scanner(fin);
		
		// Output file
		String out = "C.out";
		FileOutputStream fout = new FileOutputStream (out);
		PrintStream ps = new PrintStream(fout);
		 
		T = scnr.nextInt();
		for (int tt = 1 ; tt <= T ; tt++) {
			int N = scnr.nextInt();
			long L = scnr.nextLong();
			long H = scnr.nextLong();
			
			long num[] = new long [N]; 
			long num2[] = new long [N];
			
			
			for (int i =0 ; i < N ; i++) {
				num[i] = scnr.nextLong();
				num2[i] = num[i];
			}
			
			long res=0;
			
			for (long i = L ; i <= H ; i++){
				for (int j =0 ; j < N ; j++) {
					num2[j] = num[j];
				}
				boolean f = false;
				for (int j =0 ; j < N ; j++) {
					if (num2[j] % i == 0) {
						num2[j] = num2[j] % i;
					} else if (i % num2[j] == 0) {
						num2[j] = num2[j] % i;
					} else {
						f=true;
						break;
					}
				}
				if (!f) {
					res = i;
					break;
				}
			}
			
			if (res == 0) {
				ps.println("Case #" + (tt) + ": NO");
			} else {
				ps.println("Case #" + (tt) + ": "+ res);
			}
				
			
			/*long lcm = lcm(num[0], num[1]);
			for (int i = 2 ; i < N ; i++){
				lcm = lcm(lcm, num[i]);
				System.out.println(lcm);
			}
			
			if (lcm >= L && lcm <= H) {
				ps.println("Case #" + (tt) + ": "+ lcm);
			} else {
				ps.println("Case #" + (tt) + ": NO");
			}*/
		}
		
		fout.close();
		fin.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
	
	static long lcm(long a,long b)
	{
		return a/gcd(a,b)*b;
	}
	
	static long gcd(long a, long b)
	{
	   if (b==0) return a;
	   return gcd(b,a%b);
	}
}
