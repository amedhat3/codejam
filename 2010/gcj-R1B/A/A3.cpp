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


vector < pair<string , int> > w;
vector < pair<string,int> > f;

int main (){
	
	fin.open ("A.in");
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
		cout <<"caseeeeeeeeeeeeee   "<<ncase<<endl;
		f.clear();
		w.clear();
		
		
		string str="";
		int lev = 0;
		loop(i,N){
			lev=0;
			fin>>str;
			string use="";
			int j=1;
			int par;
			for(j = 1 ;j < str.sz;j++){
				if(str[j]!='/')use += str[j];
				else{
					par =-1;
					if(lev != 0)par=f.sz-1;
					f.pb(mp(use,par));
					use ="";
					lev++;
				 }
			}
			par =-1;
			if(lev != 0)par=f.sz-1;
			f.pb(mp(use,par));
			str="";
		}
		
		loop(i,M){
			lev=0;
			fin>>str;
			string use="";
			int j=1;
			int par;
			for(j = 1 ;j < str.sz;j++){
				if(str[j]!='/')use += str[j];
				else{
					par =-1;
					if(lev != 0)par=w.sz-1;
					w.pb(mp(use,par));
					use ="";
					lev++;
				 }
			}
			par =-1;
			if(lev != 0)par=w.sz-1;
			w.pb(mp(use,par));
			str="";
		}
		
		
		int i=0;
		int j=0;
		int c=0;
		int k=0;
		
		for(i=0;i<w.sz;i++){
			for( j = 0 ; j < f.sz;j++){
				if((w[i].second==-1 || f[j].second==-1) && !(w[i].second==-1 && f[j].second==-1))continue;
				if(w[i].first.compare(f[j].first) == 0)
					if((w[i].second==-1 && f[j].second==-1) ||(  w[w[i].second].first.compare(f[f[j].second].first) == 0)){
						int x,y;
						x=w[i].second;
						y=f[j].second;
						while(!(x==-1 && y==-1)){
							if(x==-1 || y==-1)break;
							
							if(w[x].first.compare(f[y].first) != 0){
									break;
							}
							else{
								x=w[x].second;
								y=f[y].second;
							}
						}
						if(x==-1 && y==-1){
							break;
						}
					}
			}
			if(j>=f.sz){
				c++;
				if(w[i].second == -1){
					f.pb(w[i]);
				}
				
				else{			
					cout <<w[i].first <<endl;
					for(k=0 ; k < f.sz ; k++){
						if(w[w[i].second].first.compare(f[k].first)){
							int x=w[w[i].second].second;
							int y=f[k].second;
							
							while(!(x==-1 && y==-1)){
								if(x==-1 || y==-1)break;
							
								if(w[x].first.compare(f[y].first) != 0){
									break;
								}
								else{
									x=w[x].second;
									y=f[y].second;
								}
							}
							if(x==-1 && y==-1){
								f.pb(mp(w[i].first,k));
							}
						}
					}
				}
				cout <<i<<"  "<<f.sz-1<<" --> "<<f[f.sz-1].first << "  " <<f[f.sz-1].second<<endl;
			}
		}
		
		
		fout << "Case #"<<ncase<<": "<<c<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

