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
int A1,A2,B1,B2,A,B;

vvi best(1000000,vi(1000000,-1));

bool winn(int a,int b){
	if(best[a][b]!=-1) return best[a][b];
	if(b[b][a] != -1 )return best[b][a];
	
	
	int i=1;
	int j = 1;
	
	if(a>b){
		while((a-(i*b))>0){
			if(!winn(a-(i*b),b)){
				best[a-(i*b)][b] =true;
				return true;
			}
			i++;
		}
		i--;
		if(i==0)return false;
		else return !winn(a-(i*b),b);
	}
	else if (b > a){
		j=1;
		while((b-(j*a))>0){
			if(!winn(a,b-(j*a)))return true;
			j++;
		}
		j--;
		
		if(j==0)return false;
		else return !winn(a,b-(j*a));
	}
	else{
		return false;
	}
}

int main (){
	
	fin.open ("C-small-practice.in");
	//fin.open ("C-small-attempt0.in");
	//fin.open ("C-small-attempt1.in");
	//fin.open ("C-small-attempt2.in");
		
	
	//fin.open ("C-large.in");
	
	fout.open ("C.out");
	
	int tcases;
	
	fin >> tcases;
	

		
	loop4m2(ncase,1,tcases){
		cout << "case #"<<ncase<<endl;
		fin >> A1 >> A2 >> B1 >> B2;
		int c=0;
		for(A=A1;A<=A2;A++){
			for(B=B1;B<=B2;B++){
				if(winn(A,B))c++;
			}
		}
		
		fout << "Case #"<<ncase<<": "<<c<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

