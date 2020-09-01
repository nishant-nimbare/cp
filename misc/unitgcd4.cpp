#include <bits/stdc++.h>
using namespace std;

const int sieveSize = 1000000;
bitset<sieveSize> sieve;
unordered_set<int> primes;


void initialize(){
	sieve.set(); //set all bits

	primes.insert(1);

	for(int i=2;i*i<=sieveSize;i++){

		if(sieve[i]==1){
			// i is prime
			primes.insert(i);

			for(int k=i*i; k<=sieveSize; k+=i){
				sieve[k]=0;
			}
		}
	}

	// adding the remaining primes 
	for(int t=sqrt(sieveSize); t<sieveSize; t++) 
		if(sieve[t]==1) primes.insert(t);
}

bool isPrime(int num){

	if( primes.find(num) != primes.end() ){
		return true;
	}

	// if(num>sieveSize){
	// 	// check with sqrt method
	// }

	return false;
}

int main(int argc, char const *argv[]){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	initialize();

	int t;
	cin>> t;
	
	while(t--){
		int n;
		cin >> n;

		vector< vector<int> > days;

		days.push_back(vector<int> {1});		

		// for(auto i:primes) cout<<i<<' ';
		// cout<<'\n';

		for(int i=2; i<=n; i++){

			if(isPrime(i)){
				days[0].push_back(i);
				continue;
			}

			// check even odd

			if( i&1 ){ // odd
				
				if(i==n){ //last number? add in the previous day
					days[days.size() - 1 ].push_back(i);
				}else{
					days.push_back(vector<int> {i,i+1});
					i+=1;
				}

			}else{ // even
				days.push_back(vector<int>{i});
			}

		}

		cout<<days.size()<<'\n';
		for(auto v : days){
			cout<<v.size();
			for(auto p : v) cout<<' '<<p;
			cout<<'\n';
		}


	}

	return 0;
}