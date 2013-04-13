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

vs game;
int n,k;

int main (){
	
	//fin.open ("A.in");
	//fin.open ("A-small-attempt2.in");
	//fin.open ("A-small-attempt1.in");
	//fin.open ("A-small-attempt2.in");
		
	
	fin.open ("A-large-practice.in");
	
	fout.open ("A.out");
	
	int tcases;
	
	fin >> tcases;
	int n;
	vector< pair<int,int> > line;
	loop4m2(ncase,1,tcases){
		fin >> n;
		int tmp1 , tmp2;
		line.clear();
		loop(i,n){
			fin >> tmp1 >> tmp2 ;
			line.pb(mp(tmp1,tmp2)); 
		}
		
		ll c=0;
		for(int i=0;i<n-1;i++){
			for(int j= i+1;j<n;j++){
				
				if((line[i].first < line[j].first && line[i].second > line[j].second)||(line[i].first > line[j].first && line[i].second < line[j].second)){
					c++;
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

