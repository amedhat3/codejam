/**
 * @Author :Ahmed M. Osman
 * @CodeJame userName : AMedOs
 * @TopCoder Handel : AMedOs
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
	//fin.open ("A-small-attempt0.in");
	//fin.open ("A-small-attempt1.in");
	//fin.open ("A-small-attempt2.in");
	fin.open ("A-large.in");
	//fin.open ("A.in");
	fout.open ("A.out");
	
	int tcases;
	ll n,k;
	
	fin >> tcases;
	

		
	loop4m2(ncase,1,tcases){
		string str ="OFF";
		fin >> n >> k ;
		int tot = pow(2,n)-1;
		
		str ="OFF";
		int x = 1;
		while(k >= ((tot*x)+(x-1))){
			if(k == ((tot*x)+(x-1))){
				str ="ON";
			}
			x++;
		}
		
		fout << "Case #"<<ncase<<": "<<str<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

