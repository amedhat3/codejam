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
int M,N;

//vector< pair <string,string> > hexatabel;

string bin[16];
vs grid;

void init(){
	bin[0]="0000";
	bin[1]="0001";
	bin[2]="0010";
	bin[3]="0011";
	bin[4]="0100";
	bin[5]="0101";
	bin[6]="0110";
	bin[7]="0111";
	bin[8]="1000";
	bin[9]="1001";
	bin[10]="1010";
	bin[11]="1011";
	bin[12]="1100";
	bin[13]="1101";
	bin[14]="1110";
	bin[15]="1111";
}

bool ifva(int x, int y){
	if(x>=0 &&x < N && y>=0 && y < M )return true;
	return false;
}

bool check(int x,int y,int w){
	int di[4]={-1,1,0,0};
	int dj[4]={0,0,1,-1};
	
	for(int wx=x+1 ; wx <= w+x ; wx++)
	for(int wy=y+1 ; wy <= w+y ; wy++)
	for(int i = 0 ; i < 4 ; i++){
		if(ifva(wx+di[i],wy+dj[i])){
			if(grid[wx][wy] == grid[wx+di[i]][wy+dj[i]])return false;
		}
	}
	
	return true;
}

int main (){
	
	fin.open ("C.in");
	//fin.open ("C-small-attempt0.in");
	//fin.open ("C-small-attempt1.in");
	//fin.open ("C-small-attempt2.in");
		
	
	//fin.open ("C-large.in");
	
	fout.open ("C.out");
	
	int tcases;
	init();
	fin >> tcases;

	ss sstr;
	loop4m2(ncase,1,tcases){
		cout << "newwwwwwww"<<endl;
		fin >> M >> N;
		grid.clear();
		
		string str ="";
		loop(i,M){
			fin >> str;
			string all="";
			loop(j,str.sz){
				if(str[j]<='9')
					all+= bin[str[j]-'0'];
				else
					all+= bin[str[j]-'A'+10];
			}
			grid.pb(all);
			cout <<all<<endl;
		}
		
		int x = 0 ;
		int y = 0 ;
		int w = 1;
		vi ww;
		ww.clear();
		for(y= 0 ; y < M; y++){
			for(x =0 ; x  < N ; x++){
				w=1;
				while(check(x,y,w)){
					w++;
				}
				w--;
				if(w!=0){
					x+=w;
					y+=y;
				}
				else{
					ww.pb(w);
				}
			}
		}
		
		sort(all(ww));
		int count =0;
		vector< pair<int,int> > al;
		for(int i == ww.sz-1;i>0;i-- ){
			al.pb(mp(ww[i],0))
			for(int j == i-1;j>=0;j-- ){
				if(ww[i]==ww[j])al[al.sz-1].second++;
			}
			fout << "Case #"<<ncase<<": "<<endl;
		}
		
		
		
		
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

