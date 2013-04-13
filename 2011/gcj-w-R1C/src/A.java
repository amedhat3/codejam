import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * @author : Ahmad Medhat Othman
 * @codeJame userName : AMedOs
 * @topCoder Handel : AMedOs
 * @email : contact@ahmadmedhat.com
 **/
public class A {

	static int T;
	public static void main(String[] args) throws Exception  {
		// Input file
		String in = "A-large.in";
		FileInputStream fin = new FileInputStream(in);
		Scanner scnr = new Scanner(fin);
		
		// Output file		
		String filename = "A.out";
		File myFile = new File(filename);       
		FileOutputStream outStream = new FileOutputStream(myFile);
		PrintWriter out2 = new PrintWriter(outStream); 
		   
		
		T = scnr.nextInt();
		
		int tt = 0;
		for (tt = 1 ; tt <= T ; tt++) {
			int h = scnr.nextInt();
			int w = scnr.nextInt();
			char g[][]= new char[h][w];
			for (int i =0;i<h;i++){
				g[i] = scnr.next().toCharArray();
			}
			
			boolean f = true;
			for (int i =0;i<h-1;i++){
				for (int j =0 ; j < w-1; j++) {
					if (g[i][j] =='#') {
						if (g[i+1][j]=='#' && g[i][j+1]=='#' && g[i+1][j+1]=='#') {
							g[i][j] = '/' ;
							g[i+1][j] = '\\' ;
							g[i][j+1] = '\\' ;
							g[i+1][j+1] = '/';
						} else {
							f=false;
							break;
						}
					}
				}
				if (!f)break;
			}
			
			for (int i =0 ; i < h ; i++){
				if (g[i][w-1] == '#'){
					f=false;break;
				}
			}
			for (int i =0 ; i < w ; i++){
				if (g[h-1][i] == '#'){
					f=false;break;
				}
			}
			out2.println("Case #" + tt + ":");
			if (!f){
				out2.println("Impossible");
			} else {
				for (int j =0 ; j < w; j++) {
					out2.print(g[0][j]);
				}
				for (int i =1;i<h;i++){
					out2.println();
					for (int j =0 ; j < w; j++) {
						out2.print(g[i][j]);
					}
				}
				out2.println();
			}
		}
		//out2.print('/');
		//out2.print("\\/");
	//	fout.close();
		fin.close();
		out2.close();
		System.out.println("Done:.......");
		System.exit(0);
	}
}