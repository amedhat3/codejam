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


int main (){
	fin.open ("B-large.in");
	fout.open ("B.out");
	
	int tcases;
	string tstr;
		
	int N,T,E;
	vi emp,pas;
	
	vi tw,sumtw,res;
	vvi cars;
	fin >> tcases;
	
	loop4t(ncase,1,tcases){
		
		fin >> N >> T ;
		fin >> E;
		int temp1 ,  temp2;
		emp.clear();
		pas.clear();
		
		tw.clear();
		tw.resize(N);
		
		sumtw.clear();
		sumtw.resize(N);
		
		res.clear();
		res.resize(N);
		
		cars.clear();
		cars.resize(N);
		
		loop(i,N){
			tw[i]=0;
			sumtw[i]=0;
			res[i]=0;
		}
		
		loop(i,E){
			fin >> temp1 >> temp2;
			emp.pb(temp1);
			cars[temp1-1].pb(temp2);
			
			tw[temp1-1] += 1;
			
			//if(temp2 > maxtw[temp1-1] ) maxtw[temp1-1] = temp2;
			
			sumtw[temp1-1] += temp2;
		}
		
		
		int i;
		loop2(i,N){
			
			if(T-1 != i){
				if(sumtw[i] < tw[i]){
					break;
				}
			}
			else{
				continue;
			}
			
			int num=0;
			int rem=tw[i];
			
			sort(all(cars[i]));
			
			if(sz(cars[i])>0){
				
				for(int j = sz(cars[i])-1 ; j>=0 ; j--){
					if(cars[i][j] >= rem){
						num++;
						break;
					}
					else{
						num++;
						rem -= cars[i][j];
					}
				}
			}
			res[i]=num;
		}
		if (i<N){
			fout << "Case #"<<ncase <<": "<<"IMPOSSIBLE"<<endl;
		}
		else {		
			fout << "Case #"<<ncase <<": ";
			fout << res[0];
			loop4(i,1,N){
				fout << " " <<res[i];
			}
			fout <<endl;
		}
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
