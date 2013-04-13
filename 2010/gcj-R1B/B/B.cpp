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

int main (){
	
	fin.open ("B-large-practice.in");
	//fin.open ("B-small-attempt0.in");
	//fin.open ("B-small-attempt1.in");
	//fin.open ("B-small-attempt2.in");
		
	
	//fin.open ("B-large.in");
	
	fout.open ("B.out");
	
	int tcases;
	
	fin >> tcases;
	
	int N,K,B,T;
	vi X;
	vi V;
		
	loop4m2(ncase,1,tcases){
		fin >> N >> K >> B >> T ;
		X.clear();
		V.clear();
		
		int tmp;
		loop(i,N){
			fin >> tmp;
			X.pb(tmp);
		}
		
		loop(i,N){
			fin >> tmp;
			V.pb(tmp);
		}
		int win=0;
		int loos=0;
		int ans=0;
		
		for(int i=N-1;i>=0;i--){
			if(win >= K )break;
			if(X[i]+V[i]*T < B)
				loos++;
			else{
				win++;
				ans +=loos;
			}
		}
		if(win >= K)		
			fout << "Case #"<<ncase<<": "<<ans<<endl;
		else
			fout << "Case #"<<ncase<<": "<<"IMPOSSIBLE"<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

