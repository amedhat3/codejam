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
//#define sz(x)  (int)x.size()

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

bool cmp(pair<int,int> x ,pair<int,int> y ){
	
	if(y.second < x.second)return true;
	return false;

}

int main (){
	
	fin.open ("B.in");
	//fin.open ("B-small-attempt0.in");
	//fin.open ("B-small-attempt1.in");
	//fin.open ("B-small-attempt2.in");
	
	
	//fin.open ("B-large.in");
	
	fout.open ("B.out");
	
	int tcases;
	
	fin >> tcases;
	

		int p;
		vector < pair<int,int> > m;
	loop4m2(ncase,1,tcases){
		m.clear();
		
		fin >> p;
		int x=0;
		loop(i,1<<p){
			fin >> x;
			m.pb(mp(i,p-x));
		}
		
		sort(all(m),cmp);
		/*loop(i,m.sz){
			cout <<m[i].first << "  " << m[i].second << endl;
		}*/
		vvi all;
		vector < vector <bool> > used;
		loop(i,p){
			vi tmp;
			vector <bool> tmpb;
			int yy=0;
			
			loop(j,(1<<(p-i-1))){
				fin >> yy;
				tmp.pb(yy);
				tmpb.pb(0);
			}
			used.pb(tmpb);
			all.pb(tmp);
		}
		
		int cost=0;
		
		loop(i,1<<p){
			loop(j,m[i].second){
				cout <<all[j].sz<<endl;
				loop(k,all[j].sz){
					
					cout << m[i].first <<" betw " << (1<<(k+1))-(1<<(j+1)) <<" and "<< (1<<(k+1))-(1<<(j+1))+(1<<(j+1))-1 <<" for j = "<<j<<" and k = "<< k <<endl;
					
					if(m[i].first >= (1<<(k+1))+(1<<(j+1)) && m[i].first <= (1<<(k+1))+(1<<(j+1))+(1<<(j+1))-1 && used[j][k]==0){
						//cout << m[i].first <<" betw " << k*(j+1) <<" and "<< (k*(j+1))+(j+1) <<endl;
						cost +=  all[j][k];
						used[j][k]=1;
						cout <<"yemken"<<endl;
						break;
					}
				}
				cout <<endl;
			}
		}
		
		
		fout << "Case #"<<ncase<<": "<<cost<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

