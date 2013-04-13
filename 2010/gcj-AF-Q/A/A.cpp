#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

ifstream fin;
ofstream fout;

int main (){
	fin.open ("A-large.in");
	fout.open ("test.out");
	int i , j, k,subb=0,fj=0,fk=0,res=0;
	int n,c,l,t;
	vector<int> num;
	fin >>n;
	for(i=1 ; i <= n ; i++){
		fin >>c;
		fin >>l;
		num.clear();
		for(j=0;j<l;j++){
			fin >>t;
			num.push_back(t);
		}
		subb=c;
		for(j=0;j<l;j++){
			for(k=j+1;k<l;k++){
				res = c-(num[j]+num[k]);
				if(res < subb && res >= 0){
					fj=	j+1;
					fk = k+1;
					subb = res;
				}
			}
		}
		fout << "Case #"<< i << ": "<< fj <<" "<< fk << endl;
	}
	 
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
