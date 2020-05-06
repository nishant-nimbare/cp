#include <bits/stdc++.h>

using namespace std;


unordered_set<int> primes;


int reduce(int num){

	for(int i=2; i<= sqrt(num); i++){
		if(num%i == 0){
			return num/i;
		}	
	}

	// if the num is prime 
	// cout<<" inserting in prime "<<num<<'\n';
	primes.insert(num);
	return num;

}


bool isPrime(int num){
	
	if(primes.find(num) != primes.end()){
		return true;
	}

	if(num == reduce(num)){
		primes.insert(num);
		return true;
	}

	return false;
}


int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
	// std::fstream myfile("./input.txt", std::ios_base::in);

	primes.insert(1);
	primes.insert(2);

	int t;
	cin>> t;	

	while(t--){
		int n;
		cin >> n;

		map< int,vector<int> > days;

		for(int p=1;p<=n;p++){
			//iterate over every page

			int d=0,temp=p;
			while(!isPrime(temp)){
				temp=reduce(temp);
				d++;
			}

			if( days.find(d) == days.end() ){
				// day not initialized
				vector<int> new_vec {p};
				days.insert({d,new_vec});				
			}else{
				days[d].push_back(p);
			}

		}

		// Printing answers
		cout<<days.size()<<'\n';
		for(auto day:days){

			//CHANGE THIS LATER 
			cout<<day.second.size()<<' ';
			// cout<<day.first<<' ';
			
			for(auto p : day.second){
				cout<<p<<' ';
			}
			cout<<'\n';
		}

	}

	return 0;
}