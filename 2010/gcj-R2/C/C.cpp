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
//#define sz(x)  (int)x.size()

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

bool grid[1001][1001];

int main (){
	
	//fin.open ("C.in");
	fin.open ("C-small-attempt0.in");
	//fin.open ("C-small-attempt1.in");
	//fin.open ("C-small-attempt2.in");
		
	
	//fin.open ("C-large.in");
	
	fout.open ("C.out");
	
	int tcases;
	
	fin >> tcases;
	int r,x1,x2,y1,y2;
	int maxx=0,maxy = 0;
	loop4m2(ncase,1,tcases){
		memset(grid,0,sizeof(bool)*1001*1001);
		
		fin >> r ;
		while(r--){
			fin >> y1 >> x1 >> y2 >> x2;
			
			maxx = max(maxx, max(x1,x2));
			maxy = max(maxy, max(y1,y2));
			
			loop4m2(i,x1-1,x2-1){
				loop4m2(j,y1-1,y2-1){
					grid[i][j] = 1;					
				}
			}
			
		}
		
		maxx++;
		maxy++; 
		bool g[maxx][maxy];
		loop(i,maxx){
			loop(j,maxy){
				g[i][j] = grid[i][j];
			}
		}
		/*loop(i,maxx){
				loop(j,maxy){
					cout <<g[i][j]<<" ";
				}
				cout <<endl;
		}*/
		ui countt =0;
		
		while(true){
			countt++;
			bool g2[maxx][maxy];
			
			memcpy(g2,g,sizeof(g2));
			
			/*loop(i,maxx){
				loop(j,maxy){
					cout << g2[i][j]<<"  ";
				}
				cout<<endl;
			}
			cout<<endl;
			*/
			int c=0;
			loop(i,maxx){
				loop(j,maxy){
					
					if(g2[i][j]==0)c++;
					int s=0;
					if(i-1 >= 0)s+=g2[i-1][j];
					if(j-1 >= 0)s+=g2[i][j-1];
					
					if(s<1)g[i][j]=0;
					
					if((s==2) && (g2[i][j]==0) )g[i][j] = 1;
				}
			}
			if(c >= maxx*maxy)break;
		}
		
		
		fout << "Case #"<<ncase<<": "<<countt-1<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

