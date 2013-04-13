import java.util.*;
import java.io.*;
public class Problem{
	static Scanner sc;
	static PrintWriter pr;
	static ArrayList < String > found;
	public static boolean check(String s){
		for(int h=0;h<found.size();h++){
			if(s.equals(found.get(h))) return true;
		}
		return false;
	}
	public static void main(String args[]) throws Exception{
		sc=new Scanner(new File("A-large.in"));
		pr=new PrintWriter(new File("output.out"));
		int t=sc.nextInt();
		for(int i=1;i<=t;i++){
			int n ,m ;
			n=sc.nextInt();
			m=sc.nextInt();
			sc.nextLine();
			found=new ArrayList < String >();
			for(int j=0;j<n;j++){
				found.add(sc.nextLine());
			}
			int y=0;
			for(int j=0;j<m;j++){
				String temp=sc.nextLine();
				int k=temp.length()-1;
				if(!check(temp)){
					y++;
					found.add(temp);
					while(k>0){
						if(temp.charAt(k)=='/'){
							String temps=temp.substring(0,k);
							if(check(temps)) break;
							else{
								y++;
								found.add(temps);
							}
						}
						k--;
					}
				}
			}
			pr.println("Case #"+i+": "+y);
		}
		sc.close();
		pr.close();
	}
}
