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

int b[10000];
void init(){
	int i=0;
	b[0]=0;
	b[1]=1;
	b[2]=2;
	b[3]=2;
	for(i=4;i<10000;i++)b[i]=b[i/2]+1;
}

int main (){
	
	fin.open ("B-large.in");
	//fin.open ("B-small-attempt0.in");
	//fin.open ("B-small-attempt1.in");
	//fin.open ("B-small-attempt2.in");
		
	
	//fin.open ("B-large.in");
	
	fout.open ("B.out");
	
	init();
	
	int tcases;
	
	fin >> tcases;
	ll L,P,C;
	
	loop4m2(ncase,1,tcases){
		fin >> L >> P >> C;
	
		ll count=0;
	
		for(ll i = L*C ; i <P ; i*=C){
			count++;
		}
		fout << "Case #"<<ncase<<": "<<b[count]<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

