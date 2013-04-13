/**
 * @Author :Ahmed M. Osman
 * @CodeJame userName : AMedOs
 * @Email :a.medhat.cs@gmail.com
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

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define loop(i,m) for(unsigned int i=0;i<m;i++)
#define loop2(i,m) for(i=0;i<m;i++)
#define loop4(i,x,m) for(unsigned int i=x;i<m;i++)
#define loop4t(i,x,m) for(unsigned int i=x;i<=m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair

typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;


ifstream fin;
ofstream fout;

int best[11][1000];
int countt;
/*
string d_to_base(long n, int tbase){
	
	ss strs;
	strs << n;
	string nstr = strs.str();
	if(tbase == 10)return nstr;
	
	long n2 =n;
	string res="";
	
	while (n2 > 0){
		ss strs;
		cout<<n2<<endl;
		cout<<res<<endl;
		strs << n2 % tbase; 
		res += strs.str();
		n2 /= tbase;
	}
	cout << n <<"  "<<tbase <<"  "<< res<<endl;
	return res;
}
*/
/*long base_to_d(string n, int fbase){
	return 1;
}
string c_base(long n,int fbase,int tbase){
	ss strs;
	strs << n;
	string nstr = strs.str();
	
	if(fbase == tbase) return nstr;
	
	if (fbase == 10){
		return d_to_base(n,tbase);
	}
	
	if(tbase == 10){
		ss strs2;
		strs2 << base_to_d(nstr,fbase);
 		return strs2.str();
	}
	return d_to_base(base_to_d(nstr,fbase),tbase);
}*/
/*
bool ishappy3(long n,int base){
	int res = 0;
	int tmp;
	ss strs;
	strs<<n;
	string str = strs.str();
	loop(i,str.sz){
		tmp=atoi(str.substr(i,1).c_str());
		res+=tmp*tmp;
	}
	cout <<"happy 3 "<<res<<endl;
	if(res==1)
		return true;
	else {
		return false;
	}
}

bool ishappy2(long n,int base){
	int res = 0;
	int tmp;
	ss strs;
	strs<<n;
	string str = strs.str();
	loop(i,str.sz){
		tmp=atoi(str.substr(i,1).c_str());
		res+=tmp*tmp;
	}
	cout <<"happy 2 "<<res<<endl;
	if(res==1)
		return true;
	else {
		return ishappy3(atoi(d_to_base(res,base).c_str()),base);
	}
}
*/
bool ishappy(long n,int base){
	
	if(n < 1000){
		if(best[base][n] == -2 ){
			best[base][n] = 0;
			return false;
		}
		if(best[base][n] != -1 )return best[base][n];
	}
	
	int res = 0;
	long n2=n;
	while(n > 0){
		long rem = n%base;
		res += rem * rem;
		n/=base;
	}
	
	if (res == 1){
		if(n2 < 1000)best[base][n2] = 1;
		return true;
	}
	else {
		if(n2 < 1000)best[base][n2] = -2;
		bool ret = ishappy(res,base);
		if(ret){
			if(n2 < 1000)best[base][n2] = 1;
			return true;
		}
		else{
			if(n2 < 1000)best[base][n2] = 0;
			return false;
		}
	}
}

int main (){
	fin.open ("A-large-practice.in");
	fout.open ("test.out");
	
	unsigned int cases;
	vi bases;
	string str;
	
	fin >> cases;
	
	getline(fin,str);
	
	loop4t(ncase,1,cases){
		getline(fin,str);
		
		bases.clear();
		
		ss strs(str);
		int mm;
		while (strs >> mm){
			bases.pb(mm);
		}
		
		//mem(best,-1);
		loop(i,11){
			loop(j,1000)
				j==1?best[i][j]=1:best[i][j]=-1;
		}
		
		long n;
		for(n=2 ;; n++){
				
				unsigned int i;
				loop2(i,bases.sz){
					countt = 0;
					//cout << best[2][2] <<endl;
					//if(n==1038217)cout << n << "  "<<bases[i]<<endl;
					if(!ishappy(n,bases[i]))break;
				}
				if(i >= bases.sz)break;
		}
		fout << "Case #"<<ncase <<": "<<n<<endl;
	}
		 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
