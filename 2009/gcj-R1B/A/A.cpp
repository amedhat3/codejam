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
vs lines;
string lstr;
vector< pair<string,vs> > ad;
int L;
int A;
double p = 1.0;
int pos=0;
void readtree(int an){
	
	while(lstr[pos] == ' '){
		pos++;
	}
	
	pos++;//(
	
	double weight=0.0;
	string str="";
	while(lstr[pos] == ' '){
		pos++;
	}
	while(lstr[pos] != ' '){
		str +=lstr[pos++];
	}
	weight = atof(str.c_str());
	
	p *= weight;
	//cout<< weight<<endl;
	
	while(lstr[pos] == ' '){
		pos++;
	}
	str="";
	while(lstr[pos] != ' '){
		str +=lstr[pos++];
	}
	if (hasad(str,an)){
		readTree(an);
		readTree(an);
	}
	else{
		escaptree();
		escaptree();
	}
	
	
	
	readTree();
}

void solve(){
readtree();
}

int main (){
	fin.open ("A.in");
	fout.open ("A.out");
	
	int tcases;
	string tstr;
	float tf=0.0;
	//int tn=0;

	fin >> tcases;
	
	loop4t(ncase,1,tcases){
		p = 1.0;
		
		fin >> L;
		getline(fin,tstr);
		
		lines.clear();
		lstr="";
		loop(line,L){
			getline(fin,tstr);
			lines.pb(tstr);
			lstr +=tstr;
		}
		
		
		fin >> A;
		
		ad.clear();
		loop(i,A){
			tstr="";
			int n=0;
			
			fin >> tstr >> n;
			vs desc;
			desc.clear();
			string str1="";
			loop(j,n){
				fin >> str1 ;
				desc.pb(str1);
			}
			
			ad.pb(mp(tstr,desc));
			
			/*cout << ad[i].first <<"  ";
			loop(j,n){
				cout << ad[i].second[j]  <<"  ";
			}
			cout<<endl;*/
		}
		
		pos=0;
		
		fout << "Case #"<<ncase <<":"<<endl;
		loop(i,A){
			readtree(i);
		}
		
		//fout <<lstr<<endl;
		
		
		tf = 0.5;
		//fout.precision(7);
		fout.width(9);
		fout.fill('0');
		fout <<left<<tf<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
