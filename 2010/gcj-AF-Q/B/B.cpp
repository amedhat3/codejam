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
	fin.open ("B-large.in");
	fout.open ("testB.out");
	
	int n;
	vector<string> all;
	string str="",str2="";
	fin >> n;
	getline( fin, str );
	for(int ncase = 1 ; ncase <= n ; ncase++){
		str = "";
		str2 = "";
		all.clear();
		
		getline( fin, str );
		for(int i = 0 ; i < str.length();i++){
			if((str[ i ] >= 'a' && str[ i ] <= 'z')||(str[ i ] >= 'A' && str[ i ] <= 'Z')){
				str2 += str[i];
			}
			else{
				all.push_back(str2);
				str2="";
			}
		}
		all.push_back(str2);
				
		fout << "Case #"<< ncase << ": ";
		for(int i =all.size()-1 ; i > 0;i -- ){
			fout <<all[i]<<" "; 
		}
		fout <<all[0]<<endl;
	}
	
	fin.close();
	fout.flush();
	fout.close();
	
	return 0;
}
