/**
 * @Author :Ahmed M. Osman
 * @CodeJame userName : AMedOs
 * @Email :a.medhat.cs@gmail.com
 * @Email:ahmed.osman@alex-sci.edu.eg
 * */
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz(X)  ((int)(X.size())) 
#define loop(i,m) for(int i=0;i<m;i++)
#define loop2(i,m) for(i=0;i<m;i++)
#define loop4(i,x,m) for(int i=x;i<m;i++)
#define loop4t(i,x,m) for(int i=x;i<=m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
const double pi=acos(-1.0);
const double eps=1e-11;

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef long long ll;


ifstream fin;
ofstream fout;

int main (){
	fin.open ("A-large.in");
	fout.open ("A.out");
	
	int tcases;
	string tstr;
	
	int G;
	vector<ll> c;
	
	c.clear();
	fin >> tcases;
	
	loop4t(ncase,1,tcases){
		fin >> G;
		c.clear();
		ll tn=0;
		loop(i,G){
				fin >> tn ;
				c.pb(tn);
		}
		bool found=false;
		loop(i,G){
			found=false;
			loop(j,G){
				if(i != j ){
					if(c[i] == c[j]){found =true;break;}
				}
			}
			if(found==false){
				fout << "Case #"<<ncase <<": "<<c[i]<<endl;
				break;
			}
		}
	
		
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
