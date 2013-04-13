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
	fin.open ("C-large.in");
	fout.open ("testC.out");
	
	int n,i,j,k,m,lastnum;
	string str;
	
	vector<string> num ;
	
	num.clear();
	num.resize(10);
	
	
	num[1]="";
	num[2]="abc";
	num[3]="def";
	num[4]="ghi";
	num[5]="jkl";
	num[6]="mno";
	num[7]="pqrs";
	num[8]="tuv";
	num[9]="wxyz";
	num[0]=" ";
	
	
	fin >> n;
	getline(fin,str);
	for(int ncase = 1 ; ncase <= n ;ncase++){
		getline(fin,str);
		
		fout << "Case #"<< ncase << ": ";
		for(i=0;i<str.length();i++){
			for(j=0;j<num.size();j++){
				for(k=0;k<num[j].length();k++){
					if(str[i] == num[j][k]){
		
						if(lastnum == j)fout<<" ";
						for(m=0;m<=k;m++){
							lastnum=j;
							fout<<j;
						}
					}
				}
			}
		}
		fout << endl;
	}
	
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
