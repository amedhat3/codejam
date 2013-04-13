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
typedef vector<ll> vll;


ifstream fin;
ofstream fout;
int P,C;
vll s;
ll tmp;
vi maxc;

void getmaxC(){
	int k;
	loop(i,P){
		loop(j,C){
			if(s[i]>maxc[j]){
				for(k =C-1 ; k > j ; k--){
					maxc[k]=maxc[k-1];
				}
				maxc[j] = s[i];
				break;
			}
		}
	}
}

bool removeC(){
	sort(all(s));
	int i ,j;
	for (i = sz(s)-1,j=0; j <C ; i--,j++ ){
		if(s[i]>=1 ){
			 s[i]-=1 ;
		}
		else{
			return false;
		}
	}
	return true;
}


int main (){
	fin.open ("C-large.in");
	fout.open ("C.out");
	
	int tcases;
	string tstr;	
	
	fin >> tcases;
		
	loop4t(ncase,1,tcases){
		
		fin >> P >> C;
		
		s.clear();
		loop(i,P){
			fin >> tmp;
			s.pb(tmp);
		}
		
		maxc.resize(C);
		loop(i,C)maxc[i]=0;
		getmaxC();
		ll i=0;
		while(removeC()){
			//cout << i <<endl;
			i++;
			getmaxC();
		}
	
		fout << "Case #"<<ncase <<": "<<i<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
