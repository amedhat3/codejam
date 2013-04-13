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
#include <queue>

using namespace std;

#define pb push_back
#define pf pop_front
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
	//fin.open ("C-small-attempt0.in");
	fin.open ("C.in");
	fout.open ("C-small.out");
	int tcases;
	fin >> tcases;
	ll r,k,n;
	queue<int> q;
	queue<int> q2;
	int s;
	vector< queue<int> > vq;
	loop4m2(ncase,1,tcases){
		fin >> r >> k >> n;
		
		while(q.size())q.pop();
		loop(i,n){
			fin >> s;
			q.push(s);
		}
		
		
		vq.clear();
		
		int tmp;
		int k2;
		int c =0;
		while(r-- > 0){
			k2 = k;
			while(q2.size())q2.pop();
			while(k2 > 0 && q.size()){
				if(k2-q.front() >= 0){
					tmp = q.front();
					q.pop();
					k2 -= tmp;
					q2.push(tmp);
					c+=tmp;
				}
				else{
					break;
				}
			}
			while(q2.size()){
				q.push(q2.front());
				q2.pop();
			}
		}
		
		fout << "Case #"<<ncase <<": "<<c<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}

