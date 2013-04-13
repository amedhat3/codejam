/**
 * @Author :Ahmed M. Osman
 * @CodeJame userName : AMedOs
 * @TopCoder Handel : AMedOs
 * @Email :a.medhat.cs@gmail.com
 * @Email:ahmed.osman@alex-sci.edu.eg
 * */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>
#include <map>

#include <algorithm>
#include <cmath>


using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz  size()

#define loop(i,m) for(int i=0;i<m;i++)
#define loop2(i,m) for(i=0;i<m;i++)

#define loop4m(i,x,m) for(int i=x;i<m;i++)
#define loop4m2(i,x,m) for(int i=x;i<=m;i++)

#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
const double pi=acos(-1.0);
const double eps=1e-11;

typedef long long ll;
typedef unsigned int ui;
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;



ifstream fin;
ofstream fout;


vs w;
vs f;

int main (){
	
	fin.open ("A-large-practice.in");
	//fin.open ("A-small-attempt0.in");
	//fin.open ("A-small-attempt1.in");
	//fin.open ("A-small-attempt2.in");
		
	
	//fin.open ("A-large.in");
	
	fout.open ("A.out");
	
	int tcases;
	
	fin >> tcases;
	
	int N, M;
	
	loop4m2(ncase,1,tcases){
		fin >> N >> M ;
		
		f.clear();
		w.clear();
		
		
		string str="";
		loop(i,N){
			fin>>str;
			f.pb(str);
			str="";
		}
		
		loop(i,M){
			fin>>str;
			w.pb(str);
			str="";
		}
		
		
		int i=0;
		int j=0;
		int k=0;
		int c=0;
		
		for(i=0;i<w.sz;i++){
			for( j = 0 ; j < f.sz;j++){
				if(w[i].compare(f[j])==0)break;
			}
			if(j>=f.sz){
				f.pb(w[i]);
				c++;
				k=w[i].sz-1;
				for(k=w[i].sz-1; k >0 ;k--){
					if(w[i][k]=='/'){
						string tmp = w[i].substr(0,k);
						for( j = 0 ; j < f.sz;j++){
							if(tmp.compare(f[j])==0)break;
						}
						if(j>=f.sz){
							f.pb(tmp);
							c++;
						}
						else break;
					}
				}
			}
		}
		
		
		fout << "Case #"<<ncase<<": "<<c<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

