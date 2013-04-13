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
#include <limits.h>

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
typedef unsigned long long ull;
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
	fin.open ("B.in");
	fout.open ("T.out");
	int tcases;
	
	fin >> tcases;
	vs nums;
	string str;
	int n;
	loop4m2(ncase,1,tcases){
		nums.clear();
		fin >> n;
		loop(i,n){
			str="";
			fin >> str;
			nums.pb(str);
		}
		ull T;
		ull c=0;
		ull y=0;
		ull min_y = ULONG_LONG_MAX;
		ull y0=0;
		int i;
		while(true){ // T loop
			while(c++<T){ //c loop
				y0 = c*T - num[0];
				if (y0 < 0)continue;
				for(i = 1 ; i < nums.sz ;i++ ){
					y = c*T - nums[i];
					if(y != y0)break;
				}
				if ( i <nums.sz)continue;
				
				if(y < min_y)min_y = y;
				
			}
		}
		
		fout << "Case #"<<ncase <<": "<<y<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

