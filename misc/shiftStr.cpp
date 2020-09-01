#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

// input
// 5
// ccadd
// bddcc

int bruteForce(string a,string b,int n){

	int maxCommon=0,swaps=0;

	for(int offset=0;offset<n;offset++){

		int curCommon=0;

		for(int k=0;k<n;k++){

			cout<<"comparing  "<<b.at( (offset+k)%n )<<" "<<a.at(k)<<"	,	";


			if(b.at( (offset+k)%n ) == a.at(k) ){
				curCommon++;
			}else{
				break;
			}
		
		}

		cout<< offset <<"  "<<curCommon <<endl;

		if(curCommon > maxCommon){
			maxCommon=curCommon;
			swaps = offset;
		}

	}

	return swaps;

}


int main(int argc, char const *argv[])
{
	std::fstream myfile("./input.txt", std::ios_base::in);

	int n;
	myfile >> n;

	string a,b;
	myfile>>a>>b;

	int ans = bruteForce(a,b,n);

	cout<<ans<<endl;
	
	return 0;
}