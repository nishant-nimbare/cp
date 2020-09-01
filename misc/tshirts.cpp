#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>
#include <string.h>
#include <map>

#define MOD 1000000007
#define MAX_SHIRTS 101
using namespace std;

int allSet;
long long int dp[1024][MAX_SHIRTS];

map<int,vector<int>> shirtList; 

vector<int> split(string input){
	string parsed;
	stringstream iss(input);

	vector<int> answers;

	while(getline(iss, parsed, ' ')){

		// cout<<"parsed "<<stoi(parsed)<<endl;
		answers.push_back(stoi(parsed));
	}

	return answers;
}


void mapShirts(string& input, int person){

	// cout<<"map shirt .."<<input<<"  "<<person<<endl;

	vector<int> shirts = split(input);

	for(int i=0;i<shirts.size();i++){
	
		map<int,vector<int>>::iterator it;

		it = shirtList.find(shirts[i]);

		if(it != shirtList.end()){
			//list is already there
			it->second.push_back(person);
		}else{
			vector<int> nPerson;
			nPerson.push_back(person);
			shirtList.insert({shirts[i],nPerson});
		}

	}
}

long long int recurse(int mask,int s){

	// cout<<"  |--recurse "<<mask<<" "<<s<<" : "<<"\t";

	if(mask == allSet) return 1; //all people have been assigned a shirt

	if(s > MAX_SHIRTS-1) return 0; // all shirts have been considered

	if(dp[mask][s] != -1) return dp[mask][s]; //return hashed value


	long long int ans = recurse(mask,s+1); //don't assign current cap to anyone

	map<int,vector<int>>::iterator itr;
	itr = shirtList.find(s);

	if( itr == shirtList.end() ) return dp[mask][s] = (ans%MOD);  // no person has this shirt

	vector<int>  peeps = itr->second;


	// cout<<endl<<"shirtList for "<<s<<" "<<peeps.size()<<endl;

	for(int i=0;i<peeps.size();i++){
		
		// cout<<"->"<<peeps[i]<<'\t';

		if( mask & ( 1<<(peeps[i]-1) ) ) continue;
		else{
			int newMask = ( mask | ( 1<<(peeps[i]-1) ));
			// cout<<endl<<"changing mask "<<mask<<"  to  "<< newMask <<endl;
		 	ans += ( recurse(newMask, s+1 ) %MOD); 
		}
	}


	// cout<<"  --recurse "<<mask<<" "<<s<<" : "<<(ans%MOD)<<"\t";

	dp[mask][s] = (ans%MOD);

	return (ans%MOD);

}


int main(int argc, char const *argv[])
{
	int t;
	string s;
	// std::fstream cin("./input.txt", std::ios_base::in);

	// cin>> t;
	getline(cin,s );

	t = stoi(s);
	// cout<<"test cases "<<t<<endl;
	while(t--){
		int n;
		// cin >> n;
		shirtList.clear();
		memset(dp, -1, sizeof dp); 
		
		getline(cin, s);
		n = stoi(s);

		for(int i=1;i<=n;i++){

			string line;
			getline(cin, line);
			// cin>>line;
			
			// cout<<"input "<<line<<endl;

            // cin>>line;

			mapShirts(line,i);

		} 
        allSet = (1<<n)-1;
		// allSet--;

		// cout<<"allSet "<<allSet<<"  MAX_SHIRTS "<<(MAX_SHIRTS-1)<<endl;

		// cout<<endl<<"answer "<<recurse(0,1)<<endl;
	
		cout<<recurse(0,1)<<endl;
		// cout<<endl<<"dp is "<<endl;
		// for(int j=0;j<=allSet;j++){
		// 	for(int i=0;i<MAX_SHIRTS;i++){
		// 		cout<<dp[j][i]<<"\t";
		// 	}
		// 	cout<<endl;
		// }
	}

	return 0;
}