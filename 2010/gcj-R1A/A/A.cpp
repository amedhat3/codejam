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

bool solve(char ch){
	int x,y;
	loop(i,n){
		loop(j,n){
			if(game[i][j]==ch){
				if(n-j-k >= 0){
					
					for(x=1;x < k ; x++){
						if(game[i][j+x]!=ch){
							break;
						}
					}
					if(x >= k) return true;
				}
				if(n-i-k >= 0){
					for(y=1;y < k ; y++){
						if(game[i+y][j] != ch){
							break;
						}
					}
					if(y >= k) return true;
				}
				
				for(x=1;x < k;x++){
					if(i+x >= n || j+x >=n)break;
					if(game[i+x][j+x] != ch){
						break;
					}
				}
				if(x >= k) return true;
				
				
				for(x=1;x < k;x++){
					if(i-x < 0 || j+x >= n)break;
					if(game[i-x][j+x] != ch){
						break;
					}
				}
				if(x >= k) return true;
				
				
			}
		}
	}
	
	return false;
}


int main (){
	
	fin.open ("A-large-practice.in");
	//fin.open ("A-small-attempt0.in");
	//fin.open ("A-small-attempt1.in");
	//fin.open ("A-small-attempt2.in");
		
	
	//fin.open ("A-large.in");
	
	fout.open ("A.out");
	
	int tcases;
	
	fin >> tcases;
	

	
	string str="";

	
	
		
	loop4m2(ncase,1,tcases){
		game.clear();
		
		fin >> n >> k;
		loop(i,n){
			fin >> str;
			game.pb(str);
			str="";
		}
		
		int x;
		loop(i,n){
			
			for(int j = n-2 ; j >=0; j--){
				if(game[i][j]!='.' && game[i][j+1]=='.'){
					x=j;
					while(x+1 < n && game[i][x+1]=='.'){
					
						
						game[i][x+1]=game[i][x];
						game[i][x] = '.';
					
						x++;
					}
					
				}				
			}
		}
		
		string strr;
		bool boo = solve('B');
		bool ree = solve('R');
		
		if(boo && ree)strr="Both";
		else if(boo)strr="Blue";
		else if (ree)strr="Red";
		else strr = "Neither";
		
		
		fout << "Case #"<<ncase<<": "<<strr<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

